# redis

## guidance

purpose: master the principle of redis and some design concepts
need: outline, structure, composition, function, no details now
time: 4days
note: memorize, summary, review, question, core, practice.

## outline

数据结构和对象，单机数据库的实现，多级数据库的实现，独立功能的实现

## 数据结构和对象

五种对象类型：字符串，集合，列表，哈希，有序集合
八种底层数据结构：long, sds(raw), embstr, linkedlist, ziplist, skiplist, hashtable, intset
对象的五种基本属性：type,encoding,ptr,refcount,lru。
每种对象类型底层至少能使用两种不同的数据结构实现，提供灵活高效的选择。

REDIS_STING: REDIS_ENCODIND_INT, REDIS_ENCODING_EMBSTR, REDIS_ENCODING_RAW
REDIS_LIST: REDIS_ENCODING_LINKEDLIST, REDIS_ENCODING_ZIPLIST
REDIS_HASE: REDIS_ENCODING_HT, REDIS_ENCODING_ZIPLIST
REDIS_SET: REDIS_ENCODING_HT, REDIS_ENCODING_INSET
REDIS_ZSET: REDIS_ENCODING_ZIPLIST, REDIS_ENCODING_SKIPLIST

为什么整数集合只升级不降级？

为什么Redis不共享包含字符串的对象？

## 数据库

实现原理（crud），持久化，事件，客户端，服务端

redis是键值对数据库，每个键都是一个字符串对象，每个值都是五种对象之一。

1.键空间操作：基本操作和维护操作：命中记录，最后使用时间，脏记录，脏计数，**通知**。

2.生存时间：expires字典（过期字典）保存所有键的过期时间。键是指针，值是long long整数。

3.过期删除策略：定时删除，惰性删除，定期删除。**redis采用惰性删除和定期删除结合的方式。** `expireIfNeeded` `activeExpireCycle` **定期删除应控制好执行的频率和时长。**

## RDB持久化

1.服务器在载入RDB文件期间，会一直处于阻塞状态，知道载入工作完成为止。保存RDB文件可以采用`SAVE()`或`BGSAVE()`前者会阻塞服务器进程，后者通过子进程执行。

2.redis允许用户通过设置save选项，让服务器每个一段时间自动执行一次BGSAVE命令。`save 900 1`, `save 300 10` `save 60 10000`默认900秒1次修改，300秒10次修改，60秒10000次修改则自动保存。`saveparams`数组。

3.dirty计数器：距离上一次保存后数据库进行多少次修改；
lastsave熟悉：记录上一次保存的时间
redis的周期性操作函数serverCron默认每100毫秒执行一次，用于对正在运行的服务器进行维护，包括检查是否满足保存条件。

4.RDB结构：REDIS字符标志，db_version, databases, EOF, check_sum
  databases结构：SELECTDB， db_number, key_value_pairs
  键值对结构：EXPIRETIME_MS标志, ms, TYPE, key, value

5.自带RDB文件检查工具：redis-check-dump。

## AOF持久化（append only file）

1.AOF持久化是通过保存Redis服务器执行的写命令来记录数据库状态。被写入AOF文件的所有命令都是以Redis的命令请求协议格式保存的，因为redis的命令请求协议是纯文本文件，所以可以直接打开查看。

2.将写命令以协议格式追加到aof_buf缓冲区末尾。在服务器每次结束一个事件循环之前，调用flushAppendOnlyFile函数考虑是否将aof_buf缓冲区的内容写入AOF文件。
`appendsync:always, everysec, no`设置同步。

> 文件写入和同步：为了提高文件的写入效率，现代操作系统中，当用户调用ｗrite函数将数据写入文件时，操作系统会将写入数据暂时保存在内存缓冲区里，等缓冲区填满或超时再将缓冲区数据写入磁盘。可能出现安全问题，系统停机会导致缓冲区数据丢失。当然系统会提供接口函数实现强制刷新。
> always模式每次写入都同步，效率最慢，但安全，只会丢失一次事件数据。everysec为默认模式，足够快，而且停机只会丢失一秒的数据。

3.redis命令执行只能在客户端上下文中执行，所以还原时创建一个伪客户端一次执行写命令。

4.AOF文件体积会随事件膨胀，为了解决问价膨胀问题，redis提供AOF文件重写功能。
原理：无需对现有的AOF文件进行分析，而是**直接从数据库读取键的现有值，再用一条命令去记录键值对即可**，替代之前的多条命令。当然当集合或者列表元素过多时，将使用多条命令记录键值对。`REDIS_AOF_REWRITE_ITEMS_PER_CMD = 64`

5.redis将AOF重写程序放到**子进程**执行，使用子进程而不是线程，子进程带有数据副本，可以避免使用锁的情况，保证数据安全。

6.为了保证数据一致，在执行重写子进程期间，写命令会同时追加到AOF缓冲区和AOF重写缓冲区。**重写执行完成后，将AOF重写缓冲区写到新的AOF文件并重命名覆盖原来的AOF文件**。

## 事件

redis服务器是一个事件驱动程序，服务器需要处理两类事件：文件事件和事件事件。
> redis服务器通过套接字与客户端进行连接，而文件事件就是服务器对套接字操作的抽象。服务器通过监听并处理这些事件来完成一系列网络通信操作。
> 时间事件：服务器对定时操作的抽象。
> 文件事件处理器是基于reactor模式实现的网络通信程序。

### 文件事件处理器

1.文件事件处理器以单线程模式运行，但通过I/O多路复用来监听多个套接字。既实现高性能的网络通信模型，又可以很好地与redis服务器中其他同样以单线程运行的模块进行衔接，保持了**redis内部单线程设计的简单性**。

2.套接字-->IO多路复用程序-->文件事件分配器-->不同的事件处理器

3.redis的IO多路复用底层实现是可以替换的，可以选择select， epoll, evport和kqueue等。

4.事件类型，当套接字可读（客户端write或者close或者connect），套接字产生AE_READABLE事件；当套接字可写时，产生AE_READBLE事件。如果同意套接字同时产生两种事件，则前者优先处理。

5.连接应答处理器，命令请求处理器，命令回复处理器。

### 时间事件

定时事件：让程序在指定时间之后执行，周期事件：让程序每隔一段时间执行一次。（id, when, timeproc）

保存时间事件的链表为无序链表。

serverCron函数：定期对redis自身的资源和状态进程调整，确保服务器长期稳定。

+ 更新各类统计信息，如时间，内存占用，数据库占用；
+ 清理过期键值对；
+ 关闭和清理连接失效的客户端；
+ 尝试进行持久化；
+ 如果服务器是主服务器，进行定期同步；
+ 如果是集群模式，对集群进行定期同步和连接测试。

### 调度执行

+ aeApiPoll函数的最大阻塞时间由到达最接近当前时间的**时间事件**决定。这样即可避免服务器对时间事件的频繁轮询，也可确保函数不会阻塞过长时间。
+ 对文件事件和时间事件的处理都是**同步，有序，原子**执行的，不会中断事件处理。事件处理器尽量减少阻塞时间，有需要时主动让出执行权，从而降低事件极饥饿的可能性。
+ 因为事件不可抢占，所以时间事件的处理时间通常比设置的稍晚一些。

## 多机数据库

主从复制，sentinel，集群原理

## 独立功能

发布订阅，事务，lua脚本，排序，二进制，慢查询日志，监视器

## etc

1.read more books about redis

2.murmurhash

3.hash负载因子的合理范围

4.c++的智能指针是基于引用计数实现内存回收，redis的对象系统也是基于引用计数进行内存回收。

5.redis如何保持性能？

6.reactor模式