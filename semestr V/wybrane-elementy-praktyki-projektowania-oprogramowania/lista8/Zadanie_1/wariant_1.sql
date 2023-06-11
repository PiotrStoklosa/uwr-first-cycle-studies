CREATE TABLE Osoba (
    id       INTEGER PRIMARY KEY NOT NULL,
    -- Imię i nazwisko różnej długości
    imie     VARCHAR NOT NULL,
    nazwisko VARCHAR NOT NULL,
    -- Jeden znak na płeć(K/M)
    plec     CHAR(1)
);

CREATE SEQUENCE osoba_id_sequence
    AS INT
    START WITH 1
    INCREMENT BY 1;

INSERT INTO Osoba
    VALUES (nextval('osoba_id_sequence'), 'Piotr', 'Stoklosa', 'M');