CREATE VIEW SalaryView
as
    SELECT X.Ssn, X.Salary, X.Dno, Y.Dname, X.Mgr_ssn
    FROM(
SELECT E.Ssn, E.Salary, E.Dno, D.Mgr_ssn
        FROM Employee as E LEFT OUTER JOIN Department as D
            ON E.Ssn = D.Mgr_ssn) as X,
        Department as Y
    WHERE X.Dno = Y.Dnumber;

SELECT *
FROM SalaryView;


-- i
SELECT AVG(Salary) as avg_salary
FROM SalaryView;


-- ii
SELECT AVG(Salary) as avg_manager_salary
FROM SalaryView
WHERE Mgr_ssn is not NULL;


-- iii
SELECT Dname, AVG(Salary) as avg_departmental_salary
FROM SalaryView
GROUP BY (Dname);


-- iv
SELECT Dname, MAX(X.total_departmental_salary) as max_departmental_salary
FROM (
    SELECT Dname, SUM(Salary) as total_departmental_salary
    FROM SalaryView
    GROUP BY (Dname)
) as X;

