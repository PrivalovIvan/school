-- create table cost_table (
-- id serial primary key,
-- point1 varchar not null,
-- point2 varchar not null,
-- cost int not null 
-- )

-- insert into cost_table (point1,point2,cost) values
-- ('a','b',10),
-- ('a','c',15),
-- ('a','d',20),
-- ('b','a',10),
-- ('b','c',35),
-- ('b','d',25),
-- ('c','a',15),
-- ('c','b',35),
-- ('c','d',30),
-- ('d','a',20),
-- ('d','b',25),
-- ('d','c',30);

create materialized view cost_mat as (
 with recursive cost_r as (
 select point1,point2,cost, array[point2]::varchar[] as route, cost as total_cost  
 from cost_table where point1 = 'a'
 union
 select ct.point1, ct.point2, ct.cost, cr.route || ct.point2, ct.cost + total_cost as total_cost
 from cost_r as cr
 join cost_table as ct on  cr.point2 = ct.point1 
 where not cr.route @> array[ct.point2]::varchar[]
 )
select total_cost, array['a'] || route as tour from cost_r
where array['a','b','c','d']::varchar[] @> route and route[4] = 'a'
order by total_cost, tour
);

select * from cost_mat where total_cost = 
 (select min(total_cost) from cost_mat);