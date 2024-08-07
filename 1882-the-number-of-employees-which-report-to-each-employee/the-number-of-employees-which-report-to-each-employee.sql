# Write your MySQL query statement below
SELECT 
    M.employee_id,
    M.name,
    COUNT(E.reports_to) AS reports_count,
    ROUND(AVG(E.age)) AS average_age
FROM 
    Employees M
INNER JOIN 
    Employees E
ON 
    E.reports_to = M.employee_id
GROUP BY 
    M.employee_id
ORDER BY M.employee_id;
