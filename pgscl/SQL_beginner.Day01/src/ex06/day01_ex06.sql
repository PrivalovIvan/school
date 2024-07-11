(select order_date as action_date, 
	(select name from person where id = person_id) as name
 from person_order)
INTERSECT 	
(select visit_date, 
	(select name from person where id = person_id) 
 from person_visits)
order by action_date, name desc;