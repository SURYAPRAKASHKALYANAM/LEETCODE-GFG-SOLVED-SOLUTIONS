# # Write your MySQL query statement below

# select p1.id from Weather p1,Weather p2 where DATE(p2.recordDate)=DATE_SUB(p1.recordDate,INTERVAL 1 DAY) AND p1.temperature>p2.temperature;

SELECT w1.id
FROM Weather w1, Weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature;