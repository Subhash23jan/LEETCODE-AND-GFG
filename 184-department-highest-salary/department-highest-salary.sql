# Write your MySQL query statement below
select d.name Department,e.name Employee ,e.salary as Salary from Employee e,Department d
where e.departmentId=d.id and e.salary=(select max(salary) from Employee where d.id=departmentId)