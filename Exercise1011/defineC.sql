create table emp(
	eno int,
    ename varchar(10),
    eage int,
    esalary int,
    departno int,
    supereno int,
    primary key(eno)
);

create table dep(
	depno int,
    depname varchar(10),
    depage int,
    eno int,
    primary key(depno)
);

create table depart(
	departno int,
    departname varchar(10),
    location varchar(10),
    primary key(departno,departname,location)
);