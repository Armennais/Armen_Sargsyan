import express from "express";

const app = express()


app.use(express.static("public"))
app.use(express.json());
app.get("/",(req,res) => {
    req.redirect("index.html")
})
app.get("/hello",(req,res) => {
    res.send("AYO");
})

app.get("/bye",(req,res) => {
    res.send({
        name:"Armen"
    });
})

app.post('/hi', (req, res) => {
        console.log(req.body.name)
        res.send("IT's okay")

});
app.listen(3002)
