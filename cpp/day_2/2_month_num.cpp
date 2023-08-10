#include <iostream>
using namespace std;
int main()
{
	int monthnumber;
input:
	cout << "Input Month number : ";
	cin >> monthnumber;
	switch (monthnumber)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cout << "31 days \n";
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			cout << "30 days \n";
			break;
		case 2:
			cout << "28/29 days \n";
			break;
		default:
			cout << "Error:Entered involid month number\n";
			goto input;
	}

	return 0;

}
