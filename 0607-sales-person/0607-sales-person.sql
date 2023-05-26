# Write your MySQL query statement below
SELECT name FROM SalesPerson WHERE sales_id NOT IN (SELECT Orders.sales_id FROM Orders WHERE Orders.com_id IN (SELECT com_id from Company WHERE  name='RED'));
