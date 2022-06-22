class Table{
    tb = JSON.parse(localStorage.getItem("db"));

    constructor(name,column ,values)
    {
        this.name = name,
        this.column = column,
        this.values = values
    }

    add(id,username,password){
        const a =  this.tb.find((n) => n.values[0] === id)
        id = a.values[0]
        if(a){
            a.values.push([++id,username,password]) 
        }
        this.tb.values = a.values
        localStorage.setItem("db",JSON.stringify(this.tb))
    }

    update(id,username,password){
        const a =  this.tb.find((n) => n.values[0] === id)

        //can make this with splice() function too
        id = a.values[0]
        if(a){
            a.values = [id,username,password] 
        }
        this.tb.values = a.values
        localStorage.setItem("db",JSON.stringify(this.tb))
    }

    delete(id){
        const a =  this.tb.find((n) => n.values[0] === id)
        if(a)
        {
            a.values.splice(0,a.values.length)
        }
        this.tb.values = a.values
        localStorage.setItem("db",JSON.stringify(this.tb))
    }
    
    get(id){
        return this.tb.find((n) => n.values[0] === id);
    }
}
