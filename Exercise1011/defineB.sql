CREATE TABLE PC
(
    model int,
    speed int,
    ram int,
    hd int,
    price int,
    PRIMARY KEY(model)
);

CREATE TABLE Laptop
(
    model int,
    speed int,
    ram int,
    hd int,
    screen int,
    price int,
    PRIMARY KEY(model)
);

CREATE TABLE Printer
(
    model varchar(10) not null,
    color varchar(10),
    type int,
    price int,
    PRIMARY KEY(type)
);