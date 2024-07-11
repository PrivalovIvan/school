select p.address, pz.name, count(po.person_id) as count from person as p
join person_order as po on po.person_id = p.id 
join menu as m on m.id = po.menu_id
join pizzeria as pz on pz.id = m.pizzeria_id
group by (p.address, pz.name)
order by 1,2;