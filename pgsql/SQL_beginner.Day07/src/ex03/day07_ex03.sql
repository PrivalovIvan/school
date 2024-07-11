select name,sum(count) as total_count from 
	((select p.name, count(m.pizzeria_id)as count from person_order as po
	 join menu as m on m.id = po.menu_id
	 join pizzeria as p on p.id = m.pizzeria_id
	group by p.name
	order by 2 desc)
		union all
	(select p.name, count(pizzeria_id)as count from person_visits as pv
	join pizzeria as p on p.id = pv.pizzeria_id
	group by p.name
	order by 2 desc)) 
group by name
order by 2 desc,1;