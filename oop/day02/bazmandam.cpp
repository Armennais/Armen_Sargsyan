#include "bazmandam.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

Bazmandam::Bazmandam(int member_count, int number)
{
	_member_count = member_count;
	_number = number;
}
void Bazmandam::Add()
{
	int member = _member_count;
	string poly;
	int answer = 0;
	while(member > 0)
	{
		int coef;
		cout << "Input coef: " ;
		cin >> coef;
		answer += coef*pow(_number, member);
		poly += ( to_string(coef) + "*x^" + to_string(member) + "+");
		member--;
	}
	poly.pop_back();
	cout << poly + "=" + to_string(answer) << endl;
}
void Bazmandam::Subsract()
{
	 int member = _member_count;
 	 string poly;
	 int answer = 0;
	 while(member > 0)
	 {
		 int coef;
		 cout << "Input coef: " ;
		 cin >> coef;
		 answer -= coef*pow(_number, member);
		 poly += (to_string(coef) + "*x^" + to_string(member) +  "-");
		 member--;
	 }			
	 poly.pop_back();	
	 cout << poly + "=" + to_string(answer) << endl;
}
void Bazmandam::Multiply()
{
	int member = _member_count;
	string poly;
	int answer = 0;
	while(member > 0)
	{
		int coef;
		cout << "Input coef: " ;
		cin >> coef;
		answer *= coef*pow(_number, member);
		poly += (to_string(coef) + "*x^" + to_string(member) +  "*");
		member--;
	}
	poly.pop_back();
	cout << poly + "=" + to_string(answer) << endl;
}
int main()
{
	int member_count;
	int number;
	char check;
	cout << "Input count of poly: ";
	cin >> member_count;
        cout << "Input number: ";
	cin >> number;
	Bazmandam p (member_count, number);		     
	do{
	cout << "Input */+/- : ";
	cin >> check;
	if(check == '+')
		p.Add();
	else if(check == '-')
		p.Subsract();
	else if(check == '*')
		p.Multiply();
	}while((check != '*') || (check != '-') || (check != '*'));
	return 0;
}
