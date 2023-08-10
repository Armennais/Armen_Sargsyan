#include <iostream>
using namespace std;

int factorial (int n)
{
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}



int main()
{
	int number;
        cout << "Input the number : ";
        cin >> number;
	cout << number << "'s factorial is " << factorial(number) << endl; 

        return 0;
}
