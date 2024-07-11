-- Session #1

-- Update of rating for "Pizza Hut" to 5 points in a transaction mode.
begin;
update pizzeria set rating = 5 where name = 'Pizza Hut';
-- Check that you can see a changes in session #1.
select * from pizzeria where name = 'Pizza Hut';
-- Session #2

-- Check that you can’t see a changes in session #2.
select * from pizzeria where name = 'Pizza Hut';
-- Session #1

-- Publish your changes for all parallel sessions.
commit;
-- Session #2

-- Check that you can see a changes in session #2.
select * from pizzeria where name = 'Pizza Hut';
