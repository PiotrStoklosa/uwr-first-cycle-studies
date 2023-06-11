import pgPromise from 'pg-promise';
const pgp = pgPromise({});

const databaseConfig = {
    host: 'localhost',
    database: 'weppo',
    user: 'postgres',
    password: 'postgres',
    port: 5432
}

const db = pgp(databaseConfig);

async function fetchOsoba() {
    console.log(await db.query('SELECT * from Osoba'))
};

async function fetchMiejsce_Pracy() {
    console.log(await db.query('SELECT * from Miejsce_Pracy'))
};

async function fetchPomocnicza_Tabela_Osoba_Miejsce_Pracy() {
    console.log(await db.query('SELECT * from Pomocnicza_Tabela_Osoba_Miejsce_Pracy'))
};

async function insertPerson(person) {
    return await db.one(
        `INSERT INTO Osoba (imie, nazwisko, plec)
         VALUES ($1, $2, $3) RETURNING id`,
        [person.name, person.surname, person.gender],
        res => res.id)
}

async function insertWorkplace(workplace) {
    return await db.one(
        'INSERT INTO Miejsce_Pracy (nazwa) VALUES ($1) RETURNING id',
        [workplace],
        res => res.id)
}

async function connectPersonWithWorkplace(idPerson, idWorkplace){
    await db.query(
        'INSERT INTO Pomocnicza_Tabela_Osoba_Miejsce_Pracy (id_Osoba, id_Miejsce_Pracy) VALUES ($1, $2)',
        [idPerson, idWorkplace])
}


(async function () {
    
    await db.connect()
    let p1 = await insertPerson({ 
        name: "Piotr",
        surname: "Stoklosa",
        gender: "M"
    });
    let p2 = await insertPerson({ 
        name: "a",
        surname: "b",
        gender: "K"
    });

    let w1 = await insertWorkplace("Szkola")
    let w2 = await insertWorkplace("Uniwersytet Wroclawski")

    await connectPersonWithWorkplace(p1, w1)
    await connectPersonWithWorkplace(p2, w1)
    await connectPersonWithWorkplace(p1, w2)
    await connectPersonWithWorkplace(p2, w2)

    await fetchOsoba()
    await fetchMiejsce_Pracy() 
    await fetchPomocnicza_Tabela_Osoba_Miejsce_Pracy()
    pgp.end()

})();