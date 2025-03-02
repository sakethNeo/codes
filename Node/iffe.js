
// known as IIFE - making a function expression and calling it immediately

(function() {
    console.log("Hello, World!");
})();

// each module is loaded in IIFE


(function(message) {
    console.log(message,"sak");
})("hello");
 