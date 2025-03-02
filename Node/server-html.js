const http = require("node:http");
const fs = require("node:fs");

const server = http.createServer((req,res)=>{
    res.writeHead(200, {"Content-Type": "text/html"});
    // fs.createReadStream(__dirname + "/index.html").pipe(res);
    const name = "ne0";
    let html = fs.readFileSync("Node/index.html","utf-8");
    html = html.replace("{{name}}",name);
    res.end(html);
});

server.listen(3000, ()=>{
    console.log("server running!");
}); 
