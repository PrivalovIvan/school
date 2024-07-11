create or replace function fnc_fibonacci(pstop bigint default 10) 
returns table (numbers_f bigint) as $$
    with recursive fib_r as 
        (
            select 0 as a, 1 as b
            union
            select b, a + b from fib_r where b < pstop 
        )
	select a from fib_r;
$$ language sql;

select * from fnc_fibonacci(100);