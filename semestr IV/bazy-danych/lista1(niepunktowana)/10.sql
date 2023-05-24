select Count(g.kod_grupy) from grupa g, przedmiot_semestr ps, semestr s, przedmiot p
where s.nazwa = 'Semestr zimowy 2017/2018' and p.nazwa = 'Logika dla informatyków' and g.rodzaj_zajec IN ('c', 'C')
and g.kod_przed_sem = ps.kod_przed_sem and ps.semestr_id = s.semestr_id and ps.kod_przed = p.kod_przed;
