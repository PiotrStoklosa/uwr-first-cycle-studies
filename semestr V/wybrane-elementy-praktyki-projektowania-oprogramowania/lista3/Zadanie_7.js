function fib() {
    var [a, b] = [0, 1]
    return {
        next : function() {
            let val = a;
            [a, b] = [b, a + b];
            return {
                value : val,
                done  : false
            }
        }
    }
}

function* fibGen() {
    var [a, b] = [0, 1]
    while (true) {
        yield a;
        [a, b] = [b, a + b]
    }
}

var fibIterator = {
    [Symbol.iterator]: fib
}

// w tych przypadkach można się iterować za pomocą for-of
/*for (let f of fibIterator) {
    console.log(f)
}*/
/*for (let f of fibGen()) {
    console.log(f)
}*/

// tutaj niemożliwe
/*for (let f of fib()) {
    console.log(f)
}*/