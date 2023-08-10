#include <iostream>
using namespace std;
int main()
{
	int mult_num;
input:
	cout << "Input multiple number : ";
	cin >> mult_num;	//Input number to print its table
	if( (mult_num > 10) || (mult_num < 0))
	{
		goto input;
	}
	int num = 0;
	int limit = 10;
	
	while (num <= limit)
	{
		cout << mult_num << " * " << num << " = " << num * mult_num << endl;	//Print multiplication table 
		num++;
	}
	return 0;
}
