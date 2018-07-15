# Database

[开源数据库现状](http://www.techug.com/post/all-open-source-database-status.html)

## Mysql

<http://www.cnblogs.com/xiaoluo501395377/archive/2013/04/07/3003278.html>
<https://blog.csdn.net/qq_35246620/article/details/70823903>  

### 操作

(1)mysql命令必须以分号结尾，否则不显示。  
(2)mysql可以输入多个语句执行。
(3)入门书籍：《mysql必知必会》。
(4)多数DBMS使用+或||实现拼接，mysql使用concat()函数实现。
(5)使用like或regexp匹配。
(6)Trim(), LTrim(), RTrim()去掉空格。
(7)sql函数：字符串，数值，日期时间，系统信息。
(8)Soundex()竟然支持类似发音匹配。
(9)aggregate函数。
(10)数据分组：group by和having。
(11)字句顺序：select, from, where, group by, having, order by, limit.
(12)子查询。逐渐增加。
(13)联结:通过一条select语句查找多个关联表，在运行时关联表中正确的行。(主键和外键,完全限定列名,inner join on ,性能)。
(14)别名:列别名和表别名，表别名只在查询中使用，不返回客户机。
(15)有时候自联结比子查询快得多。内联结，外联结，自联结。
(16)组合查询，union 或 union all。只能在末尾使用一个order by。查询相同的表相同的列。
(17)全文搜索：fulltext(), match(), against()。在select处使用match和在where处使用差别很大。
(18)insert low_priority into [] value (),()...;操作耗时。
(19)update [] set [] where; delete from [] where []; mysql不能撤销，注意upate和delete。
(20)create table, drop table, alter table, rename table。
(21)视图：保存查询结构，复用与保护。create or replaces view as []。(视图不一定能更新)

### 搜索引擎

innodb引擎：支持数据库事务和行级锁，目标是处理大数据容量的数据库系统。数据结构：B+树，存地址。

MyIASM引擎：mysql默认引擎，不提供事务支持和行级锁和外键。写操作要锁整个表。数据结构：B+树，存实际数据。

Memory:功能等同于MyISAM，但由于数据存储杂内存中，速度很快，特别适合临时表。

### 数据库事务的四大特性(ACID)

原子性(atomicity), 一致性(consistency)，隔离性(Isolation)，持久性(Durability)。
脏读，不可重复读，幻读。
