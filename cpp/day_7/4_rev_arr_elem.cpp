#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(int array[], int array_size)
{
  int *ptr1 = array;

  int *ptr2 = array + array_size - 1;
  while (ptr1 < ptr2)
  {
    swap(ptr1, ptr2);
    ptr1++;
    ptr2--;
  }
}

void print(int *array, int arr_size)
{
  int *size = array + arr_size;

  int *arr_ptr = array;
  cout << "Array = ";
  for (arr_ptr = array; arr_ptr < size; arr_ptr++)
    cout << *arr_ptr << " ";
}

int main()
{
  int n = 5;
  int array[] = { 1, 2, 3, 4, 5 };
  print(array, n);
  cout << endl;
  cout << "Reverse ";
  reverse(array, n);
  print(array, n);
  cout << endl;
  return 0;
}
