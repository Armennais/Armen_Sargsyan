import {createServer} from "http";
import fs from "fs";
import path from 'path';

const mimeType = {
    ".html": "text/html",
    ".css" : "text/css",
    ".js" : "text/javascript"
}


function fileMilddlewere(req,res,next){
    let url =  req.url;
    if(url === "/"){
        url = "/index.html";
    }

    const filePath = path.resolve("public"+url);
    fs.promises.access(filePath)
        .then(() => {
            const ext = path.extname(filePath);
            res.writeHead(200,{"Content-Type": mimeType[ext]})
            fs.createReadStream(filePath).pipe(res);
        })
        .catch(() => {
            next();
        })
}

const server =  createServer((req,res) => {
   fileMilddlewere(req,res,() => {
    
   });
});

server.listen(3001);