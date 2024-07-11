create table person_audit (
created timestamptz default (now() at time zone 'utc') not null,
type_event char(1) default 'I',CHECK (type_event IN ('I', 'U', 'D')),
row_id bigint not null ,
name varchar not null,
age integer not null default 10,
gender varchar default 'female' not null ,
address varchar
);


create or replace function fnc_trg_person_insert_audit()
returns trigger as $$
begin
	insert into person_audit
	values (now(), 'I', new.*);
return null;
end;
$$
language plpgsql;	


create trigger trg_person_insert_audit after insert on person
for each row execute function fnc_trg_person_insert_audit();

INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk');

select * from person_audit;