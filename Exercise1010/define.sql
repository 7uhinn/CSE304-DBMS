CREATE DATABASE ex10;

USE ex10;

CREATE TABLE Department
(
    Dname varchar(15),
    Dnumber int,
    Mgr_ssn int,
    Mgr_start_date date,
    PRIMARY KEY(Dnumber)
);

CREATE TABLE Employee
(
    Fname varchar(10),
    Minit char(1),
    Lname varchar(10),
    Ssn int,
    Bdate date,
    Address varchar(30),
    Sex char(1),
    Salary int,
    Super_ssn int,
    Dno int not NULL,
    PRIMARY KEY(Ssn),
    FOREIGN KEY(Dno) REFERENCES Department(Dnumber)
);

CREATE TABLE Dept_Locations
(
    Dnumber int,
    Dlocation varchar(10),
    PRIMARY KEY(Dnumber,Dlocation),
    FOREIGN KEY(Dnumber) REFERENCES Department(Dnumber)
);

CREATE TABLE Project
(
    Pname varchar(15),
    Pnumber int,
    Plocation varchar(10),
    Dnum int,
    PRIMARY KEY(Pnumber)
);

CREATE TABLE Works_On
(
    Essn int,
    Pno int,
    Hours float,
    PRIMARY KEY(Essn,Pno),
    FOREIGN KEY(Essn) REFERENCES Employee(Ssn),
    FOREIGN KEY(Pno) REFERENCES Project(Pnumber)
);

CREATE TABLE Dependent
(
    Essn int,
    Dependent_name varchar(10),
    Sex char(1),
    Bdate date,
    Relationship varchar(10),
    PRIMARY KEY(Essn,Dependent_name),
    FOREIGN KEY(Essn) REFERENCES Employee(Ssn)
);

DESCRIBE Employee;

DESCRIBE Department;

DESCRIBE Dept_Locations;

DESCRIBE Project;

DESCRIBE Works_On;

DESCRIBE Dependent;