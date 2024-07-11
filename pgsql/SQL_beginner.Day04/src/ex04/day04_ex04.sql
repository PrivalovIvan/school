create view v_symmetric_union as 
((select person_id from person_visits
where visit_date < '2022-01-03')
 
except

(select person_id from person_visits
where visit_date < '2022-01-07'))

union

((select person_id from person_visits
where visit_date < '2022-01-07')
 
except

(select person_id from person_visits
where visit_date < '2022-01-03'))
order by person_id;