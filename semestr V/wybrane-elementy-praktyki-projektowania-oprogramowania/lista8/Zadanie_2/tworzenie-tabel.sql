CREATE TABLE Osoba (
    id       SERIAL PRIMARY KEY,
    imie     VARCHAR NOT NULL,
    nazwisko VARCHAR NOT NULL,
    plec     CHAR(1)
);
