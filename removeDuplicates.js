//check whether the number is prime or not
const arr = [2, 3, 4, 5, 2, 1, 3, 1, 3, 10, 43, 3, 2, 6];
console.log("Original Array");
console.log(arr);
const checkPrime = (ele) => {
  let counter = 0;
  for (let i = 2; i <= ele; i++) {
    if (ele % i === 0) {
      counter++;
    }
  }
  if (counter === 1) return ele;
};
let prime = arr.filter(checkPrime);
console.log("Prime numbers in an array");
console.log(prime);

//remove duplicates
console.log("Removing the duplicates elements in an array");
let flag = true;
let num = 2; //number of which remove duplicates
for (let i = 0; i < arr.length; i++) {
  if (flag) {
    if (arr[i] === num) {
      flag = false;
      continue;
    }
  }
  if (arr[i] === num) {
    for (let k = i; k < arr.length; k++) {
      arr[k] = arr[k + 1];
    }
    arr.length--;
  }
}
console.log(arr);
console.log("All the duplicates are removed");
//rechecking the array
// prime = arr.filter(checkPrime);
// console.log(prime);
