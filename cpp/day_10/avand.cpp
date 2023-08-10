#include <iostream>
#include <ctime>
using namespace std;

void vark(int, double, int, int, int);

int
main(int argc, char *argv[])
{
  time_t now = time(0);

  string day, month1, year;

  string cur_date;

  int im, id, iy;

  char *date_time = ctime(&now);

  string s = date_time;

  cout << " \t " << s << endl;

  for (int i = 0; s[i] != '\0'; i++)

  {
    if ((i > 3 && i < 11) || (i > s.length() - 6))

    {
      if (s[i] == ' ')

      {
        s[i] = '/';

      }

      cur_date += s[i];

    }
  }

  for (int i = 0; cur_date[i] != '\0'; i++)

  {
    if (i >= 0 && i < 3)

    {
      month1 += cur_date[i];

    }
    else if (i > 3 && i < 6)

    {
      day += cur_date[i];

    }
    else if (cur_date[i] != '/')

    {
      year += cur_date[i];
    }
  }


  string arraymonth[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct",
    "Nov", "Dec" };

  for (int i = 0; i < 12; i++)

  {
    if (month1 == arraymonth[i])

    {
      im = i + 1;

    }
  }

  cout << im << "/" << day << "/" << year << endl;

  int mm = im;
  int dd = stoi(day);
  int yy = stoi(year);
  int money = atoi(argv[1]);

  char *end;

  double tokos = strtod(argv[2], &end);

  int month = atoi(argv[3]);

  vark(money, tokos, month, mm, yy);

  return 0;

}

void
vark(int money, double tokos, int month, int mm , int yy)
{
  double permonth = 0;

  string arraymonth[13] = {"",  "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December" };

  double total = 0;

  cout << "Mayr gumar |\t Ekamut | \tAmis | \t\tTari |" << endl;
  cout << "=======================================================" << endl;
  for (int i = mm ; i <= month; i++)

  {
    permonth = ((money / 100.0) *tokos) / 12;
    
    if (i % 12 == 1)
    {
      yy++;
      cout << "=======================================================" << endl;
      mm = 1;

    }
   
    cout  << money << "\t|  " << permonth << "   \t|  " <<
      arraymonth[mm] << "  \t|\t  " << yy << endl;
    money = money + permonth;
    mm++;

  }
  cout << "=======================================================" << endl; 
  cout << "\t   Total = " << money << endl;
}
