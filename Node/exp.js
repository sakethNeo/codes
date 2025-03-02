const fs = require("node:fs");

const readableStream = fs.createReadStream(__filename);
readableStream.close();
readableStream.on("close", ()=> console.log("from readableStream"));

setImmediate(()=> console.log("from setImmediate"));
setTimeout(()=> console.log("from timeout"), 0);
Promise.resolve().then(()=> console.log("from promise.resolve()"));
process.nextTick(()=> console.log("from process.nextTick()"));
