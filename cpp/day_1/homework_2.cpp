#include <iostream>
using namespace std;
int main()
{
	int mult_num;
	cout << "Input multiple number : ";
	cin >> mult_num;	//Input number to print its table
	int c = 0;
	int limit = 10;
	while (c <= limit)
	{
		cout << mult_num << " *" << c << " = " << c * mult_num << endl;	//Print multiplication table 
		c++;
	}
}
