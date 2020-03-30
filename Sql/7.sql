-- where 子句的作用是在对查询结果进行分组前，将不符合where条件的行去掉，
-- 即在分组之前过滤数据，where条件中不能包含聚组函数，使用where条件过滤出特定的行。
-- having 子句的作用是筛选满足条件的组，即在分组之后过滤数据，条件中经常包含聚组函数
-- 使用having 条件过滤出特定的组，也可以使用多个分组标准进行分组。
select emp_no,count(emp_no) t
from salaries
group by emp_no
having count(emp_no) > 15;