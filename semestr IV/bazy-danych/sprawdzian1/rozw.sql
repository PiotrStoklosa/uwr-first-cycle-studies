-- Piotr Stokłosa, pwi

-- Zadanie 1

SELECT c.name, COUNT(DISTINCT ii.island)
FROM country c 
LEFT JOIN geo_sea gs ON (gs.country = c.code)
LEFT JOIN Sea s ON (s.name = gs.sea)
LEFT JOIN islandIn ii ON (ii.sea = s.name)
GROUP BY c.name
ORDER BY COUNT(DISTINCT ii.island) DESC, c.name ASC;

-- Zadanie 2

SELECT countryTemp.name, eg.percentage polishpercentage
FROM
(
SELECT c.name
FROM Country c
JOIN EthnicGroup eg ON (c.code = eg.country)
WHERE c.code IN
(
SELECT c.code
FROM Country c
JOIN EthnicGroup eg ON (c.code = eg.country)
WHERE eg.name = 'Polish'
)
GROUP BY c.name
HAVING COUNT(DISTINCT eg.name) >= 10
) countryTemp
JOIN Country c ON (c.name = countryTemp.name)
JOIN EthnicGroup eg ON (c.code = eg.country)
WHERE eg.name = 'Polish';

-- Zadanie 3

-- Zadanie 4

SELECT DISTINCT co.name, FLOOR(SUM(ci.population) * 100 / co.population ) populationInCity
FROM Country co
JOIN City ci ON (co.code = ci.country)
GROUP BY co.name, co.population
HAVING co.population * 0.75 <= SUM(ci.population)
ORDER BY populationInCity DESC;


