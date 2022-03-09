#include <iostream>
using namespace std;

void sorted_array(int);

int main()
{
  int num;
  cout << "Enter a size: ";
  cin >> num;
  sorted_array(num);
  return 0;
}

void sorted_array(int num)
{
  int randArray[num];

  for (int i = 0; i < num; i++)
    randArray[i] = rand() % 100;
  cout << "Random array is: ";
  for (int i = 0; i < num; i++)
    cout << randArray[i] << " ";

  for (int i = 0; i < num; i++)
  {
    for (int j = 1 + i; j < num; j++)
    {
      if (randArray[i] > randArray[j])
      {
        int temp = randArray[i];
        randArray[i] = randArray[j];
        randArray[j] = temp;
      }
    }
  }

  cout << "\nSorted array is: ";
  for (int i = 0; i < num; i++)
  {
    cout << randArray[i] << " ";
  }
  cout << endl;
}
