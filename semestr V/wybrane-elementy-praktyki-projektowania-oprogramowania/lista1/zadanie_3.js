let sieve  = [];
let N = 100000;

for (let i = 2; i <= Math.sqrt(N); i++)
    if (!sieve[i])
        for (let j = i * i; j <= N; j += i)
            sieve[j] = true;

for (let i = 2; i <= N; i++)
    if (!sieve[i])
        console.log(i);
