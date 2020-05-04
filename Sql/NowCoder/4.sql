-- answer 1
select last_name,first_name,dept_no 
    from dept_emp,employees
        where  dept_emp.emp_no = employees.emp_no;

-- answer 2
select last_name,first_name,dept_no 
    from employees inner join dept_emp de
        on employees.emp_no = de.emp_no;


