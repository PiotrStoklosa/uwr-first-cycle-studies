function forEach( a, f ) {
    for(let x of a){
        f(x)
    }
}
function map( a, f ) {
    result = []
    for(let x of a){
        result.push(f(x))
    }
    return result
}
function filter( a, f ) {
    result = []
    for(let x of a){
        if (f(x)){
            result.push(x)
        }
    }
    return result
}
var a = [1,2,3,4];
forEach( a, _ => { console.log( _ ); } );
console.log(filter( a, _ => _ < 3 ));
console.log(map( a, _ => _ * 2 ));