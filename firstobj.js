//TODO: Creating the first object in js
const person = {
  firstName: "Muhammad",
  lastName: "Mohsin",
  age: 22,
  profession: "Anonymous",
};
const gender = "Male";
person.cast = "Rajpoot";
person["gender"] = gender;
//FIXME: using for in loop
for (let key in person) {
  console.log(`${key} --> ${person[key]}`);
}
