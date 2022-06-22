class Database {
    static get(){
        if(localStorage.getItem("db") === null){
            localStorage.setItem("db",JSON.stringify([]))
        }
        if(!Database.instance){
            Database.instance = new Database();
        }
        return Database.instance;
    }
    getTable(name){
        const db = JSON.parse(localStorage.getItem("db")) || [];
        return db.find((n) => n.name === name);
    }
    createTable(name,columns,values){
        values.unshift(++id)
        const db = JSON.parse(localStorage.getItem("db")) || [];
        if(!db.find((n) => n.name === name)){
            db.push({name: name,columns: columns,values: values});
            localStorage.setItem("db",JSON.stringify(db));
            return new Table(name);
        }

    }
}
