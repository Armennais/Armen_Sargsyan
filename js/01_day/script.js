// create variables
let productCount = [0,0,0,0,0]
let ProductName = ['Սնիկերս ','Կոլա','Ջերմուկ','Շոկոլադ','Կոնֆետ'];
let ProductPrice = [200,400,99.9,1200,350];
let Total = 0;
let paymant;

//Input all products count thats will buy
//And cound their total summary 
function imputCountAndTotalSum()
{
    for (let i = 0; i < 5; i++) {
        productCount[i] = parseInt(prompt("Enter " + ProductName[i] + " count"));
        Total += productCount[i] * ProductPrice[i];
    }
}
//call
imputCountAndTotalSum();

//this section for show total money,
//and check that money be true format
do{
    paymant = prompt("Դուք պետք է վճարեք " + Total +" դրամ");
    if (paymant < Total) {
        alert('Ձեր գումարը բավարար չէ գնումներ կատարելու համար');
    }
    if(isNaN(paymant)){
        alert('Սխալ գումարի մուտք') 
    }
}while(paymant < Total || isNaN(paymant));

//Print List of the shopping products
function printShopList(productCount,ProductName,ProductPrice){
    for (let i = 0; i < 5; i++) {
        if(productCount[i] != 0){
        console.log(ProductName[i]+" - " + productCount[i] +" հատ - "+ (productCount[i] * ProductPrice[i]) + "դր");       
        }
    }
}

//Print Final interface of SHOP
function printInConsole(paymant,Total) {
    console.log("Ընդամենը: " + paymant);
    console.log("Վերադարձ: " + (paymant - Total));
    console.log("Ծախս: " + Total);
    console.log("Ապրանքներ: " );
    //call printShopList
    if (!isNull(productCount)) {
        printShopList(productCount,ProductName,ProductPrice);
    }
} 

//check that products count is null or not
function isNull(productCount)
{
    let check = false;
    for (let i = 0; i < 5 ; i++) {
        if (productCount[i] != 0) {
            check = true;
            break;
        }
    }
    return check;
}
//call
if (isNull(productCount)) {
    alert("Դուք ոչինչ չեք գնել");
}

printInConsole(paymant,Total)