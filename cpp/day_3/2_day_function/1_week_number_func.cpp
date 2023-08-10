#include <iostream>
using namespace std;
void week_name(int weeknumber)
{
 switch (weeknumber)
  {
    case 1:
      cout << "Mondayi \n";
      break;
    case 2:
      cout << "Tuesday \n";
      break;
    case 3:
      cout << "Wednesday \n";
      break;
    case 4:
      cout << "Thursday \n";
      break;
    case 5:
      cout << "Friday \n";
      break;
    case 6:
      cout << "Saturday \n";
      break;
    case 7:
      cout << "Sunday \n";
      break;
    default:
      cout << "Please enter between 1-7. \n";
  }

}





int main()
{
  int weeknumber;

  cout << "Enter week number(1-7): ";
  cin >> weeknumber;
  week_name(weeknumber);
  return 0;

}
