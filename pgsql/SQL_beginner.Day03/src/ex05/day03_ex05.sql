select p.name as pizzeria_name from pizzeria as p
join person_visits as pv on pv.pizzeria_id = p.id
join person on person.id = pv.person_id
where person.name = 'Andrey'
except 
select p.name from pizzeria as p
join menu on menu.pizzeria_id = p.id
join person_order as po on menu.id = po.menu_id
join person on person.id = po.person_id
where person.name = 'Andrey'
order by pizzeria_name;

