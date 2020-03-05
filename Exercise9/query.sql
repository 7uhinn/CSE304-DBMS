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
    psid int,
    psname varchar(15),
    color varchar(10),
    PRIMARY KEY(psid)
);

CREATE TABLE Catalog
(
    ssid int,
    psid int,
    cost real,
    PRIMARY KEY(ssid,psid)
);



DESCRIBE Suppliers;

DESCRIBE Parts;

DESCRIBE Catalog;



INSERT INTO Suppliers
    (sid,sname,address)
VALUES
    (1, 'Ramesh', 'Ahmedabad'),
    (2, 'Khilan', 'Delhi'),
    (3, 'kaushik', 'Kota'),
    (4, 'Chaitali', 'Mumbai'),
    (5, 'Hardik', 'Bhopal');

SELECT * from Suppliers;