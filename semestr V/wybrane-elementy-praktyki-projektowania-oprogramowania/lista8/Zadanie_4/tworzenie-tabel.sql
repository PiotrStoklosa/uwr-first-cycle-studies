CREATE TABLE Miejsce_Pracy (
    id                  SERIAL PRIMARY KEY,
    nazwa               VARCHAR NOT NULL
);

CREATE TABLE Osoba (
    id                  SERIAL PRIMARY KEY,
    imie                VARCHAR NOT NULL,
    nazwisko            VARCHAR NOT NULL,
    plec                CHAR(1),
    id_miejsce_pracy    INTEGER REFERENCES Miejsce_Pracy (id)
);
