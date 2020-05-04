# Mysql学习

### 数据库操作
查看MySQL版本号
`mysql --version`
`select version();`

查看当前使用的数据库
`select database();`

进入数据库
`mysql -u root -p;`

查看数据库
`show databases;`

创建数据库
`create database BookDB;`

使用数据库
`use BookDB;`

数据库导入
1. `mysql -u root -p BookDB < Code/Sql/BookTable/Book.sql;`
2. `source ~/Code/Sql/BookTable/Book.sql;`

数据库导出
`mysqldump -u root -p BookDB > backup.sql；`

数据库删除
`drop database test;`

退出数据库
`CTRL+C`
`\q`

提前结束当前查询
`\c`

### 表操作
查看其他库中的表
`show tables from <other database>;`

查看表结构
`desc <table name>;`

查看表创建语句
`show create table <table name>;`

### 数据库查询操作
`select <column name> from <table name>;`
不建议在专业场合使用 `select *`

```sql
--- sql查询语句中可以使用运算表达式
--- select语句不会更改表内容
MariaDB [BookDB]> select id,author_id from book;
+----+-----------+
| id | author_id |
+----+-----------+
|  1 |        11 |
|  2 |        11 |
|  3 |        12 |
|  4 |        12 |
+----+-----------+
4 rows in set (0.00 sec)

MariaDB [BookDB]> select id,author_id*2 as double_author_id  from book;
+----+------------------+
| id | double_author_id |
+----+------------------+
|  1 |               22 |
|  2 |               22 |
|  3 |               24 |
|  4 |               24 |
+----+------------------+
4 rows in set (0.00 sec)
```

```sql
<MNnMariaDB [BookDB]> select id,author_id from book;
+----+-----------+
| id | author_id |
+----+-----------+
|  1 |        11 |
|  2 |        11 |
|  3 |        12 |
|  4 |        12 |
+----+-----------+
4 rows in set (0.00 sec)

MariaDB [BookDB]> select id,author_id*2 as double_author_id  from book;
+----+------------------+
| id | double_author_id |
+----+------------------+
|  1 |               22 |
|  2 |               22 |
|  3 |               24 |
|  4 |               24 |
+----+------------------+
4 rows in set (0.00 sec)
```

字符串
SQL标准字符串使用单引号`'`
MySQL支持双引号`"`   nm,

数据库中判断值是不是空只能用`is null` `is not null`

`%`是一个占位符，表示0-n个任意字符，用于模糊查询
`_`是一个占位符，代表任意一个字符，用于模糊查询

排序
`order by a,b,c;`优先级a>b>c
`desc`降序
```sql
MariaDB [BookDB]> select id,translator_id from book  order by translator_id desc,id asc;
+----+---------------+
| id | translator_id |
+----+---------------+
|  3 |            12 |
|  4 |            12 |
|  1 |            11 |
|  2 |          NULL |
+----+---------------+
4 rows in set (0.00 sec)
```
数据库