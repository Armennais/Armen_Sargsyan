#include <iostream>
using namespace std;

void findMinAndMax(int arr[], int size, int *, int *);
int main()
{
  int arr[6] = { 1000, 11, 445, 1, 330, 3000 };
  cout << "The array is : ";
  for (int i = 0; i < 6; i++)
  {
    cout << arr[i] << " ";
  }

  cout << endl;
  int min = arr[0];
  int max = arr[0];
  findMinAndMax(arr, 6, &min, &max);

  cout << "Min is : " << min << endl;
  cout << "Max is : " << max << endl;
  return 0;
}

void findMinAndMax(int arr[], int size, int *min, int *max)
{
  for (int i = 1; i < size; i++)
  {
    if (arr[i] > *max)
    {
      *max = arr[i];
    }

    if (arr[i]<*min)
    {
      *min = arr[i];
    }
  }
}
