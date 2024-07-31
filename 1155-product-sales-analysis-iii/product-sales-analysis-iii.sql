# Write your MySQL query statement below
select distinct s.product_id,s.year as first_year,s.quantity,s.price
from Sales s WHERE (product_id, year) IN (
SELECT product_id, MIN(year) as year
FROM Sales
GROUP BY product_id) ;