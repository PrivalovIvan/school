select name from person
join person_order as po on po.id = person.id 
join menu on menu.id = po.id
where person.address = 'Moscow'and gender = 'male'  or person.address = 'Samara'and gender = 'male'and 
menu.pizza_name = 'pepperoni pizza' or menu.pizza_name = 'mushroom pizza'
order by name desc;