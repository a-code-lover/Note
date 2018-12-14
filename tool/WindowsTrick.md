# improve efficiency on Windows

## 1.path

+ %appdata%:直接访问路径。
+ Windows使用\分隔目录是因为/被dos作为参数符号了。
+ Windows的~目录由环境变量HOME制定。

## 2.problems

### (1)打开的进程使用了dll文件导致文件无法删除

[tasklist命令](http://tech.sina.com.cn/s/s/2008-11-27/16192609051.shtml)
使用系统管理员的powershell。

## 3.VisualStudio

+ 菜单栏在工具->自定义中修改。
+ 配置vsvimrc后重启vs才生效
+ vs ctrl + tab切换标签页
+ vs 多列选择，shift+alt+arrow  ctrl+v in vim
+ vs 注释，ctrl+k+c/u
+ vs 代码自动对齐，ctrl+k, ctrl + f
+ windows:_sleep(5000)暂停5s_
+ vs 报错无法打开exe可能是之前的控制窗口没有关闭
+ ctrl + alt + A：命令窗口
+ Ctrl + M + O: 折叠所有方法
+ Ctrl + M + M: 折叠或者展开当前方法
+ Ctrl + M + L:  展开所有方法
+ ctrl + j:智能提示

## 4.了解Windows编程：

<https://blog.csdn.net/bigpudding24/article/details/48812399>

## 5.shortcut

+ win + i : settings
+ win + w : workplace
+ win + b : cursor to tray
+ alt + d == F6
+ alt + space
+ shift + 右击 : 当前文件夹打开power shell
+ c-a-arrow：旋转桌面
+ A-space-n:当前窗口最小化

## 6.批处理

```bat
rem 批量重命名
@echo off
rem 启用"延缓环境变量扩充"
setlocal enabledelayedexpansion
cd f:/test
set /a num = 0
rem /r为文件 /d为目录 !!表示变量延迟
for /r %%i in (*) do (
  set /a num += 1
  echo %%~ni
  ren %%i  !num!%%~ni.pdf
)
echo 批量重命名完成!
pause
```

### (1)变量  

<https://www.cnblogs.com/starspace/archive/2009/01/05/1368828.html>  
<http://www.yunweipai.com/archives/7315.html>  
[循环变量](https://blog.csdn.net/u010161379/article/details/50956652)  
[文件路径与名称提取](https://blog.csdn.net/gdp12315_gu/article/details/51322391)