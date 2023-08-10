#include <iostream>
using namespace std;

int main()
{
	char letter;
input:
	cout << "Enter letter from  a to Z := ";
	cin >> letter;
	if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
	{
		switch (letter)
		{
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				cout << "'" << letter << "' is vowel \n";
				break;
			default:
				cout << "'" << letter << "' is consonant \n";
		}
	}
	else
	{
		cout << letter << " is not letter.\n";
		cout << "Please ";
		goto input;
	}
	return 0;

}
