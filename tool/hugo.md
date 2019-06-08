# 安装配置

本地部署：<https://github.com/xianmin/hugo-theme-jane>
[gitpage部署](https://medium.com/@chs_wei/%E5%9C%A8-github-%E9%83%A8%E7%BD%B2-hugo-%E9%9D%9C%E6%85%8B%E7%B6%B2%E7%AB%99-9c40682dfe40)
[脚步配置](https://xiaomingplus.com/note/hugo-quick-start/)

## 踩过的坑

1. 之前利用hugo在本地部署，并部署到github page上去，但是没有把本地博客的文件夹上传到github仓库，后来换新电脑的时候直接把电脑格式化了，然后博客就没了。
2. 在新电脑使用`sudo apt install hugo`，装的是`Hugo Static Site Generator v0.16-DEV`，这个版本好多bug。
3. 配置一个主题后，最简单的方法是把主题的`exampleSites`拿过来直接用，稍微修改一下就好了。
4. `baseURL = "https://a-code-lover.github.io/"`注意使用https，之前使用http结果css、js等都被chrome拦截了，提示混合内容不安全。
5. 修改内容的时候有时候hugo后台会刷新，有时候需要手动重启一下，例如你添加了新的标签后，如果不刷新则改新的url不存在，显示404。

## hugo基本架构

+ config.toml：是整个网站的配置文件，其他的文件夹的作用：
+ archetypes：储存.md的模板文件，类似于hexo的scaffolds，该文件夹的优先级高于主题下的/archetypes文件夹。
+ content：包括网站内容，全部使用 markdown 格式。
+ layouts：包括了网站的`.html`模版，决定内容如何呈现，目录下模板优先级高于`/themes/<THEME>/layouts/`，可以用来小规模的定制主题。
+ static：包括了 css, js, fonts, media 等，决定网站的外观，该目录下的文件会直接拷贝到`/public`。
+ data: 储存数据文件供模板调用，类似于hexo的source/_data。

### 内容摘要

Hugo 会自动提取文章的前 70 个字符(hasCJKLanguage )作为摘要，可以在文章内使用 <!--more--> 注释进行强行分割。

### shortcodes

Shortcodes 帮助你在编写 markdown 时快捷的插入 HTML 代码，也可以编写自己的 Shortcodes，放置于根目录或者主题目录的 layouts/shortcodes 下。

## 主题：AllinOne

### config.toml

+ categories: 目录，文章所属的系列，关键词越少越好，也可理解为专栏。
+ tags: 标签，文章所涉及到的技术、内容、知识点，关键词越多越好。

### content

+ toc：Table of Content，侧边导航栏


