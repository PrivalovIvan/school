select person.name, count(pv.person_id) as count_of_visits from person
join person_visits as pv on pv.person_id = person.id 
group by (person.name)
having count(pv.person_id) > 3