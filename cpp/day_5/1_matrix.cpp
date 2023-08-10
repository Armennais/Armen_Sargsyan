#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
  int i, j;

  srand(time(0));
  const int size = 5;
  int matrix[size][size];

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      matrix[i][j] = rand() % 10 + 1;
      if (matrix[i][j] > 9)
      {
        cout << matrix[i][j] << " ";
      }
      else
      {
        cout << matrix[i][j] << "  ";
      }
    }

    cout << endl;
  }

  cout << endl;

  int sum1 = 0;
  int sum2 = 0;
  int sum3 = 0;
  int sum4 = 0;
  int sum5 = 0;
  int sum6 = 0;
  int sum7 = 0;
  int sum8 = 0;
  
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if (i > j)
      {
        //   cout << matrix[i][j] << " ";
        sum6 += matrix[i][j];
      }
      else if (i < j)
      {
        //   cout << matrix[i][j] << " ";
        sum5 += matrix[i][j];
      }

      int a = i + j, b = size - 1;

      if (a != b && a > b)
      {
        //   cout << matrix[i][j] << " ";
        sum8 += matrix[i][j];
      }
      else if (a != b && a < b)
      {
        //   cout << matrix[i][j] << " ";
        sum7 += matrix[i][j];
      }

      int c = size - 1 - j;

      if (i > j && i > c)
      {
        //   cout << matrix[i][j] << " ";
        sum1 += matrix[i][j];
      }
      else if (i > j && i < c)
      {
        //   cout << matrix[i][j] << " ";
        sum2 += matrix[i][j];
      }
      else if (i < j && i > c)
      {
        //   cout << matrix[i][j] << " ";
        sum3 += matrix[i][j];
      }
      else if (i < j && i < c)
      {
        //   cout << matrix[i][j] << " ";
        sum4 += matrix[i][j];
      }
    }
  }

  cout << "\nDOWN SMALL  : " << sum1;
  cout << "\nLEFT SMALL  : " << sum2;
  cout << "\nRIGHT SMALL : " << sum3;
  cout << "\nUP SMALL    : " << sum4;
  cout << "\nUP/RIGHT    : " << sum5;
  cout << "\nLEFT/LEFT   : " << sum6;
  cout << "\nUP/LEFT     : " << sum7;
  cout << "\nDOWN/RIGHT  : " << sum8 << endl;
  return 0;
}
