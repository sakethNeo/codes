const EventEmitter = require("node:events");

class PizzaShop extends EventEmitter {
    constructor() {
        super();
        this.orderNumber = 0;
    }
    orderPizza(pizzaType) {
        this.orderNumber++;
        this.emit("order", pizzaType);
        console.log(`order number = ${this.orderNumber}`);
    }
}

module.exports = PizzaShop;