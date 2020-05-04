-- join操作是对于表来说的，join操作后面一定要用on给定外键信息
select employees.emp_no,salary 
from employees
left join salaries 
on employees.emp_no = salaries.emp_no
where employees.hire_date = salaries.from_date
order by employees.emp_no desc;