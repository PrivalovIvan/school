create sequence seq_person_discounts start 1 owned by person_discounts.id;

alter table person_discounts
alter column id set default nextval('seq_person_discounts') ;
select setval('seq_person_discounts', count(id)) from person_discounts;
