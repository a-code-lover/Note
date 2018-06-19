# c++ primer

## 1.basic

### （1）emplace_back

add a new element to container by constructing it, but push_back copies or moves an existing object.

### (2)two dimensional vector initialize

    vector<vector<int> > newOne(r, vector<int>(c, 0));

    vector<vector<int> > res;
    res.resize(r);//r行
    for (int k = 0; k < r; ++k){
        res[k].resize(c);//每行为c列
    }

Plus:recommend using {} to initialize

### (3)operator ++ , += 1, + 1

set: only definition of ++ and --, but not + 1.

### (4)while else in python but no in c++

    while (j <= border[0]) {
        cout<<i<<j<<endl;
        result.push_back(matrix.at(i).at(j));
        j++; flag[0] = 1;
    }
    if (flag[0]) {j--; i++; border[3]++; flag[0] = 0;}

### (5)length() and size()

    both are the same. length is for the consistency of c language and size is designed for STL.

### (6)how to use extern

### (7)Node \* volatile \* p

## 2. name

### (1)下划线命名

系统头文件里将宏名，变量名，内部函数名以"_"开始，为了避免与用户命名冲突。在include时引用命名，如何重复导致的错误无法debug。在c语言中，以单下划线命名表示系统变量，以双下划线或单下划线加单大写字母表示编译器或者标准库预留或使用。所以用户应避免下划线命名。

### (2)作用域

+ ::name 表示全局作用域
+ class::name 表示类作用域
+ namespace::name 表示命名空间作用域

## 3. error

### (1)[Segmentation Fault: ](http://silencewt.github.io/2015/05/11/Segmentation-Fault%E9%94%99%E8%AF%AF%E5%8E%9F%E5%9B%A0%E6%80%BB%E7%BB%93/)