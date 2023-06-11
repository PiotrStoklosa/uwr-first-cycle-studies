function* fib() {
    var [a, b] = [0, 1]
    while (true) {
        yield a;
        [a, b] = [b, a + b]
    }
}

function* take(it, top) {
    for (let i = 0; i < top; i++) {
        let next = it.next();
        yield next.value
    }
}

for (let num of take( fib(), 10 )) {
    console.log(num);
}