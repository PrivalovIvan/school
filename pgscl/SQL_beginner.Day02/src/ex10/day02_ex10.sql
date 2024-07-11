select person.name as person_name1, 
person2.name as person_name2, 
person.address as common_address 
from person
join person as person2 on person2.address = person.address
where person2.id < person.id
order by person_name1,person_name2,common_address