select distinct salary
from salaries
where salaries.to_date='9999-01-01'
order by salary desc;
-- order by后面要跟着对应的列