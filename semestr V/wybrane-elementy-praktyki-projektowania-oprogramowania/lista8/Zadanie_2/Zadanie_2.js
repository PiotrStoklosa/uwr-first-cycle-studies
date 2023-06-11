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

async function fetch() { // pobieranie
    console.log(await db.query('SELECT * from Osoba'))
};

async function insert(person) { // wstawianie
    console.log(await db.one(
        `INSERT INTO Osoba (imie, nazwisko, plec)
         VALUES ($1, $2, $3)
         RETURNING id`,
        [person.name, person.surname, person.gender], res => res.id))
}

(async function () {
    await db.connect()
    await fetch() 
    await insert({ 
        name: "Piotr",
        surname: "Stoklosa",
        gender: "M"
    })
    pgp.end()
})();