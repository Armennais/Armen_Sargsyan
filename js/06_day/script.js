const randomNumber = Math.floor(Math.random() * 100) + 1;
console.log(randomNumber);
const winLose = document.querySelector('#winLose')
const inputNumber = document.querySelector('.inp_panel')
const help = document.querySelector('#help')
const again = document.querySelector('#again')
const count = document.querySelector("#countValue");
const highValue = document.querySelector("#highScoreValue");
const wrong = document.querySelector("#wrongAnswers");

let highScore = 20;
let gethHighScoreValue = sessionStorage.getItem('highScore')
if(gethHighScoreValue == null){
    sessionStorage.setItem("highScore",String(0))
    highValue.innerHTML = sessionStorage.getItem('highScore')

}else{
    sessionStorage.setItem("highScore",gethHighScoreValue)
    highValue.innerHTML = sessionStorage.getItem('highScore')
}
console.log(highValue)
function check(number,ramdomN){
    
    return Math.abs(number - ramdomN) > 10
}

function guessNumber(number){
    if (number == randomNumber) {
        inputNumber.disabled = true;
        winLose.innerText = "You Win"
        if(highScore > Number(sessionStorage.getItem('highScore'))){
        sessionStorage.setItem("highScore",String(highScore))
        highValue.innerHTML = sessionStorage.getItem('highScore')
        }
        wrong.innerText = "";
    }else if(count.innerHTML == 0){
        inputNumber.disabled = true;
        winLose.innerText = "You Lose"
    }else {
        wrong.innerText = "wrong:";
        count.innerHTML -= 1; 
        highScore -= 1;
        if(number > randomNumber && check(number,randomNumber)) {
            help.innerText = "Super high"
        }else if(number < randomNumber && check(number,randomNumber)) {
            help.innerText = "Super Low"
        }else if(number > randomNumber){
            help.innerText = "high"
        }else if(number < randomNumber){
            help.innerText = "Low"
        }
    }
}
inputNumber.addEventListener('keydown', function(event){
	if(event.key === "Enter"){
        guessNumber(inputNumber.value)
        inputNumber.value = ''
	}
});
again.addEventListener('click',function(){
    inputNumber.disabled = false;
    return location.reload();

})
