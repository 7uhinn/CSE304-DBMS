delimiter //

create procedure ProOne()
begin
select avg(E.esalary) as avg
from (
	select eno, count(depno) as numdep
    from dep
    group by eno
) as X, emp as E
where X.eno = E.eno and X.numdep > 2;
end;//

delimiter ;

CALL ProOne();

delimiter //

create procedure ProTwo()
begin
select E.eno, E.ename, D.depname
from (
	select eno, avg(depage) as avg_dep_age
    from dep
    group by eno
) as X, emp as E, dep as D
where X.eno = E.eno and X.avg_dep_age < 10 and E.eage > 50 and D.eno = E.eno;
end;//

delimiter ;

CALL ProTwo;