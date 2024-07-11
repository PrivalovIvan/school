select * from person_order 
where id % 2 = 0 and person_id % 2 = 0 and menu_id % 2 = 0
order by id;