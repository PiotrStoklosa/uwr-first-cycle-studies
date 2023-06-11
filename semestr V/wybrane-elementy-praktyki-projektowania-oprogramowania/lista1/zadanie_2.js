for (let i = 1; i <= 100000; i++){

    let sumOfDigits = 0;
    let number = i;

    while(number)
    {
        let digit = number % 10;
        sumOfDigits += digit;

        if (i % digit != 0){
            break;
        }
        number = Math.floor(number / 10);
        if (number === 0 && number % sumOfDigits === 0){
            console.log(i);
        }
    }
    
}
