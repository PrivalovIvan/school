select order_date, concat (name,' (возраст:',age,')') as person_information
from person_order
natural join person
order by order_date, person_information;
