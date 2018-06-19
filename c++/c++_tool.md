# tools extension of c++ development

## 1.Basic API

### (1)namespace std

+ std::ref(variable) --- 返回一个引用包装器
+ std::tuple make_tuple get std::pair
+ std::unique_ptr<>
+ std::move --- std::thread只能用move不能用copy

### (2)assert()

若expression为0，则调用stderr打印一条错误信息，通过abort终止程序。仅在debug模式有效，可以关掉再release.

```c++
#include <assert.h>
void assert( int expression );
```

### (3)[new, ::operator new, ::operator delete](https://www.cnblogs.com/luxiaoxun/archive/2012/08/10/2631812.html)

<font color=#ff1111>注：c++的new handle机制。</font>

## 2.G++

[reference : Linux下gcc和gdb](http://blog.51cto.com/goodhx/1734760)

+ g++ -E *.cpp (预处理，生成.i/.ii文件，预处理起cpp)
+ g++ -S *.cpp (生成.s汇编文件，编辑器egcs,用编辑器打开看到汇编指令)
+ g++ -c *.cpp (生成.o目标文件，汇编器as)
+ g++ *.o *.exe -L $PATH (生成执行程序，链接器ld)
+ g++ -o test.exe test.cpp (包括编译链接，直接生成执行程序)
+ -o (表示输出)
+ -g (表示可调试)
+ -v (输出编译过程和编译器版本信息)
+ "-std=c++11"
+ "-Wall" (输出gcc提供的所有警告)
+ "-static-libgcc" (链接静态库)

## 3.extension library

### (1)日志库：[boost::log and glog](https://blog.csdn.net/lltaoyy/article/details/56674538)
