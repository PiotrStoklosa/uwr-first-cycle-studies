select u.imie, u.nazwisko, w.data from grupa g, przedmiot_semestr ps, uzytkownik u, wybor w, semestr s, przedmiot p
where g.kod_grupy = w.kod_grupy and u.kod_uz = w.kod_uz and g.kod_przed_sem = ps.kod_przed_sem and ps.kod_przed = p.kod_przed and ps.semestr_id = s.semestr_id
and s.nazwa = 'Semestr zimowy 2017/2018' and p.nazwa = 'Matematyka dyskretna (M)' and g.rodzaj_zajec = 'w'
order by w.data limit 1;
