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
order by total_cost, tour;