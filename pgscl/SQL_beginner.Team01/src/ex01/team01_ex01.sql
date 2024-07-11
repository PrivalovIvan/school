-- insert into currency values (100, 'EUR', 0.85, '2022-01-01 13:29');
-- insert into currency values (100, 'EUR', 0.79, '2022-01-08 13:29');

create or replace function koef_val(date timestamp, current_id bigint ) 
returns numeric as $$
declare k numeric;
begin 
select rate_to_usd into k from
(
 (select rate_to_usd, 
  abs((extract(epoch from date)) - (extract(epoch from c.updated))) as t
 from currency as c
 where c.id = current_id and c.updated < date
 order by t 
 limit 1)
  union
 (select rate_to_usd, 
  abs((extract(epoch from date)) - (extract(epoch from c.updated))) as t
 from currency as c
 where c.id = current_id and c.updated > date
 order by t 
 limit 1)
order by 2
limit 1);
return k;
end;
$$ language plpgsql;




select distinct
coalesce(u.name,'not defined') as name,
coalesce(lastname,'not defined') as lastname,
c.name as currency_name,
(koef_val(b.updated,c.id) * b.money) as currency_in_usd
from currency as c
join balance as b on b.currency_id = c.id
full join "user" as u on b.user_id = u.id
where c.name is not null
order by 1 desc,2 desc,3;