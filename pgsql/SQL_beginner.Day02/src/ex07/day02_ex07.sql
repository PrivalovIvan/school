select p.name as pizzeria_name from person_visits as pv
join person on person.id = person_id
join pizzeria as p on p.id = pv.pizzeria_id 
join menu on menu.pizzeria_id = p.id
where person.name = 'Dmitriy' and  pv.visit_date = '2022-01-08' and menu.price < 800;