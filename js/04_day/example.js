const db = Database.get();
let id = 0;
db.createTable("user",["username","password"],[["Armen1","asd"]]);
db.createTable("user1",["username","password"],["Karen","asdfgd"]);
db.createTable("user2",["username","password"],["Vazgen","aghsdfgd"]);

const a = new Table();
a.add(1,"Vazgenchik","aedaef");
a.update(1,"Gagik","aedefa");
a.delete(2);


