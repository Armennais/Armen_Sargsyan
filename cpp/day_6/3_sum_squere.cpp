#include <string>
#include <iostream>
using namespace std;

bool sumSquare(int);

int main()
{
	const int len = 10;
	int nums[len];
	int i = 0;
	int n = 1;
	while (i != len)
	{
		if (sumSquare(n))
		{
			nums[i] = n;
			i++;
		}

		n++;

	}

	for (int j = 0; j < len; j++)
	{
		cout << nums[j] << " ";
	}
	cout << endl;
	return 0;

}

bool sumSquare(int n)
{
	for (int i = 1; i * i <= n; i++)
		for (int j = 1; j * j <= n; j++)
			if ((i *i + j *j == n) && (n % 5 == 0))
			{
				cout << i << "^2 + " <<
					j << "^2" << endl;
				return true;
			}

	return false;
}
