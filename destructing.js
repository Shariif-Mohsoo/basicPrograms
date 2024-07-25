/*
 * TODO:
        DESTRUCTING:
        BASICALLY AS FAR AS MY LITTLE KNOWLEDGE IS CONCERN
        IT IS THE SHORT,CLEAN AND ELEGANT WAY OF UNPACKING
        THE VALUE FROM ARRAY'S AND OBJECT'S INTO SINGLE 
        VARIABLE.
*/
//FIRST EXAMPLE FOR ARRAY
const array = ["Mohsin", "I", "Love", "Programming"];
//1st
const [arg1, arg2, arg3] = array;
console.log(arg1, arg2, arg3); //Mohsin I Love; will be output
//2nd using rest operator
const [Name, ...arg] = array;
console.log(Name, arg); //Mohsin ["I","Love","Programming"]
//3rd via skipping the index's
const [name, , , passion] = array;
console.log(name); //Mohsin
console.log(passion); //Programming
console.log(array); //entire array will be the output.
//SECOND EXAMPLE FOR OBJECT.
const Person = {
  firstName: "Muhammad",
  lastName: "Mohsin",
  age: 22,
};
//WE CAN DESTRUCTURE ITEMS FROM AN OBJECT ON THE BASIS OF KEY(MANDATORY).
const { first, last } = Person;
console.log(first, last); //undefined undefined
const { firstName, lastName } = Person;
console.log(firstName, lastName); //Muhammad Mohsin
//WE CAN ALSO CHANGE THE VARIABLES NAME.
const { firstName: First, lastName: Last } = Person;
console.log(First, Last); //Muhammad Mohsin
