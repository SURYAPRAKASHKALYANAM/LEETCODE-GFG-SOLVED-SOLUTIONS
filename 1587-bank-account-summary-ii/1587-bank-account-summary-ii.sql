# Write your MySQL query statement below

SELECT Users.name AS name,SUM(Transactions.amount) AS balance  FROM Users JOIN Transactions ON Users.account = Transactions.account GROUP BY Transactions.account HAVING SUM(Transactions.amount)>10000;