/*
FIXME:
REDUCE ARRAY METHOD WITH SIMPLE EXAMPLE
TODO: BASIC INFO RELATED TO REDUCE WORKING.
==> REDUCE IS AN ARRAY BUILD IN METHOD 
THAT EXECUTES THE REDUCER CALLBACK ON
EACH ELEMENT OF AN ARRAY,
RESULTING IN SINGLE VALUE. 
==> Reduces receives the two parameters
(which fullfil our need) 
one accumulator,second current value 
and as per the required condition it
will result in the single value.
*/
const array = [32, 23, 4, 1, 2];
const sum = array.reduce((accumulator, currentVal) => accumulator + currentVal);
console.log(sum);
/*
TODO: DRY RUN:
    Callback        accumulator     currentVal
    i)                  32              23    
    ii)                 55               4    
    iii)                59               1    
    iv)                 60               2    
FIXME:
        sum = 64 //will be the output.
*/
const mul = array.reduce((accumulator, cVal) => {
  return accumulator * cVal;
});
console.log(mul);
const diff = array.reduce(function (acc, currentVal) {
  return acc - currentVal;
});
console.log(diff);
