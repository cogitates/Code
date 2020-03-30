-- 此处利用左连接，侧重点在左侧的表
select last_name,first_name,dept_no 
from employees
left join dept_emp
on employees.emp_no = dept_emp.emp_no;