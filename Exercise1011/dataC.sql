insert into emp
	(eno,ename,eage,esalary,departno,supereno)
values
	(1,'Jake',33,70000,1,3),
    (3,'Terry',53,100000,1,4),
    (4,'Raymond',70,130000,1,null);
    
insert into dep
	(depno,depname,depage,eno)
values
	(1,'Cagney',5,3),
    (2,'Lacey',5,3),
    (3,'Ava',2,3),
    (4,'Roger',70,1),
    (5,'Amy',33,1),
    (6,'Karen',70,1),
    (7,'Kevin',70,4);
    