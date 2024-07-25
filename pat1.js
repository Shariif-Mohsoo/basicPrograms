console.log("First pattern: ");
let string = "";
for (let i = 1; i <= 5; i++) {
  for (let j = 1; j <= i; j++) {
    string += "*";
  }
  console.log(string);
  string = "";
}
//2nd pattern
console.log("Second pattern: ");
for (let i = 5; i >= 1; i--) {
  for (let j = 1; j <= i; j++) {
    string += "*";
  }
  console.log(string);
  string = "";
}
//write guess number program using while instead of using while loop
const target = Math.floor(Math.random() * 10 + 1);
let guess = Math.floor(Math.random() * 10 + 1);
var counter = 1;
for (; guess !== target; ) {
  console.log(`Guess: ${guess} --- Target: ${target}`);
  guess = Math.floor(Math.random() * 10 + 1);
  counter++;
}
console.log(`Guess: ${guess} --- Target: ${target}`);
if (counter > 0 && counter <= 3) {
  console.log("You Win Dear, Total tries: ", counter);
} else {
  console.log("You loose Dear, Total tries: ", counter);
}
