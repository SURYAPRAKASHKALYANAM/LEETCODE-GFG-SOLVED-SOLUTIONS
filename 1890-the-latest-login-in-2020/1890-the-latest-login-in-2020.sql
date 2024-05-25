# Write your MySQL query statement below
SELECT user_id,max(time_stamp) AS last_stamp from Logins where time_stamp like "2020%" group by user_id;
