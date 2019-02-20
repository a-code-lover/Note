# mysql高效编程

## api

+ myql -u root -p --按提示输入密码
+ SHOW databases;
+ DROP databases;
+ CREATE databases home;
+ use home;
+ grant all priviledges on home.* to user@localhost identified by '12345'; --创建授权用户
+ SELECT database(); --查看当前数据库
+ CREATE table if not exists customer(id INT NOT NULL, birth DATE, title VARCHAR(100) NOT NULL, primary + key(id))engine=InnoDB default charset=utf8;
+ CREATE table goods(id INT AUTO_INCREMENT PRIMARY KEY, name VATCHAR(30));
+ ALTER tables goods AUTO_INCREMENT=0;
+ SHOW tables;
+ DROP TABLE customerG;
+ desc customer; describe customer;
+ DROP table customer;
+ INSERT into customer(id, title) values(100, 'xiaohua');
+ INSERT into customer values(101, '1990-1-1', 'xiaoming');
+ UNIQUE制约, DEFAULT制约, CHECK制约
+ mysqladmin -u root -p CREATE home;
+ mysqladmin -u root -p < sampledb.sql;
+ **DML(manipulation), DDL(definition), DCL(control)**
+ SELECT * FROM customer；
+ UPDATE customer SET name='', birth='' WHERE TITLE='';
+ DELETE FROM customer WHERE birst='';
+ SELECT name,birth FROM customer WHERE birth>='1990/1/1'; --条件
+ SELECT name,birth FROM customer WHERE name LIKE '李%'; --%代笔0个以上字符，_表示一个字符
+ SELECT name,birth FROM customer WHERE birth>='1990/1/1' AND name LIKE '李_'; --多条件
+ SELECT name,birth FROM customer WHERE birth>='1990/1/1' AND name LIKE '李_', ORDER BY sec ASC, birth DESC; --排序
+ SELECT name,birth FROM customer WHERE birth>='1990/1/1' AND name LIKE '李_', ORDER BY sec ASC, birth DESC LIMIT 1,2; --从1开始取2条，limit 2表示从0开始取2条
+ SELECT sex,COUNT(id) FROM customer GROUP BY sex; --数据分组，统计男女人数
+ SELECT sex,COUNT(id)*2 AS cnt FROM customer GROUP BY sex; --别名，加减乘除运算
+ 处理算术运算，比较运算等，还提供数据库函数字符串函数，数值函数，日期函数等。
+ SELECT u.name,o.oid FROM order AS o INNER JOIN user AS u ON o.uid=u.uid; --内连接
+ 内连接，左外连接，右外连接，自连接
+ SELECT * FROM product WHERE price > (SELECT AVG(price) FROM product); --基本子查询
+ SELECT name,address FROM user WHERE uid NOT IN (SELECT uid FROM order WHERE odate=''); --多个返回值的子查询
+ SELECT name,address FROM user WHERE EXISTS (SELECT * FROM order WHERE user.uid=order.uid); --查询至少一单的用户

+ ALTER TABLE visitor MODIFY name VARCHAR(30); --由VARCHAR(20)改为VARCHAR(30)
+ ALTER TABLE visitor ADD old INT；
+ ALTER TABLE visitor ADD old INT FIRST；--加在最前面
+ ALTER TABLE visitor ADD old INT AFTER name；--任意位置
+ ALTER TABLE visitor MODIFY old INT AFTER name; --修改列的位置
+ ALTER TABLE visitor CHANGE birth birthday DATA; --修改列名和属性
+ ALTER TABLE visitor DROP old; --删除列

+ CREATE TABLE customerH SELECT * FROM customer; --复制列结构及数据
+ CREATE TABLE customerH LIKE customer; --复制列结构，包括PRIMARY KEY和AUTO_INCREMENT
+ INSERT INTO customerH SELECT * FROM customer; --复制数据 