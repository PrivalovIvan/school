select coalesce(person.name,'-') as person_name,
coalesce( pv.visit_date::text, 'null')as visit_date,
coalesce(pizzeria.name,'-') as pizzeria_name from person 
full join (select * from  person_visits 
		   where person_visits.visit_date between '2022-01-01' and '2022-01-03' ) as pv
			on pv.person_id = person.id 
full join pizzeria on pizzeria.id = pv.pizzeria_id
order by  person_name ,visit_date, pizzeria_name
;