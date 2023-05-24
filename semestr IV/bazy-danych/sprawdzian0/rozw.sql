-- Piotr Stokłosa, pwi

-- Zadanie 1

SELECT DISTINCT ci.name, ci.country, ci.province, ci.population, ci.latitude, ci.longitude, ci.elevation
FROM City ci
JOIN Country co ON (ci.country = co.code)
JOIN Airport a ON (ci.name = a.city)
WHERE ci.elevation < 100 AND co.name = 'Poland'
ORDER BY ci.name;

-- Zadanie 2

SELECT DISTINCT s.name, s.area
FROM SEA s
JOIN River r ON (s.name = r.sea)
JOIN geo_river gr ON (r.name = gr.river)
JOIN Country c ON (c.code = gr.country)
WHERE r.length > 800 AND c.name = 'France'
ORDER BY s.area DESC;
