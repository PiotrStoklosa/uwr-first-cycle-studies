let recursiveFibonacci = (n) => {
    if (n === 1 || n === 2)
        return 1;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

let iterativeFibonacci = (n) => {
    let t0 = 0;
    let t1 = 1;
    for (let i = 2; i <= n; i++){
        [t0, t1] = [t1, t1 + t0]
    }
    return t1;
}

let measureTimeRecursiveFibonacci = (n) => {
    console.log("I measure time for a recursive Fibonacci for a number " + n);
    console.time("recursiveTime");
    recursiveFibonacci(n);
    console.timeEnd("recursiveTime"); 
}

let measureTimeIterativeFibonacci = (n) => {
    console.log("I measure time for a iterative Fibonacci for a number " + n);
    console.time("iterativeTime");
    iterativeFibonacci(n);
    console.timeEnd("iterativeTime");
}

let N = 42;

for (let i = 10; i <= N; i++){
    measureTimeRecursiveFibonacci(i);
    measureTimeIterativeFibonacci(i);
}