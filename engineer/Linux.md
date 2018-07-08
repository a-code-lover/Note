# linux notes

## 1.reference

+ [tools quick tutorial](http://linuxtools-rst.readthedocs.io/zh_CN/latest/base/01_use_man.html)
+ [common linux command](https://www.cnblogs.com/peida/archive/2012/12/05/2803591.html)
+ [all linux command](http://www.runoob.com/linux/linux-command-manual.html)

## 2.basic

+ [命令参数一个-和两个-](https://www.zhihu.com/question/41366215)
+ 命令前加一个减号表示忽略命令的部分错误继续执行。
+ /usr/share/application: contain all the graphic shortcuts of applications.
+ [查看系统版本](https://blog.csdn.net/u011669700/article/details/79443134)
+ python版本升级  
  + wget, tar -zxvf, cd, ./configure, make, sudo make install
+ python替换版本  
  <https://www.jianshu.com/p/9d3033d1b26f>
  <https://blog.csdn.net/fang_chuan/article/details/60958329>
  <http://www.5ycode.com/article/59.html>
+ 以d结尾命名服务，是守护进程。以.d结尾的文件夹，保持对原有配置的兼容，同时存在.config和.config.d或者同时存在rc和rc.d。
+ init.d: 包含许多系统各种服务的启动和终止的脚本。
+ ssh经常超时断开：/etc/ssh/sshd_config配置

## 3.command

+ [ls -a -l -F -s -t -S / tree -L n](https://blog.csdn.net/xuehuafeiwu123/article/details/53817161)
+ shift + pageup/pagedown : terminal 翻页

## 4.tool

### (1)ssh

<http://www.ruanyifeng.com/blog/2011/12/ssh_remote_login.html>

### (2)./configure, make, make test, make install

<http://freetstar.com/trouble-shooting-configure-make-make-install>

这个要看你的Makefile的,约定俗成的而已。一般"潜规则"：

make就是make all,编译用的,具体编译了那些文件要看你的Makefile。

make install就是把编译出来的二进制文件,库,配置文件等等放到相应目录下，因为/usr/bin只有管理员才能向里面添加文件，所以通常要加sudo。

make clean清除编译结果。

具体的东西都在Makefile里面,只不过大部分应用程序的Makefile都是由configure脚本自动生成的,所以Makefile内容都差不多。

## 5.shell

### (1)Notice

1) no spaces before or after equal sign when set an variable.

## 6.mysql

(1)mysql命令必须以分号结尾，否则不显示。