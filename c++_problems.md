##basic 

+ [进程的地址空间？](https://harttle.land/2015/07/22/memory-segment.html)
+ [哪些变量会默认初始化，哪些会随机初始化？](https://harttle.land/2015/10/05/cpp-variable-init.html)
+ [构造函数和析构函数没有返回值，以及抛出异常的问题？](https://www.cnblogs.com/luxiaoxun/archive/2012/09/06/2673249.html)
+ [什么情况下stl的迭代器和引用会非法化？](https://blog.csdn.net/y1196645376/article/details/52938474)
+ [类的对象会调用默认构造函数，对象的指针不会调用默认构造函数？](https://harttle.land/2015/06/22/cpp-object-lifecycle.html)
+ int * a = new int(10); a在栈， 10在堆。
+ [全局对象，静态对象，局部对象，const， static， static const](https://blog.csdn.net/jinpeng_cumt/article/details/52723131)  
[静态函数只能访问静态变量。static变量在类外初始化，避免重复定义。
常量对象只能访问构造函数，析构函数和常量函数，所有属性赋值都会编译报错。](https://harttle.land/2015/06/24/cpp-static-and-const-member.html)
> const修饰的量确切说叫只读量，不是常量。
> 可能在栈区，可能在全局区，看作用域以及有没有static修饰了，如果没有对其取地址的话，也可能被编译器优化为字
> 面常量。
+ [static_cast, dynamic_cast, const_cast](https://www.cnblogs.com/chenyangchun/p/6795923.html)
+ 类中的方法只声明，不定义，如果没被调用会报错吗？虚函数除外。
+ [引用占用内存？](https://stackoverflow.com/questions/1179937/how-does-a-c-reference-look-memory-wise)
+ [**[Item 3]**尽量使用常量](https://harttle.land/2015/07/21/effective-cpp-3.html)
+ 确保变量初始化？
+ [对象中有引用成员时，默认的赋值运算符会被delete掉?](https://harttle.land/2015/07/23/effective-cpp-5.html)
+ [**[Item 7]**将多态基类的析构函数定义为虚函数？](https://harttle.land/2015/07/24/effective-cpp-7.html)
+ [指针占几个字节？](https://zhidao.baidu.com/question/505146033.html)
+ [标准库的sizeof(string)占几个字节？64bit和32bit还不一样？](https://zhidao.baidu.com/question/165120550.html)
+ [类的存储字节如何对齐？](https://harttle.land/2015/07/24/effective-cpp-7.html)
> 对齐方式：最大基本数据类型，函数在代码段，所以与sizeof()无关。
+ [**[Item 8]**为什么不要再析构函数中抛出异常？](https://harttle.land/2015/07/26/effective-cpp-8.html)
+ [c++的异常处理好像有争议哦？](https://www.zhihu.com/question/22889420)
+ [**[Item 9]**在构造/析构时不要调用虚函数](https://harttle.land/tags.html#Effective-C++)
+ [**[Item 10]**赋值运算符重载要返回自己引用](https://harttle.land/2015/07/28/effective-cpp-10.html)
+ [**[Item 11]**赋值运算符的自赋值问题](https://harttle.land/2015/07/30/effective-cpp-11.html)
+ ??过多判断语句会影响程序的运行效率吗？
+ ??c++哪些机制是异常安全的？如何保证异常安全？
+ 可以忽略函数返回值的处理？
+ [**[Item 12]**完整地拷贝对象](https://harttle.land/2015/08/01/effective-cpp-12.html)
+ [**[Item 14]**??资源管理类要特别注意拷贝行为](https://harttle.land/2015/08/04/effective-cpp-14.html)
+ [数组名类似指针？(了解一下，不纠结) 指针数组，数组指针](https://www.cnblogs.com/ddx-deng/archive/2012/12/16/3755862.html)
https://www.cnblogs.com/kwdeblog/p/6097362.html
+ [**[Item 16]**使用同样的形式来new和delete](https://harttle.land/2015/08/07/effective-cpp-16.html)
+ [**[Item 17]**在单独的语句将new的对象放入智能指针中](https://harttle.land/2015/08/08/effective-cpp-17.html)
+ [**[Item 18]**让接口容易被正确使用，不易被误用](https://harttle.land/2015/08/08/effective-cpp-17.html)
+ [**[Item 19]**把类的设计当作类型的设计](https://harttle.land/2015/08/12/effective-cpp-19.html)
+ [**[Item 20]**传递常量引用比传值更好？](https://harttle.land/2015/08/13/effective-cpp-20.html)