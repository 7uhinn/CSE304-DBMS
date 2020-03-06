CREATE DATABASE ex9;

USE ex9;

CREATE TABLE Suppliers
(
    sid int,
    sname varchar(15),
    address varchar(30),
    PRIMARY KEY(sid)
);

CREATE TABLE Parts
(
    pid int,
    pname varchar(15),
    color varchar(10),
    PRIMARY KEY(pid)
);

CREATE TABLE Catalog
(
    sid int,
    pid int,
    cost real,
    PRIMARY KEY(sid,pid),
    FOREIGN KEY(sid) REFERENCES Suppliers(sid),
    FOREIGN KEY(pid) REFERENCES Parts(pid)
);


DESCRIBE Suppliers;

DESCRIBE Parts;

DESCRIBE Catalog;


INSERT INTO Suppliers
    (sid,sname,address)
VALUES
    (1, 'Ramesh', 'Ahmedabad'),
    (2, 'Khilan', 'Delhi'),
    (3, 'Kaushik', 'Chennai'),
    (4, 'Chaitali', 'Mumbai'),
    (5, 'Hardik', 'Bhopal');

SELECT *
FROM Suppliers;


INSERT INTO Parts
    (pid,pname,color)
VALUES
    (1, 'One', 'blue'),
    (2, 'Two', 'green'),
    (3, 'Three', 'red'),
    (4, 'Four', 'black'),
    (5, 'Five', 'red'),
    (6, 'Six', 'blue'),
    (7, 'Seven', 'green'),
    (8, 'Eight', 'red'),
    (9, 'Nine', 'black'),
    (10, 'Ten', 'red');

SELECT *
FROM Parts;

INSERT INTO Catalog
    (sid,pid,cost)
VALUES
    (1, 4, 200),
    (2, 3, 100),
    (3, 3, 100),
    (3, 5, 700),
    (4, 2, 900),
    (5, 1, 1100),
    (1, 8, 2000),
    (3, 8, 2000),
    (1, 10, 1200),
    (3, 10, 1200),
    (2, 7, 700),
    (4, 6, 500),
    (5, 9, 1400),
    (1, 3, 100),
    (1, 5, 700),
    (1, 2, 900),
    (1, 1, 1100),
    (1, 7, 700),
    (1, 6, 500),
    (1, 9, 1400);


SELECT *
FROM Catalog;

-- a
SELECT DISTINCT S.sname
FROM Suppliers as S, Parts as P, Catalog as C
WHERE P.pid = C.pid and P.color = 'red' and S.sid = C.sid;

-- b
SELECT DISTINCT S.sid
FROM Suppliers as S, Parts as P, Catalog as C
WHERE P.pid = C.pid and P.color = 'red' and S.sid = C.sid and S.address = 'Chennai';

-- c
SELECT AVG(cost)
FROM Parts as P, Catalog as C
WHERE P.pid = C.pid and P.color = 'red';

-- d
SELECT S.sname, max(X.SuppliersPartsCount) as SuppliersPartsCount
FROM(
    SELECT sid, COUNT(sid) as SuppliersPartsCount
    FROM Catalog
    GROUP BY sid) as X, Suppliers as S
WHERE S.sid = X.sid;

-- e
SELECT X.sid
FROM(
    SELECT sid, COUNT(sid) as SuppliersPartsCount
    FROM Catalog
    GROUP BY sid
) as X,
    (
    SELECT COUNT(DISTINCT pid) as PartsCount
    FROM Parts
) as Y
WHERE X.SuppliersPartsCount = Y.PartsCount;

-- f
SELECT X.sid
FROM(
    SELECT COUNT(DISTINCT pid) as RedPartsCount
    FROM Parts
    WHERE color = 'red'
) as Y,
    (
    SELECT M.sid, COUNT(sid) as SuppliersRedPartsCount
    FROM(
        SELECT C.sid
        FROM Catalog as C, Parts as P
        WHERE C.pid = P.pid and P.color = 'red'
    ) as M
    GROUP BY M.sid
) as X
WHERE X.SuppliersRedPartsCount = Y.RedPartsCount;

-- g


