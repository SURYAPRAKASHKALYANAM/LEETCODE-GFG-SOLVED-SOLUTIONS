# Write your MySQL query statement below

UPDATE SALARY 
SET sex=
case 
when sex='m' then 'f'
else 'm'
end;
