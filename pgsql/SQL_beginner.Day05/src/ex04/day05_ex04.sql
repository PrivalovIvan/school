create unique index idx_menu_unique on menu (pizzeria_id, pizza_name);

SET enable_seqscan = off;
explain 
	analyze
select pizzeria_id, pizza_name from menu
where  pizza_name = 'cheese pizza' and pizzeria_id = 1;
