#include <iostream>
using namespace std;

void sum(int *arr, int size)
{
  int sum = 0;
  int *ptr = arr;
  while (ptr < arr + size)
  {
     sum = sum + *(ptr++);
  }
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
