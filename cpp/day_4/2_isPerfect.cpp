#include <iostream>
using namespace std;
bool isPerfect(int);

int main()
{
  int num;
  cout << "Enter the number: ";
  cin >> num;
  if (num < 0)
  {
    cout << "The number is negative!!! \n";
  }
  else if (isPerfect(num))
  {
    cout << "\n" << num << " is perfect number. \n";
  }
  else
  {
    cout << "\n" << num << " is not perfect number. \n";
  }

  return 0;
}

bool isPerfect(int num)
{
  int i, sum = 0;
  for (i = 1; i < num; i++)
  {
    if (num % i == 0)
      sum = sum + i;
  }

  return (num == sum);
}
