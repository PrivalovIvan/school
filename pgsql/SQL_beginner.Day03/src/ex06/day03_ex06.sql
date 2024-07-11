select menu1.pizza_name, 
p1.name as pizzeria_name_1, 
p2.name as pizzeria_name_2 , 
menu1.price 
from menu as menu1
join menu as menu2 on menu1.pizza_name = menu2.pizza_name
join pizzeria as p1 on p1.id = menu1.pizzeria_id 
join pizzeria as p2 on p2.id = menu2.pizzeria_id
where p1.name < p2.name and menu1.price = menu2.price
order by pizza_name;