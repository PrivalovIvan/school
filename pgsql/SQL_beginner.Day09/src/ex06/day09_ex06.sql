drop function if exists fnc_person_visits_and_eats_on_date;
create or replace function fnc_person_visits_and_eats_on_date
(pperson varchar default 'Dmitriy',
 pprice numeric default 500,
 pdate date default '2022-01-08') returns table(pizzeria_name varchar) as $$
begin
return query
	select p.name from menu
	join pizzeria as p on p.id = menu.pizzeria_id
	join person_visits as pv on pv.pizzeria_id = menu.pizzeria_id
	join person on person.id = pv.person_id
	where price < pprice and person.name = pperson and pv.visit_date = pdate;
end;
$$ language plpgsql;


select *
from fnc_person_visits_and_eats_on_date(pprice := 800);

select *
from fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');

