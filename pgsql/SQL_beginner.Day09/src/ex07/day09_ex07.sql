create or replace function func_minimum(arr anyarray) returns anyelement  as $$
	select min(i) from unnest(arr) as i;
$$ language sql;

SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);
