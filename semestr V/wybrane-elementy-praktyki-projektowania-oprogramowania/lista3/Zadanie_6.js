function createGenerator(n) {
    return function () {
        var _state = 0;
        return {
            next: function () {
                return {
                    value: _state,
                    done:  _state++ >= n
                }
            }
        }
    }
}

var foo1 = {
    [Symbol.iterator]: createGenerator(5)
};

var foo2 = {
    [Symbol.iterator]: createGenerator(10)
}

for (var x of foo1) {
    console.log(x);
}

for (var x of foo2) {
    console.log(x);
}
