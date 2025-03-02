const uppercase = require("upper-case").upperCase;

function greet(name) {
  console.log(uppercase(`Hello ${name}`));
}

greet("scooby Do");
module.exports = greet;
