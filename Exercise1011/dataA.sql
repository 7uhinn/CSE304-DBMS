INSERT INTO Instructor
    (ID, name, dept_name, salary)
VALUES
    (1, 'A', 'CSE', 50000),
    (2, 'B', 'CSE', 40000),
    (3, 'C', 'ECE', 35000),
    (4, 'D', 'MECH', 15000);

SELECT *
FROM Instructor;

INSERT INTO Section
    (course_id, sec_id, semester, year, building, room_number, time_slot_id)
VALUES
    (1, 1, 1, 1998, 'B1', 1, 1),
    (2, 2, 2, 1998, 'B2', 2, 2),
    (3, 3, 3, 1998, 'B3', 3, 3),
    (4, 4, 4, 1998, 'B4', 4, 4);

SELECT *
FROM Section;

INSERT INTO Teaches
    (ID, course_id, sec_id, semester, year)
VALUES
    (1, 1, 1, 1, 1998),
    (2, 2, 2, 2, 1998),
    (3, 3, 3, 3, 1998),
    (4, 4, 4, 4, 1998);

SELECT *
FROM Teaches;