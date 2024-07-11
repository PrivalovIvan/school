select person_id,count(pv.pizzeria_id)as count_of_visits from person_visits as pv
group by pv.person_id 
order by 2 desc,1