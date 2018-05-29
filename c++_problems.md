##basic 

+ [进程的地址空间？](https://harttle.land/2015/07/22/memory-segment.html)
+ [哪些变量会默认初始化，哪些会随机初始化？](https://harttle.land/2015/10/05/cpp-variable-init.html)
+ [构造函数和析构函数没有返回值，以及抛出异常的问题？](https://www.cnblogs.com/luxiaoxun/archive/2012/09/06/2673249.html)
+ [什么情况下stl的迭代器和引用会非法化？](https://blog.csdn.net/y1196645376/article/details/52938474)
+ [类的对象会调用默认构造函数，对象的指针不会调用默认构造函数？](https://harttle.land/2015/06/22/cpp-object-lifecycle.html)
+ int * a = new int(10); a在栈， 10在堆。
+ [全局对象，静态对象，局部对象，const， static， static const](https://blog.csdn.net/jinpeng_cumt/article/details/52723131)  
静态函数在data段，普通函数在stack，静态函数只能访问静态变量。static变量在类外初始化，避免重复定义。