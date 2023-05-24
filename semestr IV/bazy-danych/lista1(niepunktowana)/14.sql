(SELECT kod_przed FROM przedmiot WHERE rodzaj='k')

EXCEPT

(SELECT kod_przed FROM przedmiot_semestr);
