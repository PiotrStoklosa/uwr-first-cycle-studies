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

async function insertPerson(person) {
    await db.query(
        `INSERT INTO Osoba (imie, nazwisko, plec, id_miejsce_pracy)
         VALUES ($1, $2, $3, $4)`,
        [person.name, person.surname, person.gender, person.workplace_id])
}

async function insertWorkplace(workplace) {
    return (await db.one(
        'INSERT INTO Miejsce_Pracy (nazwa) VALUES ($1) RETURNING id',
        [workplace],
        res => res.id
    ))
}

async function insertPersonAndWorkplace(person, workplace) {
    if ((await db.query(
        `SELECT COUNT(*) from Miejsce_Pracy where Miejsce_Pracy.nazwa = $1`,
     [workplace]))[0].count > 0)
     
        person.workplace_id = (await db.query(
            `SELECT Miejsce_Pracy.id from Miejsce_Pracy where Miejsce_Pracy.nazwa = $1`,
         [workplace]))[0].id
    else
        person.workplace_id = await insertWorkplace(workplace)
    console.log(person.workplace_id)
    await insertPerson(person)
}


(async function () {
    
    await db.connect()
    await insertPersonAndWorkplace({ 
        name: "Piotr",
        surname: "Stoklosa",
        gender: "M"
    }, "Uniwersytet Wroclawski");

    await fetchOsoba() 
    await fetchMiejsce_Pracy() 
    pgp.end()
})();