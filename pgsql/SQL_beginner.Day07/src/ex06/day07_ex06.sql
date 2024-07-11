select p.name, 
count(person_id) as count_of_orders,
round(avg(price),2)::REAL as average_price,
max(price) as max_price,
min(price) as min_price
from person_order as po
join menu as m on m.id = po.menu_id
join pizzeria as p on p.id = m.pizzeria_id
group by (p.name)
order by name;