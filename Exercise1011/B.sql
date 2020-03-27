CREATE TRIGGER PCprice
AFTER UPDATE of price on PC
REFERENCING 
OLD TABLE as ot
NEW TABLE as nt
FOR EACH ROW
WHEN (nt.price>(
    SELECT price
    FROM ot
    WHERE nt.speed = ot.speed
))
UPDATE PC
SET price = ot.price
WHERE model = nt.model;