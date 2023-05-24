select nazwisko from uzytkownik u, przedmiot p, grupa g, semestr s, przedmiot_semestr ps
where u.kod_uz = g.kod_uz and g.kod_przed_sem = ps.kod_przed_sem and ps.semestr_id = s.semestr_id and ps.kod_przed = p.kod_przed
and p.nazwa = 'Matematyka dyskretna (M)' and g.rodzaj_zajec = 'c' and s.nazwa = 'Semestr zimowy 2017/2018'
