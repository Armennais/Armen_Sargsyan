// 1. Գրել ֆունկցիա, որը արգումենում պետք է ստանա string և վերադարձնի նույն string-ը, բայց առաջին բառը մեծատառերով։
function firstWordToUppercase(word) {
	let word1 = word.split(" ");
	return word1[0].toUpperCase() + " " + word1.slice(1).join(' ');
}
console.log(firstWordToUppercase("Javascript is a programming language"));

// 2. Գրել ֆունկցիա, որը արգումենում պետք է ստանա զանգված և չափ: Ֆունկցիան տրված զանգվածը պետք է բաժանի ենթազանգվածների ըստ տրված չափի ու արդյունքը վերադարձնի զանգվածի տեսքով;
const num_arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];

function foo(arr, num) {
	const newArr = [];
	while(num_arr.length) {
		newArr.push(`[ ${num_arr.splice(0,num)} ]`);
	}
	return newArr;
}
console.log(foo(num_arr, 4));

// 3. Գրել ֆունկցիա, որը արգումենտում կստանա օբյեկտ ({}) և կվերադարձնի օբյեկտի բոլոր այն արժեքների գումարը որոնք հանդիսանում են թիվ.
function getSum(obj) {
	let sum = 0;
	for(let el in obj) {
		if(!isNaN(obj[el])) {
			sum += parseFloat(obj[el]);
		}
	}
	return sum;
}
let myObj = {
	a: 1,
	b: 2,
	c: 3,
	d: "str"
};
let sum = getSum(myObj);
console.log("sum: " + sum);

// 4. Գրել ֆունկցիա, որը կհաշվի ձայնավորների քանաքը արգումենտով փոխանցված string֊ում
function vowelCount(str1) {
	let vowelList = 'aeiou';
	let count = 0;
	for(var x = 0; x < str1.length; x++) {
		if(vowelList.indexOf(str1[x]) !== -1) {
			count += 1;
		}
	}
	return count;
}
console.log("Output " + vowelCount("Today is the best day of my life"));

// 5․ Գրել ֆունկցիա, որը ստանում է զանգված արգումենտում և գումարում է առանձին առանձին դրական և բացասական թվերը։ Ֆունկցիան պետք է վերադարձնի օբյեկտ:
function SummPositive(numbers) {
	let myObj = {
		positive: 0,
		negative: 0,
	}
	for(var i = 0; i < numbers.length; i++) {
		if(numbers[i] < 0) {
			myObj.negative += numbers[i];
		} else {
			myObj.positive += numbers[i];
		}
	}
	return myObj;
}
let arr = [1, 2, 3, -4, -5, 1, -2];
console.log(SummPositive(arr));

	// 6.Գրել ֆունկցիա, որը արգումենտում կստանա ստորև տրված data֊ն ու կվերադարձնի եզակի (unique) քաղաքների զանգված։
const array = [{
	id: 1,
	name: 'Name one',
	city: 'Stepanakert',
}, {
	id: 2,
	name: 'Name one',
	city: 'Erevan',
}, {
	id: 3,
	name: 'Name one',
	city: 'Moscow',
}, {
	id: 4,
	name: 'Name one',
	city: 'Stepanakert',
}, {
	id: 5,
	name: 'Name one',
	city: 'Erevan',
}, ];
const unique = Array.from(new Set(array.map(item => item.city)));
console.log(unique);