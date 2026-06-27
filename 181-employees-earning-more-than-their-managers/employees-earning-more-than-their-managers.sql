# Write your MySQL query statement below
select E2.name  as Employee from Employee E1 join Employee E2 
on E1.id = E2.managerId 
where E2.salary > E1.salary;