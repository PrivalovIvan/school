(select  p.name as pizzeria_name from pizzeria as p
join menu on menu.pizzeria_id = p.id
join person_order as po on po.menu_id = menu.id
join person on person.id = po.person_id
where gender = 'male'
) except
(select p.name from pizzeria as p
join menu on menu.pizzeria_id = p.id
join person_order as po on po.menu_id = menu.id
join person on person.id = po.person_id
where gender = 'female')
union 
(select  p.name from pizzeria as p
join menu on menu.pizzeria_id = p.id
join person_order as po on po.menu_id = menu.id
join person on person.id = po.person_id
where gender = 'female'
) except
(select p.name from pizzeria as p
join menu on menu.pizzeria_id = p.id
join person_order as po on po.menu_id = menu.id
join person on person.id = po.person_id
where gender = 'male')
order by pizzeria_name;
