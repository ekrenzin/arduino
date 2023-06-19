const fs = require('fs');
const https = require('https');
const express = require('express');
const app = express();
const port = 3000;

const options = {
  key: fs.readFileSync('server.key'),
  cert: fs.readFileSync('server.cert')
};

let counter = 0

app.get('/', (req, res) => 
{
    console.log("INCOMING REQ", Date.now());
    counter++;
    console.log("counter", counter);
    res.send('Hello World!');
});

https.createServer(options, app).listen(port, () => console.log(`Example app listening on port ${port}!`));
