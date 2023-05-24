select ps.semestr_id, Count(ps.kod_przed)
from przedmiot_semestr ps, przedmiot p
where ps.kod_przed = p.kod_przed
and p.rodzaj = 'o'
group by ps.semestr_id
order by Count(ps.kod_przed) DESC
limit 1;
