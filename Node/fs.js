const fs = require("node:fs");

console.log("first");

const fileCn = fs.readFileSync("Node/file.txt","utf-8");
console.log(fileCn);

console.log("second");

fs.readFile("Node/file.txt","utf-8",(err,data)  => {
    if(err) {
        console.log(err);
    } else {
        console.log(data);
    }
});

console.log("third");

fs.writeFileSync("Node/spell.txt","Lumos");

fs.writeFile("Node/spell.txt"," Expeliarmus",{flag :"a"}, (err) => {
    if(err) console.log(err);
    else console.log("done");
});
