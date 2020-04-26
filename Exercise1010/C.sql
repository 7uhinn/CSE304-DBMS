-- transaction

delimiter //

START TRANSACTION;

INSERT INTO Department
    (Dname,Dnumber,Mgr_Ssn,Mgr_start_date)
VALUES
    ('LAPD', 9, 281198123, '1983-04-12');
    
INSERT INTO Employee
    (Fname,Minit,Lname,Ssn,Bdate,Address,Sex,Salary,Super_ssn,Dno)
VALUES
    ('Amy', 'B', 'Peralta', 12041999, '1956-01-09', '731 Baxton, Austin, TX', 'M', 40000, NULL, 2);

COMMIT;//

delimiter ;



