#include <iostream>
using namespace std;

void sum1(int *a, int *b, int *sum);  // 1
void sum2(int &a, int &b, int &sum);  // 2
void sum3(int a, int b, int &sum);  // 3
void sum4(int a, int *b, int &sum);  // 4
void sum5(int *a, int *b, int &sum);  // 5

int main()
{
  int a, b, sum = 0;
  cout << "Enter numbers: ";
  cin >> a >> b;

  sum1(&a, &b, &sum);
  cout << endl;

  sum2(a, b, sum);
  cout << endl;

  sum3(a, b, sum);
  cout << endl;

  sum4(a, &b, sum);
  cout << endl;

  sum5(&a, &b, sum);
  cout << endl;
  return 0;
}

void sum1(int *a, int *b, int *sum)
{
  *sum = *a + *b;
  cout << "Sum 1: ";
  cout << *a << " + " << *b << " = " << *sum;
}

void sum2(int &a, int &b, int &sum)
{
  sum = a + b;
  cout << "Sum 2: ";
  cout << a << " + " << b << " = " << sum;
}

void sum3(int a, int b, int &sum)
{
  sum = a + b;
  cout << "Sum 3: ";
  cout << a << " + " << b << " = " << sum;
}
void sum4(int a, int *b, int &sum)
{
  sum = a + *b;
  cout << "Sum 3: ";
  cout << a << " + " << *b << " = " << sum;
}
void sum5(int *a, int *b, int &sum)
{
  sum = *a + *b;
  cout << "Sum 3: ";
  cout << *a << " + " << *b << " = " << sum;
}
