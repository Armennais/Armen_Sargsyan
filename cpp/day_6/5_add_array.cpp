#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	srand(time(0));
	const int n = 4;
	int matrix1[n][n], matrix2[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix1[i][j] = rand() % 10 + 1;
			if (matrix1[i][j] > 9)
			{
				cout << matrix1[i][j] << " ";
			}
			else
			{
				cout << matrix1[i][j] << "  ";
			}
		}

		cout << endl;
	}

	cout << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix2[i][j] = rand() % 10 + 1;
			if (matrix2[i][j] > 9)
			{
				cout << matrix2[i][j] << " ";
			}
			else
			{
				cout << matrix2[i][j] << "  ";
			}
		}

		cout << endl;
	}

	cout << "\n" << endl;
	cout << "sum of 2 arrays : \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix1[i][j] + matrix2[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}
