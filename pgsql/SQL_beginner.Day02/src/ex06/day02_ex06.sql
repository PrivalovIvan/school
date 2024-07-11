select menu.pizza_name as pizza_name, pizzeria.name as pizzeria_name from person
join person_order on person_id = person.id 
join menu on menu.id = menu_id
join pizzeria on pizzeria.id = menu.pizzeria_id
where person.name = 'Anna' or person.name = 'Denis'
order by pizza_name,pizzeria_name;
