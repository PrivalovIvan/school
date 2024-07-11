create or replace function fnc_trg_person_delete_audit() 
returns trigger as $$
begin
	insert into person_audit
	select now(), 'D', old.*;
return null;
end;
$$
language plpgsql;

create trigger trg_person_delete_audit after delete on person
for each row execute function fnc_trg_person_delete_audit();

DELETE FROM person WHERE id = 10;

select * from person_audit;


