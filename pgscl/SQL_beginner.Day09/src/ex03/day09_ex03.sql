drop function if exists fnc_trg_person_insert_audit cascade;
drop function if exists fnc_trg_person_update_audit cascade;
drop function if exists fnc_trg_person_delete_audit cascade;

create or replace function fnc_trg_person_audit() returns trigger as $$
begin
		if (tg_op = 'INSERT') then
            insert into person_audit select  now(),'I', new.*;
		elsif (tg_op = 'UPDATE') then
			insert into person_audit select now(), 'U', old.*;
        elsif (tg_op = 'DELETE') then
			insert into person_audit select now(), 'D', old.*;
		end if;
return null;
end;
$$ language plpgsql;

create or replace trigger trg_person_audit after insert or update or delete on person
for each row execute function fnc_trg_person_audit();

insert into person(id, name, age, gender, address)  values (10,'Damir', 22, 'male', 'Irkutsk');
update person set name = 'Bulat' where id = 10;
update person set name = 'Damir' where id = 10;
delete from person WHERE id = 10;

select * from person_audit;
