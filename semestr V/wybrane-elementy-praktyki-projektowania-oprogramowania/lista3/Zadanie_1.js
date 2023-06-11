
let animal = {
    name: "dog",

    say: function(){
        return "hau";
    },
    get name(){
        return this.name;
    },

    set name(name)
    {
        animal.name = name;
    }
}

// Pola oraz metody mogą być dodawane używając Object.defineProperty (ale nie muszą)

animal['tail'] = true

animal.eat = function() {
    return "animal eating";
}

// Właściwości muszą być dodawane używając Object.defineProperty

Object.defineProperty(animal, 'owner', {
    get : function() {
        return owner
    },

    set : function(o) {
        owner = o
    }
})

animal.owner = "John"
console.log(animal.owner)