const math = require("./math");

// const {add, sub} = math;

console.log(math.add(1,2),math.sub(2,1));


const cartoon = require("./caching.js");
// loaded and chached for sub sequent loading

console.log(cartoon.getName());

cartoon.setName("jackie chan");

const new_cartoon = require("./caching.js");
/* 
when you debug it doesn't go to the caching.js it stays in the 
index itself because the caching module is already loaded previously
*/
console.log(new_cartoon.getName());
