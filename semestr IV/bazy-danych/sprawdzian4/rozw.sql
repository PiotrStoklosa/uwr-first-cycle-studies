-- Piotr Stokłosa, pwi

-- Zadanie 1

SELECT DISTINCT o.name
FROM organization o
JOIN isMember im ON (o.abbreviation = im.organization)
JOIN borders b ON (im.country = b.country1)
JOIN politics p1 ON (b.country1 = p1.country)
JOIN politics p2 ON (p2.country = b.country2)
WHERE ABS(EXTRACT(YEAR FROM p1.independence) - EXTRACT(YEAR FROM p2.independence)) > 580
AND p2.country IN 
(
    SELECT country
    FROM isMember copy
    WHERE copy.organization = im.organization
);

-- Zadanie 2

CREATE TABLE city_log (id SERIAL NOT NULL, 
rodzaj varchar(6), 
id_uzytkownika name,
data timestamp, 
akc boolean DEFAULT true,
PRIMARY KEY(id));

-- Zadanie 3

CREATE OR REPLACE FUNCTION city_change() RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO city_log(rodzaj, id_uzytkownika, data)
    VALUES (TG_OP, current_user, current_timestamp);
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER city_insert AFTER INSERT ON city FOR EACH ROW EXECUTE PROCEDURE city_change();

CREATE TRIGGER city_delete AFTER DELETE ON city FOR EACH ROW EXECUTE PROCEDURE city_change();

CREATE TRIGGER city_update AFTER UPDATE ON city FOR EACH ROW EXECUTE PROCEDURE city_change();

-- Zadanie 4

CREATE OR REPLACE FUNCTION change_insert() RETURNS TRIGGER AS $$
BEGIN
IF  
(SELECT COUNT(temp.id_uzytkownika) FROM
    (SELECT * FROM city_log ORDER BY data DESC LIMIT 10) AS temp
    WHERE temp.id_uzytkownika = current_user) < 10
THEN
    INSERT INTO city_log(rodzaj, id_uzytkownika, data)
    VALUES ('INSERT', current_user, current_timestamp);
    RETURN NEW;
ELSE
    INSERT INTO city_log(rodzaj, id_uzytkownika, data)
    VALUES ('INSERT', current_user, current_timestamp, false);
    RETURN NULL;
END IF;
END
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION change_update() RETURNS TRIGGER AS $$
BEGIN
IF
(SELECT COUNT(temp.id_uzytkownika) FROM
    (SELECT * FROM city_log ORDER BY data DESC LIMIT 10) AS temp
    WHERE temp.id_uzytkownika = current_user) < 10
THEN
    INSERT INTO city_log(rodzaj, id_uzytkownika, data)
    VALUES ('UPDATE', current_user, current_timestamp);
    RETURN NEW;
ELSE
    INSERT INTO city_log(rodzaj, id_uzytkownika, data)
    VALUES ('UPDATE', current_user, current_timestamp, false);
    RETURN NULL;
END IF;
END
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION change_delete() RETURNS TRIGGER AS $$
BEGIN
IF
(SELECT COUNT(temp.id_uzytkownika) FROM
    (SELECT * FROM city_log ORDER BY data DESC LIMIT 10) AS temp
    WHERE temp.id_uzytkownika = current_user) < 10
THEN
    INSERT INTO city_log(rodzaj, id_uzytkownika, data)
    VALUES ('DELETE', current_user, current_timestamp);
    RETURN OLD;
ELSE
    INSERT INTO city_log(rodzaj, id_uzytkownika, data)
    VALUES ('DELETE', current_user, current_timestamp, false);
    RETURN NULL;
END IF;
END
$$ LANGUAGE plpgsql;

CREATE TRIGGER change2 BEFORE INSERT ON City FOR EACH ROW EXECUTE PROCEDURE change_insert();

CREATE TRIGGER change3 BEFORE UPDATE ON City FOR EACH ROW EXECUTE PROCEDURE change_update();

CREATE TRIGGER change1 BEFORE DELETE ON City FOR EACH ROW EXECUTE PROCEDURE change_delete();
