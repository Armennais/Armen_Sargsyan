#include <iostream>
using namespace std;

//Asterisk function 2

void
asterisk_1(int i, int count)
{
  i = count;
  while (i > 0)
  {
    int j = 0;
    while (j < i)
    {
      cout << " *";
      j++;
    }

    j = 0;

    cout << " " << endl;

    i--;
  }
}

//Asterisk function 2

void asterisk_2(int i, int count)
{

  while (i < count)
  {
    int j = 0;
    while (j <= i)
    {
      cout << " *";
      j++;
    }

    j = 0;
    cout << " " << endl;
    i++;
  }

  i = 0;
}
//Asterisk function 3
void asterisk_3(int i, int count)
{
  for (int i = count; i > 0; i--)
  {
    for (int j = 0; j <= count; j++)  //looping columns
    {
      if (j >= i)
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }

  i = 0;
}

int main()
{
  int c, i = 0;
  cout << "Enter count: ";

  cin >> c;
  const int count = c;

  asterisk_1(i, count);
  cout << endl;

  asterisk_2(i, count);
  cout << endl;

  asterisk_3(i, count);
  cout << endl;

  return 0;
}
