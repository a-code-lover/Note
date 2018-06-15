# deep insight of c++ stl

Reference:

+ 侯捷《STL源码解析》

核心组件：container，algorithm, iterator, allocator, functor, adapter

## 1.源码：资源配置器Allocator

（1）设计：<font color=red>向system heap申请空间，考虑多线程，考虑内存不足的措施，考虑过多小型区块造成内存破碎问题。</font>
（2）std规格的allocators定义在defallocator.h，只是对::operator new和::operator delete的简单包装，并未考虑分配效率，分配失败等情况。在sgi_stl中使用stl_alloc.h,实现二级分配策略。
（3）当申请大于128B时，执行一级分配，直接使用c的malloc和free。有历史原因，而且c++没有remalloc操作。
（4）当申请小于128时，利用内存池进行分配回收，实行8字节对齐,维护16个linklist。<font color=red>**利用union实现链表节点结构，可以避免额外的管理空间。**</font>当内存不足时，执行一级策略向系统申请，由于一级使用c语言，所以用c语言模拟c++的new handle机制。stl标准的配置器定义在memory中。
