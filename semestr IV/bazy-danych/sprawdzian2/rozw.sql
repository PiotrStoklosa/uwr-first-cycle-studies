-- Piotr Stoklosa, pwi

-- Zadanie 1

CREATE VIEW SeaAirports
    (iatacode, name, city, province, country, sea)
AS
SELECT a.iatacode, a.name, c.name, a.province, a.country, s.name
FROM airport a 
JOIN located l ON (a.city = l.city AND a.country = l.country AND a.province = l.province)
JOIN sea s ON (l.sea = s.name)
JOIN city c ON (a.city = c.name AND a.province = c.province AND a.country = c.country)
WHERE c.elevation >= 200;

-- Zadanie 2

--1
ALTER TABLE city DROP CONSTRAINT pk_name;

--2
ALTER TABLE city ADD COLUMN id INTEGER;

ALTER TABLE city ADD CONSTRAINT pk_id
PRIMARY KEY(id);

--3
ALTER TABLE airports ADD COLUMN CityId (LIKE city.id)
 

-- Zadanie 3

INSERT INTO countrypops(country, year, population)
SELECT code, 2021, population
FROM country;

-- Zadanie 4

ALTER TABLE country ADD COLUMN popPeakCount INTEGER;
ALTER TABLE country ADD COLUMN popPeakYear INTEGER;

UPDATE country c SET popPeakCount = temp2.m, popPeakYear = temp2.year
FROM
(SELECT temp.country, m, year
FROM
(SELECT country, MAX(population) m
FROM countrypops
GROUP BY country) temp
JOIN countrypops ON (temp.country = countrypops.country AND temp.m = countrypops.population)) temp2
WHERE c.code=temp2.country;
