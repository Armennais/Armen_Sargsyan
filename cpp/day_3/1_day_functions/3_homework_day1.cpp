#include <iostream>
using namespace std;
void nestTwLeapYear(int year)
{
	int i = 0;
	while (i < 20)
        {
        	cout << year << endl;
                year += 4;
                i++;
        }

}




int main()
{
        int year = 2024;        //next first leap year
        cout << "Print the next 20 leap year \n";
	nestTwLeapYear(year);
        return 0;
}

