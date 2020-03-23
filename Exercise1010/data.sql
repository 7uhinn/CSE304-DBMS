INSERT INTO Employee
    (Fname,Minit,Lname,Ssn,Bdate,Address,Sex,Salary,Super_ssn,Dno)
VALUES
    ('John', 'B', 'Smith', 123456789, '1955-01-09', '731 Fondren, Houston, TX', 'M', 30000, 333445555, 5),
    ('Franklin', 'T', 'Wong', 333445555, '1945-12-08', '638 Voss, Houston, TX', 'M', 40000, 888665555, 5),
    ('Alicia', 'J', 'Zelaya', 999887777, '1958-07-19', '3321 Castle, Spring, TX', 'F', 25000, 987654321, 4),
    ('Jennifer', 'S', 'Wallace', 987654321, '1931-06-20', '291 Berry, Bellaire, TX', 'F', 43000, 888665555, 4),
    ('Ramesh', 'K', 'Narayan', 666884444, '1952-09-15', '975 Fire Oak, Humble, TX', 'M', 38000, 333445555, 5),
    ('Joyce', 'A', 'English', 453453453, '1962-07-31', '5631 Rice, Houston, TX', 'F', 25000, 333445555, 5),
    ('Ahmad', 'V', 'Jabbar', 987987987, '1959-03-29', '980 Dallas, Houston, TX', 'M', 25000, 987654321, 4),
    ('James', 'E', 'Borg', 888665555, '1927-11-10', '450 Stone, Houston, TX', 'M', 55000, NULL, 1);

SELECT *
FROM Employee;


INSERT INTO Department
    (Dname,Dnumber,Mgr_Ssn,Mgr_start_date)
VALUES
    ('Research', 5, 333445555, '1978-05-22'),
    ('Administration', 4, 987654321, '1985-01-01'),
    ('Headquarters', 1, 888665555, '1971-06-19');

SELECT *
FROM Department;


INSERT INTO Dept_Locations
    (Dnumber,Dlocation)
VALUES
    (1, 'Houston'),
    (4, 'Stafford'),
    (5, 'Bellaire'),
    (5, 'Sugarland'),
    (5, 'Houston');

SELECT *
FROM Dept_Locations;


INSERT INTO Project
    (Pname,Pnumber,Plocation,Dnum)
VALUES
    ('ProductX', 1, 'Bellaire', 5),
    ('ProductY', 2, 'Sugarland', 5),
    ('ProductZ', 3, 'Houston', 5),
    ('Computerization', 10, 'Stafford', 4),
    ('Reorganization', 20, 'Houston', 1),
    ('Newbenefits', 30, 'Stafford', 4);

SELECT *
FROM Project;


INSERT INTO Works_On
    (Essn,Pno,Hours)
VALUES
    (123456789, 1, 32.5),
    (123456789, 2, 7.5),
    (666884444, 3, 40.0),
    (453453453, 1, 20.0),
    (453453453, 2, 20.0),
    (333445555, 2, 10.0),
    (333445555, 3, 10.0),
    (333445555, 10, 10.0),
    (333445555, 20, 10.0),
    (999887777, 30, 30.0),
    (999887777, 10, 10.0),
    (987987987, 10, 35.0),
    (987987987, 30, 5.0),
    (987654321, 30, 20.0),
    (987654321, 20, 15.0),
    (888665555, 20, NULL);

SELECT *
FROM Works_On;


INSERT INTO Dependent
    (Essn,Dependent_name,Sex,Bdate,Relationship)
VALUES
    (333445555, 'Alice', 'F', '1976-04-05','Daughter'),
    (333445555, 'Theodore', 'M', '1973-10-25','Son'),
    (333445555, 'Joy', 'F', '1948-05-03','Spouse'),
    (987654321, 'Abner', 'M', '1932-02-29','Spouse'),
    (123456789, 'Michael', 'M', '1978-01-01','Son'),
    (123456789, 'Alice', 'F', '1978-12-31','Daughter'),
    (123456789, 'Elizabeth', 'F', '1957-05-05','Spouse');

SELECT *
FROM Dependent;


