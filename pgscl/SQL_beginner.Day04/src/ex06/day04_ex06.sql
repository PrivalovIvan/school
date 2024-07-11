create materialized view mv_dmitriy_visits_and_eats as
select  pizzeria.name from person_visits as pv
join person on person.id = pv.person_id
join pizzeria on pizzeria.id = pv.pizzeria_id
join menu on menu.pizzeria_id = pizzeria.id
where person.name = 'Dmitriy'and visit_date = '2022-01-08' and menu.price < 800;