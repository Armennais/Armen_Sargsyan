#include <iostream>
using namespace std;
void number_Guessing(int );//Function guess number on [0:100 ]range

int main()
{
	int secret_num;  // secret number
	cout << "Input secret number for guessing in[0:100] range \n";
	cin >> secret_num;  //Input secret number
	number_Guessing(secret_num);
	return 0;
}
//function that guess number
void number_Guessing(int secret_num)
{
	int guess_number;
	do {
		if (secret_num < 0 || secret_num > 100)
		{
			cout << "I said in[0:100] range!!! \n";
			cin >> secret_num;
			cin.ignore();
		}
		else
		{
			cout << "Try guess the number : ";
			cin >> guess_number;
			if (guess_number < secret_num)
				cout << "Try a larger number \n";
			else if (guess_number > secret_num)
				cout << "Try a smaller number \n";
			else
				cout << "YESSS!!!  \n";
		}
	} while (guess_number != secret_num);
}
