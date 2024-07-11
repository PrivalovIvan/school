insert into person_discounts (id, person_id, pizzeria_id, discount)  
(select row_number() over() as id, person_id, pizzeria_id, 
 (case when count(person_id) = 1 then 10.5 
       when count(person_id)  = 2 then 22 
       else 30 
  end)
 from person_order as po 
 join menu on menu.id = po.menu_id
 group by person_id, pizzeria_id
order by person_id
);
