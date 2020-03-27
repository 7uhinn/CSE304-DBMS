-- i
CREATE ASSERTION roomchaos check( 1 >= ALL(
SELECT COUNT(X.ID)
FROM (
    SELECT T.ID, S.semester, S.building, S.room_number, S.time_slot_id
    FROM Teaches as T LEFT OUTER JOIN Section as S
        ON T.course_id = S.course_id 
) as X
GROUP BY X.semester,X.building,X.room_number,X.time_slot_id));

-- ii
CREATE ASSERTION coursechaos check( 1 >= ALL(
SELECT COUNT(course_id)
FROM Teaches
GROUP BY ID,semester));