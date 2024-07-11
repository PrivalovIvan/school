select person_order.order_date  as order_data, concat (person.name,' (возраст:',person.age,')') as person_information 
from person_order
join person on person.id = person_order.person_id
order by order_data, person_information;