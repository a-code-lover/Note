# design patterns

参考教程：

+ [菜鸟教程](http://www.runoob.com/design-pattern/design-pattern-tutorial.html)

## 1.设计模式

>设计模式是软件开发人员在软件开发过程中遇到一般问题的解决方案，是众多软件开发人员经过长时间的经验和错误的总结。

一般基于以下面向对象设计原则：

+ 对接口编程而不是对实现编程。
+ 优先使用对象组合而不是继承。

经典23种设计模式：

+ 创建型模式：工厂模式，抽象工厂模式，单例模式，建造者模式，原型模式
+ 结构型模式：适配器模式，过滤器模式，装饰器模式，代理模式，组合模式，
+ 行为型模式：观察者模式，

## 2.单例模式

>意图：保证一个类仅有一个实例，并提供一个访问它的全局访问点。
>
>主要解决：一个全局使用的类频繁地创建与销毁。
>
>何时使用：当您想控制实例数目，节省系统资源的时候。
>
>如何解决：判断系统是否已经有这个单例，如果有则返回，如果没有则创建。
>
>关键代码：构造函数是私有的。