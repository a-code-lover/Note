# mysql高效编程

## api

子查询，多表查询，排序

+ myql -u root -p --按提示输入密码
+ SHOW databases;
+ DROP database test;
+ CREATE database home;
+ use home;
+ grant all priviledges on home.* to user@localhost identified by '12345'; --创建授权用户
+ SELECT database(); --查看当前数据库
+ mysqladmin -u root -p CREATE home;
+ **mysqladmin -u root -p < sampledb.sql;**
+ **DML(manipulation), DDL(definition), DCL(control)**

+ CREATE table if not exists customer(id INT NOT NULL, birth DATE, title VARCHAR(100) NOT NULL, primary key(id))engine=InnoDB default charset=utf8;
+ CREATE table goods(id INT AUTO_INCREMENT PRIMARY KEY, name VATCHAR(30));
+ **ALTER tables goods AUTO_INCREMENT=0;**
+ SHOW tables;
+ DROP TABLE customerG;
+ desc customer; describe customer;
+ DROP table customer;
+ INSERT into customer(id, title) values(100, 'xiaohua');
+ INSERT into customer values(101, '1990-1-1', 'xiaoming');
+ UNIQUE制约, DEFAULT制约, CHECK制约
+ SELECT * FROM customer；
+ UPDATE customer SET name='', birth='' WHERE TITLE='';
+ DELETE FROM customer WHERE birst='';
+ SELECT name,birth FROM customer WHERE birth>='1990/1/1'; --条件
+ SELECT name,birth FROM customer WHERE name **LIKE '李%'**; --%代笔0个以上字符，_表示一个字符
+ SELECT name,birth FROM customer WHERE birth>='1990/1/1' AND name LIKE '李_'; --多条件
+ SELECT name,birth FROM customer WHERE birth>='1990/1/1' AND name LIKE '李_', ORDER BY sec ASC, birth DESC; --排序
+ SELECT name,birth FROM customer WHERE birth>='1990/1/1' AND name LIKE '李_', ORDER BY sec ASC, birth DESC LIMIT 1,2; --从1开始取2条，limit 2表示从0开始取2条
+ SELECT sex,COUNT(id) FROM customer GROUP BY sex; --数据分组，统计男女人数
+ SELECT sex,COUNT(id)*2 AS cnt FROM customer GROUP BY sex; --别名，加减乘除运算
+ 处理算术运算，比较运算等，还提供数据库函数字符串函数，数值函数，日期函数等。
+ SELECT u.name,o.oid FROM order AS o INNER JOIN user AS u **ON** o.uid=u.uid; --内连接
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
+ CREATE TABLE customerH **LIKE** customer; --复制列结构，包括PRIMARY KEY和AUTO_INCREMENT
+ INSERT INTO customerH SELECT * FROM customer; --复制数据

+ SHOW CREATE TABLE customer; --查看包括存储引擎
+ SHOW CREATE TABLE customer \G --用\G替换分号是监视器的小技巧，方便查看
+ ALTER TABLE customer ENGINE=MyISAM;
+ transaction事务：BEGIN,COMMIT,ROLLBACK，提交前可以回滚，提交后不可以。
+ SET AUTOCOMMIT=0; --关闭自动提交
+ SELECT @@AUTOCOMMIT; --查看自动提交模式
+ SAVEPOINT sp; ROLLBACK TO SAVEPOINT sp;

## transaction

+ drop database; drop table; drop; alter table; 这几个命令执行后会自动commit，不在事务处理范围之内。
+ 锁：共享锁（读锁），排他锁（写锁），粒度：行，表，库。
+ 不是锁的粒度越小越好，因为锁要消耗数据库服务器资源，锁数目越多消耗资源越多。mysql不支持库粒度，不支持锁提升。
+ 事务隔离级别；READ UNCOMMITED, READ COMMITTED, REPEATABLE READ（mysql默认级别）, SERIALIZABLE
+ 隔离性越高，锁定时间越长，性能降低。
+ 死锁时数据库采取将一方锁定强制解除，并rollback。

| 隔离水平 | 非提交读 | 不可重复读 | 幻象读 |
| ----- | ----- | ------| --- |
| READ UNCOMMITTED | YES | YES | YES |
| READ COMMITTED   | NO  | YES | YES |
| REPEATABLE READ  | NO  | NO  | YES |
| SERIALIZABLE     | NO  | NO  | NO  |

### 事务更新数据

UNDO日志：回滚段，在修改数据之前保存变更前的数据，表内容有指向undo日志的指针。
REDO日志：事务处理日志，commit后出错，利用redo日志恢复。客户端更新数据先更新内存，同时将事务写到REDO日志（实时），到达某一检查点是更新硬盘数据。如果写硬盘出错（如断电导致内存丢失），则排除故障并可根据REDO日志还原到故障点前。