create view v_price_with_discount as 
select person.name, 
menu.pizza_name, 
menu.price,
cast(menu.price - menu.price * 0.1 as int) as discount_price
from person_order as po
join person on person.id = po.person_id
join menu on menu.id = po.menu_id
order by person.name, menu.pizza_name;