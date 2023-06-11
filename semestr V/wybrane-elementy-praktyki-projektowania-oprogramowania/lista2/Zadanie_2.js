// a)
let animals = {
    parrot: 'Bazyl',
    cat: 'Mruczek',
    dog: 'Azor'
}

console.log(animals.parrot);
console.log(animals["parrot"]);

// Dzięki operatorowi [] możemy dynamicznie odwoływać się do pól w obiekcie

// b)

animals[1] = 'Wiktor';
console.log(animals[1]);
// do obiektu animals zostanie dodane nowe pole '1'

let eat = {
    toString(){
        return "animalEating"
    }
}

animals[eat] = 'bread';
console.log(animals['animalEating']);
// W obiekcie animals zostanie stworzone pole 'animalEating', które ma przypisane wartość 'bread'

// Każdy klucz podany do obiektu będzie konwertowany na string, pod którym będzie znajdować się podana wartość

// c)

let arr = [1];

arr["string"] = "test";
console.log(arr);

// zostanie stworzone pole typu string, pod którym będzie znajdować się podana wartość

let value = {
    toString: function() {
        return "myValue";
    }
}

arr[value] = 2;
console.log(arr);
// podobnie jak wyżej stworzy się nam pole, o nazwie, która zostanie zwrócona z metody toString() czyli w tym wypadku "myValue"

arr['test']='cos'
console.log(arr); // zamiast odwołać się do elementu tablicy, zostanie stworzone nowe pole o wartości 'cos'

console.log(arr.length)
arr.length = 0;
console.log(arr)
console.log(arr.length)
arr.length = 2;
console.log(arr);
console.log(arr.length);
// atrybut length można ustawić na inną wartość niż liczba elementów.
// W przypadku zmiany na mniejszą wartość, tablica zostanie zmniejszona do podanej wartości.
// W przypadku zmiany na większą wartość, długość zostanie zwiększona, ale elementy nie zostaną dodane.