#include<iostream>

using namespace std;
int main() {
  int i = 0;
  int year = 2024; //next first leap year
  cout << "Print the next 20 leap year \n";
  while (i <= 20) {
    cout << year << endl;
    year += 4;
    i++;

  }
  return 0;
}
