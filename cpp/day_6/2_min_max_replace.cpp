#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	srand(time(0));
	const int m = 4,n = 4;
	double matrix[m][n];
	cout << "Before replace: " << endl; 
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 10;
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	int Max = 0, Min = 0, rev = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] > matrix[i][Max])
			{
				Max = j;
			}

			if (matrix[i][j] < matrix[i][Min])
			{
				Min = j;
			}
		}

		cout << "Max: " << Max << "  " << "Min: " << Min << "" << endl;
		rev = matrix[i][Max];
		matrix[i][Max] = matrix[i][Min];
		matrix[i][Min] = rev;
		Min = 0, Max = 0;
	}

	cout << "\n After replace: " <<  endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}
