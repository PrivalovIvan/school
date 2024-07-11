select name,rating from pizzeria
left join person_visits on pizzeria.id = person_visits.pizzeria_id
where pizzeria_id is null;