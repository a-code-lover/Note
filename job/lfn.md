# 1

## algorithm

### 海量数据处理（含topk问题）

[海量数据处理面试题](http://www.cnblogs.com/timchen5858/p/3652553.html?utm_source=tuicool&utm_medium=referral)

### 外排序为什么用归并？

因为归并排序算法不需要将所有记录读入内存。比如你的内存是10G, 对90G的数据排序，external merge sort的步骤是类似这样的：

1. 读10G数据然后进行in memory的sort，重复9次。得到9个10G的已经排好序的数据块。
2. 从每个chunk里分别读1G到9个输入buffer里，进行merge（9个已经排好序的1G数据一起merge），剩下的1G内存作为输出buffer用来存结果。当merge好1G数据后，把这1G的结果复制到硬盘中，然后清空输出buffer，接着merge，直到某个输入buffer中的1G数据都处理完，再向该输入buffer读入1G数据，如此往复直到所有9个数据块中的数据都处理完。

### 怎么给大量url和ip去重

[使用BloomFilter布隆过滤器解决缓存击穿、垃圾邮件识别、集合判重](https://blog.csdn.net/tianyaleixiaowu/article/details/74721877)
[布隆过滤器原理实现](https://www.cnblogs.com/cpselvis/p/6265825.html)

### 字符串hash成状态位的具体实现方式

[字符串hash函数](https://blog.csdn.net/yl2isoft/article/details/16362479)
[同上](https://blog.csdn.net/github_35124642/article/details/51506386)
[非加密哈希](https://segmentfault.com/a/1190000010990136)
[一致性哈希算法和MurmurHash](http://eovie.cn/notes/%E4%B8%80%E8%87%B4%E6%80%A7%E5%93%88%E5%B8%8C%E7%AE%97%E6%B3%95%E5%92%8CMurmurHash)

### hash函数如何保证冲突最小

[hash如何尽可能少的冲突](https://www.zhihu.com/question/20507188)