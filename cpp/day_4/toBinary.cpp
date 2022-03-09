#include <iostream>
using namespace std;

void toBinary(int);

int main()
{
  int n;
  cout << "Enter Decimal number: ";
  cin >> n;
  if (n > 0)
  {
    toBinary(n);
  }
  else if (n == 0)
  {
    return 0;
  }
  else
  {
    cout << "Error: " << n << " is negative";
  }
  return 0;
}

void toBinary(int n)
{
  int bin_num[32];

  int i = 0;
  cout << "Binary is: ";
  while (n > 0)
  {
    bin_num[i] = n % 2;
    n = n / 2;
    i++;
  }

  for (int j = i - 1; j >= 0; j--)
  {
	cout  << bin_num[j];
  }
cout << endl;
}
