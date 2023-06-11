CREATE TABLE Miejsce_Pracy (
    id                  SERIAL PRIMARY KEY,
    nazwa               VARCHAR NOT NULL
);

CREATE TABLE Osoba (
    id                  SERIAL PRIMARY KEY,
    imie                VARCHAR NOT NULL,
    nazwisko            VARCHAR NOT NULL,
    plec                CHAR(1)
);


CREATE TABLE Pomocnicza_Tabela_Osoba_Miejsce_Pracy (
    id_Osoba INTEGER NOT NULL REFERENCES Osoba (id),
    id_Miejsce_Pracy INTEGER NOT NULL REFERENCES Miejsce_Pracy (id)
);
