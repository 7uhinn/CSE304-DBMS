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
