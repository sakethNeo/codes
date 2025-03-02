function greet(name) {
    console.log(`Hello ${name}`);
}

function higherOrderFuntion(callback) {
    const name = "Bheem";
    callback(name);
}

higherOrderFuntion(greet);

//  -> sync callback - immediate execution like above

/*
    -> async callback - callbacks are used to delay until a particular time occured  
    -> document.getElementById("btn").addEventListener("click", callback);
    -> callback function is called when the button is clicked
*/