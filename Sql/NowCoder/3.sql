-- 单独列不用写明表，某个列在两个表中都出现则应该指明表
select salaries.emp_no,salary,salaries.from_date,salaries.to_date,dept_no
    from salaries,dept_manager
        where salaries.emp_no=dept_manager.emp_no
            and salaries.to_date='9999-01-01'
            and dept_manager.to_date='9999-01-01';