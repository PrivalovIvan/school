select name as pizzeria_name from pizzeria
where id not in (select pizzeria_id from person_visits);

select name as pizzeria_name from pizzeria
where not exists (select * from person_visits where pizzeria.id = person_visits.pizzeria_id);

