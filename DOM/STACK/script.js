// const multiply = (x, y) => {
//   return x * y;
// };
// const square = (x) => {
//   return multiply(x, x);
// };
// const isRightTriangle = (x, y, z) => {
//   return square(x) + square(y) === square(z);
// };
// isRightTriangle(3, 4, 5);
// console.log(isRightTriangle(3, 4, 5));

//hello
//HELLO !!!
//repeat 4 times
//append in container
const repeat = (txt) => {
  let text = "";
  for (let i = 1; i <= 4; i++) {
    text += txt;
    text += " ";
  }
  return text;
};
const streaming = (text) => {
  const newText = text.toUpperCase() + "!!!";
  return repeat(newText);
};
const display = (txt, ele) => {
  const text = streaming(txt);
  const h1 = document.createElement("h1");
  h1.innerText = text;
  ele.appendChild(h1);
};
display("Mohsoo", document.body.querySelector(".container"));
