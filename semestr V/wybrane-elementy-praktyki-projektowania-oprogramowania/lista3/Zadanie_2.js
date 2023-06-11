let previousFib = (n) => {
    if (n === 1 || n === 2)
        return 1;
    return previousFib(n - 1) + previousFib(n - 2);
}


function fib(n) { 
 
    if ( n > 2 ) { 
        return fib(n-1) + fib(n-2)
    }
    return 1; 
}

function memo(f) { 
 
    var cache = {}; 
 
    return function(n) { 
 
        if ( cache[n] === undefined ) { 
            var result = f(n); 
            cache[n] = result; 
            return result; 
           
        } else { 
            return cache[n] 
        } 
 
    } 
} 
let measureTimePreviousFib = (n) => {
    console.log("I measure time for a previous implementation Fibonacci for a number " + n);
    console.time("recursiveTime");
    previousFib(n);
    console.timeEnd("recursiveTime"); 
}

let measureTimeFibonacciWithMemoisation = (n) => {
    console.log("I measure time for a Fibonacci with memoisation for a number " + n);
    console.time("memoisationTime");
    fib(n);
    console.timeEnd("memoisationTime");
}
 
var fib = memo(fib); 

measureTimePreviousFib(41); 

measureTimeFibonacciWithMemoisation(41);
