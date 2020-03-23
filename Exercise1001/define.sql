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