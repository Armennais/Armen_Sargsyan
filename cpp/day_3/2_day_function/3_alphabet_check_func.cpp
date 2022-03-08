#include <iostream>
using namespace std;

void alphabet_check(char letter)
{
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
        }
}


int main()
{
	char letter;
	cout << "Enter letter from  a to Z := ";
	cin >> letter;
	alphabet_check(letter);
	return 0;

}
