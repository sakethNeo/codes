const PizzaShop = require("./pizza-shop");

const pizzaShop = new PizzaShop();

pizzaShop.on("order", (pizzaType)=>{
    console.log(`Order recieved a ${pizzaType}`);
});

pizzaShop.orderPizza("large")

