/*TODO: 
    LET'S EXPLORE LITTLE BIT ABOUT THE KEYWORD THIS IN JAVASCRIPT.
    THE KEYWORD (THIS) REFER TO THE CURRENT EXECUTION SCOPE. 
    ALSO WE WILL SEE LITTLE BIT MORE ABOUT DESTRUCTING.
*/
//TODO: EXAMPLE 1
function anonymous() {
  console.log(this); //this will refer to the window
}
//TODO: EXAMPLE 2
const func = () => {
  console.log(this); // this will also refer to window
};
//EXAMPLE 3 (THIS) KEYWORD IN OBJECTS.
const Person = {
  firstName: "Muhammad",
  lastName: "Mohsin",
  age: 22,
  getFullName() {
    const { firstName: first, lastName: last, age } = Person;
    return `${first} ${last}`;
  },
  printFullName: () => {
    //this will not worK because in case of arrow function this keyword will
    //always refer to the window object instead of current reference.
    console.log(this.getFullName());
  },
  getAge() {
    const { firstName: first, lastName: last, age } = Person;
    return age;
  },
  againPrintFullName() {
    console.log(this.getFullName());
  },
  printBio() {
    console.log(
      this.getFullName(),
      "AKA (Shariif-Rajpoot) is of age:",
      this.getAge(),
      "and he is persuing the CS Degree"
    );
  },
};
// Person.printFullName(); INVALID(ERROR WILL BE OCCUR IN VS CONSOLE)
Person.againPrintFullName(); //Muhammad Mohsin
Person.printBio(); //Muhammad Mohsin AKA (Shariif-Rajpoot) is of age:22
// and he is persuing the CS Degree.
