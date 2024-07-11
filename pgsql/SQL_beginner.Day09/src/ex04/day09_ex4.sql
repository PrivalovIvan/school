create function fnc_persons_male() returns setof person as $$
	select * from person where gender = 'male';
$$ language sql;

create function fnc_persons_female() returns setof person as $$
	select * from person where gender = 'female';
$$ language sql;


SELECT *
FROM fnc_persons_male();

SELECT *
FROM fnc_persons_female();
