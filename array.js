//TODO:  Let's apply bubble sort
const prompt = require("prompt-sync")({ sigint: true });
let num = prompt("Enter Number: ");
console.log(num);

const arr = [3, 2, 7];
let isTrue;
console.log(arr);
for (let i = 0; i < arr.length - 1; i++) {
  isTrue = false;
  for (let j = 0; j < arr.length - 1 - i; j++) {
    if (arr[j] > arr[j + 1]) {
      [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
      isTrue = true;
    }
    if (isTrue === false) break;
  }
}
console.log("Sorted Array: ", arr);
