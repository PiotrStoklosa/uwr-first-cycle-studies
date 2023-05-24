(select distinct CAST(w.data as date) from wybor w, grupa g, przedmiot_semestr ps, semestr s
where s.nazwa = 'Semestr zimowy 2016/2017'
and s.semestr_id = ps.semestr_id and ps.kod_przed_sem = g.kod_przed_sem and g.kod_grupy = w.kod_grupy
order by CAST(w.data as date)
limit 1)
UNION
(select distinct CAST(w.data as date) from wybor w, grupa g, przedmiot_semestr ps, semestr s
where s.nazwa = 'Semestr zimowy 2016/2017'
and s.semestr_id = ps.semestr_id and ps.kod_przed_sem = g.kod_przed_sem and g.kod_grupy = w.kod_grupy
order by CAST(w.data as date) DESC
limit 1);
