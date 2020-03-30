-- distinct 是去重，后面跟的列就是去重对象
-- order by 是排序，后面跟的列是排序对象
-- desc 是降序排列， asc 是升序排列
-- limit 是选定数据
-- limit 5 是【0:4】
-- limit 4,3 是 【4:5】
select * from employees
where hire_date = (
      select distinct hire_date from employees order by hire_date desc limit 2,1
);