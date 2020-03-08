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
    (1, 4, 250),
    (2, 3, 85),
    (3, 3, 105),
    (3, 5, 733),
    (4, 2, 912),
    (5, 1, 436),
    (1, 8, 2122),
    (3, 8, 1543),
    (1, 10, 1322),
    (3, 10, 1222),
    (2, 7, 2222),
    (4, 6, 599),
    (4, 9, 1423),
    (1, 3, 121),
    (1, 5, 699),
    (1, 2, 899),
    (1, 1, 1122),
    (1, 7, 783),
    (1, 6, 510),
    (1, 9, 1423);


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
SELECT X.color, COUNT(DISTINCT X.sid) as NumberOfSuppliers
FROM (
    SELECT P.color, C.sid
    FROM Parts as P, Catalog as C
    WHERE P.pid = C.pid
) as X
GROUP BY X.color;

-- h
SELECT C.pid, C.sid, C.cost
FROM(
    SELECT pid, MIN(cost) as MinCost
    FROM Catalog
    GROUP BY pid
) as X,
    (
    SELECT pid
    FROM Parts
    WHERE color = 'red'
) as Y, Catalog as C
WHERE X.pid = Y.pid and C.cost = X.MinCost and Y.pid = C.pid
ORDER BY C.pid;

-- i
SELECT C.pid, C.sid, C.cost
FROM(
    SELECT pid, MIN(cost) as MinCost
    FROM Catalog
    GROUP BY pid
) as X, Catalog as C
WHERE C.cost = X.MinCost
ORDER BY C.pid;

-- j
SELECT S.sname, X.NumberOfParts
FROM(
    SELECT C.sid, COUNT(C.sid) as NumberOfParts
    FROM Catalog as C
    GROUP BY C.sid
) as X, Suppliers as S
WHERE S.sid = X.sid
ORDER BY X.NumberOfParts;

-- k
SELECT S.sname, S.sid, X.MaxCost
FROM (
    SELECT MAX(cost) as MaxCost
    FROM Catalog
) as X, Suppliers as S, Catalog as C
WHERE S.sid = C.sid and C.cost = X.MaxCost;

-- l
SELECT S.sname, X.NumberOfParts
FROM(
    SELECT C.sid, COUNT(C.sid) as NumberOfParts
    FROM Catalog as C
    GROUP BY C.sid
) as X, Suppliers as S
WHERE S.sid = X.sid and X.NumberOfParts > 1
ORDER BY X.NumberOfParts;
