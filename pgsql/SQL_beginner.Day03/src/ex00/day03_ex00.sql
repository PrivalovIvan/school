select menu.pizza_name,
menu.price,
p.name as pizzeria_name,
pv.visit_date 
from pizzeria as p
join menu on menu.pizzeria_id = p.id
join person_visits as pv on pv.pizzeria_id = p.id
join person on person.id = pv.person_id
where menu.price between 800 and 1000 and person.name = 'Kate'
order by pizza_name, price, pizzeria_name
;