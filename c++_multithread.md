[教程](https://www.kancloud.cn/jxm_zn/cpp_concurrency_in_action/264949)
##1.并发
c++标准库并未对进程间通信提供原生支持，所以实现多进程并发必须依赖与平台相关的API。
进程间通信的缺点：设置复制，速度慢，开销大，因为操作系统要提供进程间保护和进程管理，还有启动问题。
优点：安全，可以实现远程连接。

##2.线程管理
###启动
```c++
void do_some_work();
std::thread my_thread(do_some_work);
```

```c++
class background_task {
public:
    void operator() () {
        do_something;
        do_something_else;
    }
};

background_task f;
std::thread my_thread(f);
```

也可以使用lambda函数。

```c++
//分离还是等待线程结束
std::thread my_thread(do_something_inbackground);
my_thread.detach();
assert(!my_thread.joinable());
```


###向线程函数传参
```c++
void f(int a, std::string const & s);
std::thread t(f, 10, "hallo");
```

```c++
class X {
public:
    void do_something(int & a) {

    };
}
X x;
int num(10);
//pass the reference of the object 
std::thread t(&X::do_something, &x, num);
```

###转移线程所有权

###运行时决定线程数量
`std::thread::hardware_concurrence()`

###识别线程
`std::thread::id`  
`std::this_thread::get_id()`

```c++
std::thread::id master_thread;
void some_core_part_of_algorithm()
{
  if(std::this_thread::get_id()==master_thread)
  {
    do_master_thread_work();
  }
  do_common_work();
}
```

##3.线程间共享数据

###使用互斥量保护共享数据
>C++中通过实例化std::mutex创建互斥量，通过调用成员函数lock()进行上锁，unlock()进行解锁。不过，不推荐实践中直接去调用成员函数，因为调用成员函数就意味着，必须记住在每个函数出口都要去调用unlock()，也包括异常的情况。C++标准库为互斥量提供了一个RAII语法的模板类std::lack_guard，其会在构造的时候提供已锁的互斥量，并在析构的时候进行解锁，从而保证了一个已锁的互斥量总是会被正确的解锁。

```c++
std::list<int> some_list;
std::mutex some_mutex;
void add_to_list(int some_value) {
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(some_value);
}
```

问题：具有访问能力的指针和引用可以访问甚至修改被保护的数据，而且不受互斥锁的限制。因此，互斥量保护的数据需要对接口进行谨慎的设计，要确保互斥锁能够锁住任何保护的数据，而且不留后门。

###谨慎设计代码保护共享数据
>只要没有成员函数通过返回值或者输出参数的形式向其调用者返回指向受保护数据的指针或引用，数据就是安全的。如果你还想往祖坟上刨，就没这么简单了。在确保成员函数不会传出指针或引用的同时，检查成员函数是否通过指针或引用的方式来调用也是很重要的(尤其是这个操作不在你的控制下时)。函数可能没在互斥量保护的区域内，存储着指针或者引用，这样就很危险。更危险的是：将保护数据作为一个运行时参数。

###接口内在的条件竞争
细粒度锁，粗粒度锁

###死锁

死锁，它的最大问题就是由两个或两个以上的互斥量来锁定一个操作。避免死锁的一般建议，就是让两个互斥量总以相同的顺序上锁：总在互斥量B之前锁住互斥量A，就永远不会死锁。某些情况下是可以这样用，因为不同的互斥量用于不同的地方，但可能有多个互斥量保护同一个类的独立实例。C++标准库有办法解决这个问题，std::lock——可以一次性锁住多个(两个以上)的互斥量，并且没有副作用(死锁风险)。

```c++
friend void swap(X& lhs, X& rhs)
  {
    if(&lhs==&rhs)
      return;
    std::lock(lhs.m,rhs.m); // 1
    std::lock_guard<std::mutex> lock_a(lhs.m,std::adopt_lock); // 2
    std::lock_guard<std::mutex> lock_b(rhs.m,std::adopt_lock); // 3
    swap(lhs.some_detail,rhs.some_detail);
  }
```