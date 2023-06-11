function sum(){
  let sum = 0; 
  for(let x of arguments){
    sum += x
  }
  return sum;
}

console.log(sum(1,2,3));
console.log(sum(1,2,3,4,5));