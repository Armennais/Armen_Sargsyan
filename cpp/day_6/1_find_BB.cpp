#include <string>
#include <iostream>
using namespace std;

int main()
{
	string str;

	cout << "Enter text: ";

	getline(cin, str);
	int sum = 0, num = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'B' && str[i] != ' ')
		{
			num++;

		}

		if ((num == 2 && str[i] == ' ') || (num == 2 && str[i + 1] == '\0'))
		{
			num = 0;

			sum++;

		}

		if (str[i] == ' ')
		{
			num = 0;

		}
	}

	cout << "word's with BB letter count is : " << sum << endl;

	return 0;
}
