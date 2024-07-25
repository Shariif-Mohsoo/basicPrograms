const person = {
  firstName: "Muhammad",
  lastName: "Mohsin",
  age: 21,
};
const arr = [{ ...person }, { ...person }];
function display() {
  const item = [...arguments];
  //TODO: ARGUMENTS OBJECT DON'T WORK IN ARROW FUNCTION.
  item.forEach((item) => console.log(item));
}
const Display = (arg, ...rest) => {
  console.log(arg);
  console.log(rest);
};
// display(person, person);
// display(arr);
Display(arr, person);
