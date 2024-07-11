SET enable_seqscan = Off;
explain
	analyze
select * from person p   
	where UPPER(name) = 'ANNA';