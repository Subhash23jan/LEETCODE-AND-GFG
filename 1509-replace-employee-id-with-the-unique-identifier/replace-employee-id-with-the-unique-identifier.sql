# Write your MySQL query statement below
select unique_id,name from Employees e
left join EmployeeUNI Eu on
e.id=Eu.id;