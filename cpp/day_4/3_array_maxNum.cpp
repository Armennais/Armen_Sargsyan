#include <iostream>
using namespace std;
void max_val_array(int);
int find_max(int, int randArray[]);

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  const int num = n;
  max_val_array(num);
  return 0;
}

void max_val_array(int num)
{
  int randArray[num];
  for (int i = 0; i < num; i++)
    randArray[i] = rand() % 100;
  cout << "Random array is:[";
  for (int i = 0; i < num; i++)
    cout << randArray[i] << " ";
  cout << "]; ";

  cout << endl << "Largest element = " << find_max(num, randArray) << ";\n";
}

int find_max(int num, int randArray[])
{
  for (int i = 1; i < num; ++i)
  {
    if (randArray[0] < randArray[i])
      randArray[0] = randArray[i];
  }

  return randArray[0];
}
