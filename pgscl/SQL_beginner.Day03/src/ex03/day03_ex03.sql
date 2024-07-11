with male_visits as (
select p.name as pizzeria_name
from person_visits as pv
join person on person.id = pv.person_id
join pizzeria as p on p.id = pv.pizzeria_id
where gender = 'male'
),
female_visits as (
select p.name
from person_visits as pv
join person on person.id = pv.person_id
join pizzeria as p on p.id = pv.pizzeria_id
where gender = 'female'
)


(select *
from male_visits
except ALL
select *
from female_visits
)
union all
(select *
from female_visits
except ALL
select *
from male_visits
)
order by pizzeria_name;

