create unique index idx_person_discounts_unique on person_discounts (person_id, pizzeria_id);

set enable_seqscan = off;
set enable_indexscan = off;
set enable_bitmapscan = off;

explain 
	analyze
select * from person_discounts as pd 
join person on person.id = pd.person_id