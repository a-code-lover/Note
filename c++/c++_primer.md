# c++ primer

## 1.basic

### etc

+ '\0'为ARSCII码0，在内存中为全零，字符串为NULL表示未分配内存，字符串为""已分配内存为指定内容。
+ cout, cerr, clog的差别？
+ 指针前加const和指针后加const，函数前加const和函数后加const。
+ 对于sizeof()的深入了解。
+ sizeof("abcd"); //结果为5.
+ 将基本一维数组`int a[]`或者二维数组`int a[][]`作为函数形参如何使用。

### (1)namespace std

+ std::ref(variable) --- 返回一个引用包装器
+ std::tuple make_tuple get std::pair
+ std::unique_ptr<>
+ std::move --- std::thread只能用move不能用copy
+ std::setpercision(n)和cout.precision(n)效果一样，一个是流对象函数一个是操纵函数。

### (2)assert()

若expression为0，则调用stderr打印一条错误信息，通过abort终止程序。仅在debug模式有效，可以关掉再release.

```c++
#include <assert.h>
void assert( int expression );
```

### (3)[new, ::operator new, ::operator delete](https://www.cnblogs.com/luxiaoxun/archive/2012/08/10/2631812.html)

### (4)emplace_back

add a new element to container by constructing it, but push_back copies or moves an existing object.

### (5)two dimensional vector initialize

    vector<vector<int> > newOne(r, vector<int>(c, 0));

    vector<vector<int> > res;
    res.resize(r);//r行
    for (int k = 0; k < r; ++k){
        res[k].resize(c);//每行为c列
    }

Plus:recommend using {} to initialize

### (6)operator ++ , += 1, + 1

set: only definition of ++ and --, but not + 1.

### (7)while else in python but no in c++

    while (j <= border[0]) {
        cout<<i<<j<<endl;
        result.push_back(matrix.at(i).at(j));
        j++; flag[0] = 1;
    }
    if (flag[0]) {j--; i++; border[3]++; flag[0] = 0;}

### (8)length() and size()

    both are the same. length is for the consistency of c language and size is designed for STL.

### (9)how to use extern

### (10)Node \* volatile \* p

## 2. name

### (1)下划线命名

系统头文件里将宏名，变量名，内部函数名以"_"开始，为了避免与用户命名冲突。在include时引用命名，如何重复导致的错误无法debug。在c语言中，以单下划线命名表示系统变量，以双下划线或单下划线加单大写字母表示编译器或者标准库预留或使用。所以用户应避免下划线命名。

### (2)作用域

+ ::name 表示全局作用域
+ class::name 表示类作用域
+ namespace::name 表示命名空间作用域

## 3. error

### (1)[Segmentation Fault: ](http://silencewt.github.io/2015/05/11/Segmentation-Fault%E9%94%99%E8%AF%AF%E5%8E%9F%E5%9B%A0%E6%80%BB%E7%BB%93/)

## 4. 输入/输出运算符

### \<ios\>

boolalpha, showbase, showpoint, showpos, skipws, uppercase, unitbuf, internal/left/right, dex/hex/oct, fixed/scientific

### \<ostream\>

ends, flush, endl

### \<iomanip\>

setiosflags, setfill, setw, setprecision, setbase

## 5.namespace

### std

> The ISO standards specify that "all library entities are defined within namespace std." This includes namespaces nested within namespace std, such as namespace std::chrono.  
> P.S. The ISO standard is a detailed technical document intended primarily for people writing C++ compilers and standard library implementations.

## 6.stream

### istringstream

## 7.rand随机数

```c++
srand(time(0));  //将srand放在循环外避免每次产生的随机数一样。
vector<int> shuffle() {
    vector<int> result(nums);
    for (int i = 0;i < result.size();i++) {
        int pos = rand()%(result.size()-i);
        swap(result[i+pos], result[i]);
    }
    return result;
}
```
