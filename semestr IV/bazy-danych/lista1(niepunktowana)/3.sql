select w.kod_uz from grupa g, przedmiot_semestr ps, uzytkownik u, wybor w, semestr s, przedmiot p
where g.kod_grupy = w.kod_grupy and u.kod_uz = w.kod_uz and g.kod_przed_sem = ps.kod_przed_sem and ps.kod_przed = p.kod_przed and ps.semestr_id = s.semestr_id
and s.nazwa = 'Semestr zimowy 2017/2018' and p.nazwa = 'Matematyka dyskretna (M)' and g.rodzaj_zajec = 'w'
order by w.data asc limit 1
-
select w.kod_uz from grupa g, przedmiot_semestr ps, uzytkownik u, wybor w, semestr s, przedmiot p
where g.kod_grupy = w.kod_grupy and u.kod_uz = w.kod_uz and g.kod_przed_sem = ps.kod_przed_sem and ps.kod_przed = p.kod_przed and ps.semestr_id = s.semestr_id
and s.nazwa = 'Semestr zimowy 2017/2018' and p.nazwa = 'Matematyka dyskretna (M)' and g.rodzaj_zajec = 'w'
order by w.data limit 1

select w1.data from wybor w1 
where w1.kod_grupy = w2.kod_grupy and w1.kod_uz = 3722 and w2.kod_uz = 3380;

select w.kod_uz from grupa g, przedmiot_semestr ps, uzytkownik u, wybor w, semestr s, przedmiot p
where g.kod_grupy = w.kod_grupy and u.kod_uz = w.kod_uz and g.kod_przed_sem = ps.kod_przed_sem and ps.kod_przed = p.kod_przed and ps.semestr_id = s.semestr_id
and s.nazwa = 'Semestr zimowy 2017/2018' and p.nazwa = 'Matematyka dyskretna (M)' and g.rodzaj_zajec = 'w'
order by w.data limit 1
