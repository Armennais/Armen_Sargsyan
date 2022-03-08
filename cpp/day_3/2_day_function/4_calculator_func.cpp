#include <iostream>
using namespace std;

void add(float num1, float num2)
{
	cout << "Output : " << num1 << " + " << num2 << " = " << num1 + num2 << " \n ";
}

void subtract(float num1, float num2)
{
	cout << "Output : " << num1 << " - " << num2 << " = " << num1 - num2 << " \n ";
}

void multiply(float num1, float num2)
{
	cout << "Output : " << num1 << " *" << num2 << " = " << num1 * num2 << " \n ";
}

void divide(float num1, float num2)
{
	cout << "Output : " << num1 << " / " << num2 << " = " << num1 / num2 << " \n ";
}

void calculator()
{
	char op;
	float num1, num2;
	cout << "Program takes an arithmetic operator(+, -, *, /)\n";
	cout << "Input number 1: ";
	cin >> num1;
	cout << "Input operator: ";
	cin >> op;
	cout << "Input number 2: ";
	cin >> num2;
	if (num2 == 0)
	{
		do { 	cout << "Input number 2 again: ";
			cin >> num2;
		} while (num2 == 0);
	}
	switch (op)
	{
		case '+':
			add(num1, num2);
			break;

		case '-':
			subtract(num1, num2);
			break;

		case '*':
			multiply(num1, num2);
			break;

		case '/':
			divide(num1, num2);
			break;

		default:
			cout << "An incorrect operator has been entered";
			break;
	}
}

int main()
{
	calculator();
	return 0;
}
