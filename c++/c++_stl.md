# deep insight of c++ stl

Reference:

+ 侯捷《STL源码解析》

核心组件：container，algorithm, iterator, allocator, functor, adapter

## 1.源码：资源配置器Allocator

（1）设计：<font color=red>向system heap申请空间，考虑多线程，考虑内存不足的措施，考虑过多小型区块造成内存破碎问题。</font>
（2）std规格的allocators定义在defallocator.h，只是对::operator new和::operator delete的简单包装，并未考虑分配效率，分配失败等情况。在sgi_stl中使用stl_alloc.h,实现二级分配策略。
（3）当申请大于128B时，执行一级分配，直接使用c的malloc和free。有历史原因，而且c++没有remalloc操作。
（4）当申请小于128时，利用内存池进行分配回收，实行8字节对齐,维护16个linklist。<font color=red>**利用union实现链表节点结构，可以避免额外的管理空间。**</font>当内存不足时，执行一级策略向系统申请，由于一级使用c语言，所以用c语言模拟c++的new handle机制。stl标准的配置器定义在memory中。

## 2.源码：迭代器Iterator

(1)iterator is a smart pointer, the most common actions of pointer are defeference and memeber access. so the most important design of iterator is overloading of operator * and operator ->.
Inreference to auto_ptr, a wrapper of native pointer to deal with the memory leak problem.

```c++
template <class T>
class auto_ptr {
public:
    explicit auto_ptr(T *p = 0) : pointee(p) {};
    template<class U>
    auto_ptr(auto_ptr<U>& rhs) : pointee(rhs.release());
    ~ autp_ptr() {};

    template<class U>
    auto_ptr<T>& operator=(auto_ptr<U>& rhs) {
        if (this != &rhs) reset(rhs.release());
        return *this;
    }
    T& operator*() {return *pointee};
    T* operator->() {return pointee};
    T* get() {return pointee};
    //...

private:
    T *pointee;
}
```

```c++
template <class item>
struct Iterator {
    item* ptr;
    Iterator(item* p = 0) : ptr(p) {};

    item& operator*() const {return *ptr};
    item* operator->() const {return ptr};

//以下两个operator++遵循标准作法
    Iterator<item>& operator++() {  //pre-increment,item要不要写？
        ptr = pte->next(); return *this;
    }
    Iterator<item> operator++(int) {  //post-increment
        Iterator tmp = *this; ++*this; return tmp;
    }

    bool operator==(const Iterator& i) const {return ptr==i.ptr;}
    bool operator!=(const Iterator& i) const (return ptr!=i.ptr;)
}
```

（2）traits编程技法：类型萃取  

+ 利用function template 的自变量推导机制。
+ 加上原生类型和const的偏特化。
+ 注意typeid的使用。
+ 迭代器最常用的五种型别：value_type , difference_type , pointer , reference , iterator_categor
+ 五种迭代器：input Interator, output Iterator, Forward Interator, Bidirectionnal, RandomAccess

```c++
template <class T>
struct iterator_traits {
    typedef typename T::value_type value_type;
}

template <class T>
struct iterator_traits<T*> {
    typedef T value_type;
}

template <class T>
struct iterator_traits<const T*> {
    typedef T value_type;
}
```


