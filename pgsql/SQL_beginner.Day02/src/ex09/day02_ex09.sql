select distinct person.name from person
join person_order as po on po.person_id = person.id 
join menu on menu.id = po.menu_id
where gender = 'female' and menu.pizza_name in  ('pepperoni pizza', 'cheese pizza')
order by name;