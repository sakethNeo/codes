const fs = require("node:fs/promises");

// async is a keyword in js
async function readFile() {
    try {
        const data = await fs.readFile("Node/file.txt", "utf-8");
        // await used to asynchronously wait for a promise to resolve
        console.log(data);
    } catch(err) {
        console.log(err);
    }
}

readFile();