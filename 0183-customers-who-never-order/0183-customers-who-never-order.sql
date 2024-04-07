# Write your MySQL query statement belowlet
select name as Customers from Customers where id not in(select customerId from Orders);