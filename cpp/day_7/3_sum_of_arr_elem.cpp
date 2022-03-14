#include <iostream>
using namespace std;

void sum(int *arr, int size)
{
  int i, sum = 0;
  for (i = 0; i < size; i++)
    sum = sum + *(arr + i);
  cout << "sum  = " << sum;
}

int main()
{
  int n = 4;
  int arr[] = { 1, 4, 10, -12 };

  sum(arr, n);
  cout << endl;
  return 0;
}
