delimiter //

create trigger PCPrice
before update on PC
for each row 
begin
if new.price > old.price then
	if new.speed = old.speed then	
		signal sqlstate '45000'
        set message_text = 'Price is higher when speed is equal.';
	end if;
end if;
end;//

delimiter ;

update PC
set price = 200, speed = 10
where model = 101;

update PC
set price = 90, speed = 10
where model = 101;

delimiter //

create trigger PrinterModel
before insert on Printer
for each row
begin
if new.model = '' then
	signal sqlstate '45000'
	set message_text = 'Printer Model cannot be null';
    set new.model = null;
end if;
end;//

delimiter ;
    
insert into Printer
	(model,color,type,price)
values
	('','red',1,100);
    
insert into Printer
	(model,color,type,price)
values
	('ABC','red',1,100);
    
delimiter //

create trigger AvgLaptopPrice
before update on Laptop
for each row
begin
set @avg = (select avg(price) from Laptop);
if @avg < 1500 then
	signal sqlstate '45000'
	set message_text = 'Modification disallowed as average laptop price is less than 1500.';
end if;
end;//

delimiter ;

update Laptop
set price = 200
where model = 101;