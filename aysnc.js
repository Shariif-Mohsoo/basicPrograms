/*
    Let's explore little bit about the aysnc function.
    These are same like normal function but the diff. 
    is that they return the promise.That will be resolve.
*/
const add = async (x, y) => {
  return x + y;
};
// const addStrictly = async (x, y) => {
//   if (typeof x !== Number || typeof y !== Number)
//     throw "Those arguments must be number";
//   else return x + y;
// };
//using normal promises
const addStrictly = (x, y) => {
  const type = typeof 4;
  return new Promise((resolve, reject) => {
    if (typeof x !== type || typeof y !== type)
      reject("Both arguments must be numbers");
    else resolve(x + y);
  });
};
console.log(add(1, 2));
addStrictly(parseInt(3), parseInt(4))
  .then((res) => {
    console.log(res);
  })
  .catch((err) => {
    console.log(err);
  });
addStrictly(5, 4)
  .then((res) => {
    console.log(res);
  })
  .catch((err) => {
    console.log(err);
  });
