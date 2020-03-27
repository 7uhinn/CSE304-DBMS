CREATE TABLE PC
(
    model varchar(10),
    speed int,
    ram int,
    hd int,
    price int,
    PRIMARY KEY(model)
);

CREATE TABLE Laptop
(
    model varchar(10),
    speed int,
    ram int,
    hd int,
    screen int,
    price int,
    PRIMARY KEY(model)
);

CREATE TABLE Printer
(
    model varchar(10),
    color varchar(10),
    type int,
    price int,
    PRIMARY KEY(model)
);