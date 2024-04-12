# DELETE FROM Person 
# WHERE id NOT IN (
#     SELECT id FROM (
#         SELECT MIN(id) AS id FROM Person GROUP BY email
#     ) AS temp
# );
DELETE p1
FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND
p1.Id > p2.Id
