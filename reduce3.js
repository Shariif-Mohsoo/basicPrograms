//FIXME: reduce practice
const arr = [4, 1, 23, 32, 10, 43];
let test;
test = arr.reduce((accumulator, currVal) => Math.max(accumulator, currVal));
console.log(`Maximum: ${test}`);
test = arr.reduce((accumulator, currVal) => Math.min(accumulator, currVal));
console.log(`Minimum: ${test}`);
/*
    TODO: DRY RUN FOR FIRST CODE
    Callback    accumulator     currentVal    return value
    i)              4              1              4
    ii)             4              23             23
    iii)            23             32             32
    iv)             32             10             32
    v)              32             43             43
    test = 43

    TODO: DRY RUN FOR SECOND CODE
    Callback    accumulator     currentVal    return value
    i)              4              1              1
    ii)             1              23             1
    iii)            1             32              1
    iv)             1             10              1
    v)              1             43              1
    test = 1
*/
