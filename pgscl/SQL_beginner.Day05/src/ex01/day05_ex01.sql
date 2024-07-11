SET enable_seqscan = off;

explain 
	analyze 
select pizza_name, name as pizzeria_name from menu m
join pizzeria p on m.pizzeria_id = p.id;