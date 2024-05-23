# Write your MySQL query statement below
select class from Courses Group by class Having Count(student)>=5;