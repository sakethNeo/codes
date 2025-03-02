const fs = require("node:fs");

const readableStream = fs.createReadStream("Node/file.txt",{
    encoding: "utf-8",
    highWaterMark: 2,
});

const writableStream = fs.createWriteStream("Node/file2.txt");

// *learn pipe chaining* //

// readableStream.pipe(writableStream);

readableStream.on("data", (chunk) => {
    console.log(chunk);
    writableStream.write(chunk);
});

// duplex streams - both read and write
// transform streams
