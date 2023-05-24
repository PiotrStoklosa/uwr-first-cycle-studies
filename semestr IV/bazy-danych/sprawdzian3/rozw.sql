-- Piotr Stokłosa, pwi

-- Zadanie 1

-- Zmienną zapamiętuję w osobnej tabeli, testuję poprzez wywołanie Select sea_level(-zmienna-). Np. przetestowałem Select sea_level(50) i po wpisaniu Select * from City nie znalazłem miasta na wysokości poniżej 50m.

CREATE TABLE sunken_city (LIKE city);
ALTER TABLE sunken_city ADD COLUMN sinking_date date;

CREATE TABLE lastlevel(lev int);
INSERT INTO lastlevel VALUES(0);

CREATE OR REPLACE FUNCTION sea_level(level int)
RETURNS VOID AS
$X$

DECLARE

    m city; 
    l character varying(3);
    
BEGIN

UPDATE lastlevel
SET lev = level; 

FOR l IN
(
    SELECT airport.iatacode
    FROM airport
    WHERE elevation < level
)
LOOP
    DELETE FROM airport
    WHERE airport.iatacode = l;
END LOOP;

FOR m IN
(
    SELECT *
    FROM city
    WHERE elevation < level
)
LOOP
    INSERT INTO sunken_city
    VALUES (m.*, current_timestamp);
    
    UPDATE airport
    SET city = null
    WHERE city = m.name AND country = m.country AND province = m.province;
    
    DELETE FROM city
    WHERE city.name = m.name AND city.country = m.country AND city.province = m.province;
    
END LOOP;

END
$X$ LANGUAGE plpgsql;

-- Zadanie 2

-- Należy zdefiniować wyzwalacz, który przed każdym dodaniem krotki do miasta wywołuje funkcję. Zadaniem tej funkcji jest sprawdzenie czy miasto, które ma właśnie zostać dodane leży poniżej czy powyżej poziomu określonego w tabeli lastlevel. Jeżeli leży poniżej powinien zamiast dodawać do City dodawać to miasto do sunken_city. W przeciwnym wypadku pozwolić na dodanie normalne tego miasta do tabeli City.


CREATE OR REPLACE FUNCTION city_test()
RETURNS TRIGGER AS
$X$

BEGIN

    IF (NEW.elevation < (SELECT lev FROM lastlevel))
    THEN
        INSERT INTO sunken_city
        SELECT city.*, current_timestamp
        FROM city
        WHERE city.name = NEW.name AND city.province = NEW.province AND city.country = NEW.country;
        
        return NULL;
        
    END IF;
    
    RETURN NEW;
END
$X$ LANGUAGE plpgsql;

CREATE TRIGGER insert_to_city BEFORE 
INSERT ON city
FOR EACH ROW EXECUTE PROCEDURE city_test();


