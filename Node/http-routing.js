const http = require("node:http");
const fs = require("node:fs");

const server = http.createServer((req,res)=>{
    // res.end(req.url);
    if (req.url==="/") {
        res.writeHead(200, {"Content-Type":"text/plain"});
        res.end("Home page");
    } else if (req.url==="/about") {
        res.writeHead(200, {"Content-Type":"text/plain"});
        res.end("About page");
    } else {
        res.writeHead(200, {"Cotent-Type":"text/plain"});
        res.end("Random page");
    }
});

server.listen(3000, ()=>{
    console.log("LET'S GOO!!");
});