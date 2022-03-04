#include <iostream>
using namespace std;
int main()
{
  char letter;
  cout << "Enter letter from  a to Z := ";
  cin >> letter;
  switch (letter)
  {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      cout << "'" << letter << "' is vowel \n";
      break;

    default:
      cout << "'" << letter << "' is consonant \n";
  }

  return 0;

}
