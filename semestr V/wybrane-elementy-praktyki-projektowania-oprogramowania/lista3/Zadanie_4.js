function createFs(n) { // tworzy tablicę n funkcji
    var fs = []; // i-ta funkcja z tablicy ma zwrócić i
    for ( var i=0; i<n; i++ ) {
        fs[i] = function(x) {
            return function () {
                return x;
            }
        }(i);
    };
    return fs;
}
var myfs = createFs(10);
console.log( myfs[0]() );
console.log( myfs[2]() );
console.log( myfs[7]() );

//Zastąpienie var słowem let zmienia zasięg zmiennej z funkcyjnego do blokowego, dzięki czemu funkcje ukryte pod tablicą zwracają kolejne wartości, a nie wartość ostatniej wartości zmiennej i
