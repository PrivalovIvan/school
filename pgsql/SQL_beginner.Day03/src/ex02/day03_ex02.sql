select menu.pizza_name, price, p.name from menu 
join pizzeria as p on p.id = menu.pizzeria_id
where menu.id not in (select menu_id from person_order)
order by pizza_name, price;