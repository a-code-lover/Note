# Web

## Web 服务器

### Apache和Tomcat

1.apache是web服务器（静态解析，如HTML），tomcat是java应用服务器（动态解析，如JSP、PHP、ASP）。tomcat只是一个servlet(jsp也翻译成servlet)容器，可以认为是apache的扩展，但是可以独立于apache运行。  
2.二者均为Apache组织开发，都有http服务功能，均为开源免费。  
3.apache是一辆车，上面可以装一些东西如html等，但是不能装水，要装水必须要有容器（桶），而这个桶也可以不放在卡车上，那这个桶就是TOMCAT。  
4.二者整合：如果客户端请求的是静态页面，则只需要Apache服务器响应请求；
如果客户端请求动态页面，则是Tomcat服务器响应请求，将解析的JSP等网页代码解析后回传给Apache服务器，再经Apache返回给浏览器端
这是因为jsp是服务器端解释代码的，Tomcat只做动态代码解析，Apache回传解析好的静态代码，Apache+Tomcat这样整合就可以减少Tomcat的服务开销。
