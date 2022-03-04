#include <iostream>
using namespace std;

int main()
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

  switch (op)
  {
    case '+':
      cout << "Output : " << num1 << " + " << num2 << " = " << num1 + num2 << " \n ";
      break;

    case '-':
      cout << "Output : " << num1 << " - " << num2 << " = " << num1 - num2 << " \n ";
      break;

    case '*':
      cout << "Output : " << num1 << " *" << num2 << " = " << num1 * num2 << " \n ";
      break;

    case '/':
      cout << "Output : " << num1 << " / " << num2 << " = " << num1 / num2 << " \n ";
      break;

    default:
      cout << "An incorrect operator has been entered";
      break;
  }

  return 0;
}
