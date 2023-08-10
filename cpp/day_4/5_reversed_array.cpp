#include <iostream>
using namespace std;

void reversed_array(int);

int main()
{
  int num;
  cout << "Enter a size: ";
  cin >> num;
    reversed_array(num);
  return 0;
}

void reversed_array(int num)
{
      int randArray[num];

  for (int i = 0; i < num; i++)
  randArray[i] = rand() % 100;
  cout << "Random array is: ";
  for (int i = 0; i < num; i++)
    cout << randArray[i] << " ";

  cout << "\nReversed array is: ";
  for (int i = num - 1; i >= 0; i--)
  {
    cout << randArray[i] << " ";
  }
  cout << endl;
}
