# stl api

## container

### vector

1.vector赋值：

+ 默认初始化
+ 带参初始化，单个或双个: vec(val), vec(nums, val)
+ 地址范围或迭代器区间: vec(Array.addrBegin, Array.addrEnd), vec(beginIter, endIter);
+ 拷贝构造
+ insert
+ copy(source.beginIter, sourceEndIter, targetIter);
+ assign
+ initial list

2.vector拷贝

+ 构造时拷贝
+ vec.assign(source.beginIter, source.endIter);
+ vec.swap(source);
+ vec.insert(target.iter, source.beginIter, source.endIter);

## 工具库

### [hash支持](https://zh.cppreference.com/w/cpp/utility/hash)

### bitset

## algorithm

### 堆操作

`std::make_heap()`, `std::push_heap()`, `std::pop_heap()`, `sort_heap()`, `is_heap()`

> 实现常量长度的位数组