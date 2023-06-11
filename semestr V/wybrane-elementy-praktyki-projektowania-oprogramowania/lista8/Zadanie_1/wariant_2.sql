CREATE TABLE Osoba (
    -- Generujący się klucz
    id       SERIAL PRIMARY KEY,
    -- Imię i nazwisko różnej długości
    imie     VARCHAR NOT NULL,
    nazwisko VARCHAR NOT NULL,
    -- Jeden znak na płeć(K/M)
    plec     CHAR(1)
);

INSERT INTO Osoba (imie, nazwisko, plec)
    VALUES ('Piotr', 'Stoklosa', 'M');

INSERT INTO Osoba (imie, nazwisko, plec)
    VALUES ('Kasia', 'Kruk', 'K');

INSERT INTO Osoba (imie, nazwisko, plec)
    VALUES ('Milena', 'Szalik', 'K');
