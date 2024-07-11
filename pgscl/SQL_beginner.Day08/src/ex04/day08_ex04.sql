--изменил после второго коммита (сессия 1)

-- Session #1
begin;
set transaction isolation level serializable ;
-- Session #2
begin;
set transaction isolation level serializable ;

-- Session #1
select * from pizzeria where name = 'Pizza Hut';

-- Session #2
update pizzeria set rating = 3.6 where name = 'Pizza Hut';
commit;

-- Session #1
select * from pizzeria where name = 'Pizza Hut';
commit;

-- Session #1
select * from pizzeria where name = 'Pizza Hut';
-- Session #2
select * from pizzeria where name = 'Pizza Hut';
