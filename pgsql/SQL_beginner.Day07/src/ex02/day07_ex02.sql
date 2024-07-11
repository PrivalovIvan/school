(select p.name, count(m.pizzeria_id), 'order' as action_type from person_order as po
join menu as m on m.id = po.menu_id
join pizzeria as p on p.id = m.pizzeria_id
group by p.name
order by 2 desc
limit 3)
union
(select p.name, count(pizzeria_id) , 'visits' as action_type from person_visits as pv
join pizzeria as p on p.id = pv.pizzeria_id
group by p.name
order by 2 desc
limit 3)
order by 3,2 desc;