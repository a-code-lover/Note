# notes for vscode

## 1.reference

+ [official](https：//code.visualstudio.com/docs/languages/cpp)
+ [vscode入门](https：//www.jianshu.com/p/3dda4756eca5)
+ [vim入门](https：//feifeiyum.github.io/2017/01/23/vimusage/)
+ [中文文档](https：//legacy.gitbook.com/book/jeasonstudio/vscode-cn-doc/details)
+ [基本使用教程](https：//www.w3cschool.cn/visualstudiocode/)
+ [配置c++](https：//www.zhihu.com/question/30315894)
+ [配置c++](https：//blog.csdn.net/qq_32126633/article/details/78838554)
+ [snippets](https://www.jianshu.com/p/1f1132df1def)

## 2.shortcut

### (1)editor

+ C-k, v ： markdown live preview (C-S-v)
+ C-S-p / f1： show command palettte
+ C-space ： intellisense suggestions
+ C-1/2 ： 编辑器切换
+ A-num ： 标签切换 C-pageup/pagedown
+ C-p ： 快速打开最近打开的文件
+ C-k,C-s ： 查看所有快捷键
+ C-p, right arrow ： open muliple files
+ C-k, z ： zen mode
+ C-` ： terminal / C-S-y ： console;
+ C-l ： clear terminal C-k
+ C-S-e ： switch between explorer and editor
+ c-s-\：跳转到括号匹配处
+ C-a: choose all
+ C-up/down：滚动

### (2)code

+ C-[/] ： add tab
+ C-i ： select current line
+ C-S-p + 输入fold ： 可以查看所有折叠快捷键
+ A-arrow up/down ： move one line up or down
+ S-A-mouse drag： choose columns
+ S-A-a: block comment

### (3)plugin  

#### settting sync

<https：//www.cnblogs.com/ashidamana/p/6761085.html>

+ S-A-u/d ： 同步

## 3.编译环境

Mind： the folder .vscode must be put together with src files.

### c++

1. 数组越界竟然不输出错误，而是直接退出。。。。。。
2. c_cpp_properties.json文件中的includePath用于静态编译检查，实际在编译是要**将链接的文件添加到gcc的参数**中。
3. [gdb调试打印容器](https://blog.csdn.net/xiedejun1984/article/details/5752945)
    + vscode是直接调用gdb。
    + (gdb) print *(myVector._M_impl._M_start)@myVector.size() 打印整个vector。
    + print *(myVector._M_impl._M_start)@N 打印第N个成员。
    + 在vscode的debug console中执行-exec p myVector查看容器模板。
