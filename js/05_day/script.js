const add = document.querySelector('#add');
const substract = document.querySelector('#substract');
const multiply = document.querySelector('#multiply');
const devide = document.querySelector('#devide');
const reset = document.querySelector('.reset');

function getResult(n) {
  const num1 = Number(document.querySelector("#firstInp").value);
  const num2 = Number(document.querySelector("#secondInp").value);
  const result = document.querySelector('.answer');
  if (num1 && num2 !== NaN) {
    let sum = 0
    switch(n){
        case '+':
         sum = num1 + num2;
         break;
        case '-':
            sum = num1 - num2;
            break;
        case '*':
            sum = num1 * num2;
            break;
        case '/':
            sum = num2 == 0 ? "Infinity ": num1 / num2
            break
         default:
            sum = "Error" ;
    }
    result.value = sum;
    return false;

  } else {
    alert("Enter Valid Number");
  }
}

function DeleteAll() {
    document.querySelector("#firstInp").value = 0;
    document.querySelector("#secondInp").value = 0;
    document.querySelector('.answer').value = 0;
}

add.addEventListener('click', () => {
    let mathIcon = () => document.querySelector(".input_panel p").innerHTML = '+';
    getResult(mathIcon());
});

substract.addEventListener('click', () => {
    let mathIcon = () => document.querySelector(".input_panel p").innerHTML = '-';
    getResult(mathIcon());
});

multiply.addEventListener('click', () => {
    let mathIcon = () => document.querySelector(".input_panel p").innerHTML = '*';
    getResult(mathIcon());
});

devide.addEventListener('click', () => {
    let mathIcon = () => document.querySelector(".input_panel p").innerHTML = '/';
    getResult(mathIcon());
});

reset.addEventListener('click', () => {
    DeleteAll()
});

document.addEventListener('keyup', function(event){
	if(event.key === "Escape"){
        DeleteAll()
	}
});
