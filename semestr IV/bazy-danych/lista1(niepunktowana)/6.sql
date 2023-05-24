select distinct p.nazwa from przedmiot p, przedmiot_semestr ps, grupa g, uzytkownik u
where u.semestr = '0' and u.nazwisko = 'Urban'
and p.kod_przed = ps.kod_przed and ps.kod_przed_sem = g.kod_przed_sem and g.kod_uz = u.kod_uz order by p.nazwa;
