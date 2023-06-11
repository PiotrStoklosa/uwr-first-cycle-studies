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

async function fetch() {
    console.log(await db.query('SELECT * from Osoba'))
};

async function insert(person) {
    await db.query(
        `INSERT INTO Osoba (imie, nazwisko, plec) VALUES ($1, $2, $3)`,
        [person.name, person.surname, person.gender])
}


async function update(id, newName) { 
    db.query(`Update Osoba SET imie = $1 WHERE id = $2`, [newName, id])
};

async function deleteFromDB(id) {
    db.query(`DELETE FROM Osoba WHERE id = $1`, [id])
};

(async function () {
    await db.connect()
    await fetch() 

    await insert({ 
        name: "Piotr",
        surname: "Stoklosa",
        gender: "M"
    });
    await insert({ 
        name: "x",
        surname: "y",
        gender: "K"
    });
    await insert({ 
        name: "a",
        surname: "b",
        gender: "M"
    });
    await fetch() 
    await update(1,"newName")

    await fetch()
    await deleteFromDB(6)

    await fetch()

    pgp.end()
})();