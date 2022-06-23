const randomNumber = 20;
const winLose = document.querySelector('#winLose')
const inputNumber = document.querySelector('.inp_panel')
const help = document.querySelector('#help')
const again = document.querySelector('#again')
const count = document.querySelector("#countValue");
const highValue = document.querySelector("#highScoreValue");
highValue.value = 20;

console.log(highValue)
function check(number,ramdomN){
    
    return Math.abs(number - ramdomN) > 10
}
function guessNumber(number){
    if (number == randomNumber) {
        highValue.innerHTML = highValue.value;
        winLose.innerText = "You Win"
    }else {
        count.innerHTML -= 1; 
        highValue.value -= 1;
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
    return location.reload();
})
