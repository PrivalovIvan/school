--результат изменился после второго коммита (сессии 1)


-- (Session #1)
begin;
set transaction isolation level repeatable read;
-- (Session #2)
begin;
set transaction isolation level repeatable read;


-- (Session #1)
select sum(rating) from pizzeria;


-- (Session #2)
update pizzeria set rating = 1 where name = 'Pizza Hut';
commit;

-- (Session #1)
select sum(rating) from pizzeria;
commit;



-- (Session #1)
select sum(rating) from pizzeria;
-- (Session #2)
select sum(rating) from pizzeria;

