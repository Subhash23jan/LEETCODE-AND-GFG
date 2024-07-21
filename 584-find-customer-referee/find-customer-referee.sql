# Write your MySQL query statement below
select c1.name from Customer c1
where c1.referee_id is NULL || c1.referee_id<>2;