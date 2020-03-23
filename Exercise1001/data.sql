INSERT INTO Suppliers
    (sid,sname,address)
VALUES
    (1, 'Sarala', 'Bombay'),
    (2, 'Uma', 'Chennai'),
    (3, 'Nehru', 'Chennai'),
    (4, 'Priya', 'Bombay'),
    (5, 'Anand', 'Delhi');

SELECT *
FROM Suppliers;

INSERT INTO Parts
    (pid,pname,color)
VALUES
    (1, 'Nut', 'red'),
    (2, 'Bolt', 'green'),
    (3, 'Screw', 'blue'),
    (4, 'Screw', 'red'),
    (5, 'Cam', 'blue'),
    (6, 'Cog', 'red');

SELECT *
FROM Parts;

INSERT INTO Catalog
    (sid,pid,cost)
VALUES
    (1, 1, 300),
    (1, 2, 200),
    (1, 3, 400),
    (1, 4, 200),
    (1, 5, 100),
    (1, 6, 100),
    (2, 1, 300),
    (2, 2, 400),
    (3, 2, 400),
    (4, 2, 200),
    (4, 4, 300),
    (4, 5, 400);

SELECT *
FROM Catalog;
