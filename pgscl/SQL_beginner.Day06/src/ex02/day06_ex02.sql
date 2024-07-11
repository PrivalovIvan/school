select person.name, m.pizza_name, m.price, 
(m.price::REAL - m.price / 100 * pd.discount ) as discounts_price, 
p.name as pizzeria_name
from person_discounts as pd 
join person on person.id = pd.person_id
join pizzeria as p on p.id = pd.pizzeria_id
join menu as m on p.id = m.pizzeria_id
order by name ,	pizza_name