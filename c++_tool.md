##Basic API
###namespace std
+ std::ref(variable) --- 返回一个引用包装器
+ std::tuple make_tuple get std::pair
+ std::unique_ptr<>
+ std::move --- std::thread只能用move不能用copy   


###assert()
若expression为0，则调用stderr打印一条错误信息，通过abort终止程序。仅在debug模式有效，可以关掉再release.

```c++
#include <assert.h>
void assert( int expression );
```

##设计模式，编程范式