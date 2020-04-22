CREATE TABLE Instructor
(
    ID int,
    name varchar(15),
    dept_name varchar(15),
    salary int,
    PRIMARY KEY(ID)
);

CREATE TABLE Section
(
    course_id int,
    sec_id int,
    semester int,
    year int,
    building varchar(15),
    room_number int,
    time_slot_id int,
    PRIMARY KEY(course_id)
);

CREATE TABLE Teaches
(
    ID int,
    course_id int,
    sec_id int,
    semester int,
    year int,
    PRIMARY KEY(ID)
);