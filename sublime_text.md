参考配置:
    http://blog.csdn.net/hfut_jf/article/details/5285386 （markdownediting）
    http://jokerliang.com/markdown-editing-and-preview-in-sublime-text-3.html （markdown实时预览）
    https://feliving.github.io/Sublime-Text-3-Documentation/ (vintage模式)
    https://segmentfault.com/a/1190000002570753 (快捷键)
    http://damnwidget.github.io/anaconda/ (Anaconda Python配置)
    http://blog.csdn.net/dream_allday/article/details/78338736 (anaconda插件载入配置提示错误)
    http://blog.csdn.net/u011475210/article/details/78168341 （类IDE配置）
    http://www.riaway.com/theme.php(配色方案参考)
    https://www.jianshu.com/p/5f3a29632645 (Package Resource Viewer to change color scheme)
    https://jdhao.github.io/2017/03/04/Sublime-Windows-Markdown/ (markdown简单技巧)
    https://blog.csdn.net/coslay/article/details/42324505 (sublime代码补全插件)
    https://blog.csdn.net/qq_24345801/article/details/79077902 (解决输入法不同步问题)
    http://www.yalewoo.com/sublime_text_3_gcc.html  (配置c++环境)
    https://my.oschina.net/u/3485339/blog/900297  (c++) 
    http://www.linuxdiyf.com/linux/21941.html (c++compile)
    https://blog.qiujinfeng.com/archives/making-Sublime-Text-cplusplus-IDE.html  (配置c++环境)
    https://www.zhihu.com/question/39064280  （重装同步，覆盖roaming/sublimetext3文件夹）
    https://9iphp.com/web/html/sublime-text-code-snippets.html (定制snippet代码段)
    
插件：
    https://github.com/tushortz/CPP-Completions   （c++语法提示）
    https://github.com/Rapptz/cpp-sublime-snippet  （c++补全）
    SublimeAStyleFormatter （自动排版，处理缩进）

SublimeAStyleFormatter:
    **Windows, Linux:**
    + `ctrl+alt+f`: Format current file
    + `ctrl+k, ctrl+f`: Format current selection


技巧：

1.侧边栏：c-k-b，通过project->add folder to project添加文件夹，通过sidebarenhancement插件增强侧边栏的右键功能。

2.侧边栏的字体大小是在主题中修改的，功能扩展是在sidebar插件中实现的。 

3.要在sublime 实现c或c++代码的编译和运行，在本质上说也是调用外部的命令，windows中也可以理解为执行一段cmd命令。 
目前c/c++编译器最流行的就是gcc和g++,MinGW是Minimalist GNU on >Windows的首字母缩写，安装后就可以使用很多的GNU工具。GNU（GNU’s Not >Unix）是linux中的一个著名的项目，包含了gcc\g++\gdb等工具。也就是说，安装MinGw后，我们就可以使用gcc和g++命令了。

4.markdown中空格和空行对格式有很大影响。 

4.
 + ctrl+`:show console  
 + ctrl+shift+/：注释  
 + ctrl+m: jump out of brackets，normal  
 + shift+tab: markdown folding  
 + ctrl+pagedown: switch tag    
 + ctrl + k, ctrl + 1: fold all functions  
 + ctrl + k, ctrl + j: unfold all  or ctrl + 2          
 + ctrl + shift + [ or ]: fold and unfold 
 + ctrl + d: 光标处单词查找
 
5.多行编辑：
+ 鼠标选中多行，按下 Ctrl Shift L (Command Shift L) 即可同时编辑这些行；   
+ 鼠标选中文本，反复按 CTRL D (Command D) 即可继续向下同时选中下一个相同的文本进行同时编辑；   
+ 鼠标选中文本，按下 Alt F3 (Win) 或 Ctrl Command G(Mac) 即可一次性选择全部的相同文本进行同时编辑；    
+ Shift 鼠标右键 (Win) 或 Option 鼠标左键 (Mac) 或使用鼠标中键可以用鼠标进行竖向多行选择；    
+ Ctrl 鼠标左键(Win) 或 Command 鼠标左键(Mac) 可以手动选择同时要编辑。   

6.Windows下
备份文件夹：C:\Users\yourusername\AppData\Roaming\Sublime Text 3\Packages\User

Linux下
备份文件夹：~/Library/Application/Support/Sublime\ Text\ 3/Packages/User



