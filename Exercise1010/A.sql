-- i
CREATE VIEW Manager
as
    SELECT D.Dname, E.Fname, E.Salary
    FROM Department as D, Employee as E
    WHERE D.Mgr_ssn = E.Ssn;

SELECT *
FROM Manager;


-- ii
CREATE VIEW Proj
as
    SELECT P.Pname, D.Dname, X.Number_of_employees, Y.Number_of_hours
    FROM(
    SELECT Pno, COUNT(Essn) as Number_of_employees
        FROM Works_On
        GROUP BY Pno
) as X,
        (
    SELECT Pno, SUM(Hours) as Number_of_hours
        FROM Works_On
        GROUP BY Pno
) as Y,
        Department as D, Project as P
    WHERE X.Pno = P.Pnumber and Y.Pno = X.Pno and P.Dnum = D.Dnumber;

SELECT *
FROM Proj;


-- iii
CREATE VIEW Dep as
SELECT *
FROM Department;

SELECT *
FROM Dep;