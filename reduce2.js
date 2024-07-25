/*
const arr = ["y", "n", "n", "y", "n"];
OUTPUT:
{
    y:2,
    n:3
};   
*/
const arr = ["y", "n", "n", "y", "n"];
let tally;
//***************TODO: BAD CODE
//  tally = arr.reduce(
//   (acc, cval) => {
//     if (cval === "y") acc.y++;
//     else acc.n++;
//     return acc;
//   },
//   { y: 0, n: 0 }
// );
//***************TODO: NORMAL
// tally = arr.reduce((acc, cval) => {
//   if (acc[cval]) acc[cval]++;
//   else acc[cval] = 1;
//   return acc;
// }, {});
//***************FIXME: GOOD CODE
tally = arr.reduce((acc, cval) => {
  acc[cval] = (acc[cval] || 0) + 1;
  return acc;
}, {});
console.log(tally);
