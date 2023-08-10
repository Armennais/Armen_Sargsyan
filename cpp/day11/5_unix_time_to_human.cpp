#include <iostream>
using namespace std;

string timeFromUnixToHuman (long int);

int main()
{
	long int sec ;
	cout << "Input seconds: ";
	cin >> sec;
	cout << "UTC: ";
	string res = timeFromUnixToHuman(sec);
	cout << res << "\n";

	return 0;
}

string timeFromUnixToHuman(long int seconds)
{

	string res = "";

	int daysOfMonth[] = { 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	long int currYear, daysNow, extraTime, extraDays, index, date, month, hours, minutes, check = 0;

	daysNow = seconds / (24 * 60 *60);
	extraTime = seconds % (24 * 60 *60);
	currYear = 1970;

	while (daysNow >= 365)
	{
		if (currYear % 400 == 0 || (currYear % 4 == 0 && currYear % 100 != 0))
		{
			daysNow -= 366;
		}
		else
		{
			daysNow -= 365;
		}

		currYear += 1;
	}
	extraDays = daysNow + 1;

	if (currYear % 400 == 0 || (currYear % 4 == 0 && currYear % 100 != 0))
	{
		check = 1;
	}
	month = 0, index = 0;
	if (check == 1)
	{
		while (true)
		{
			if (index == 1)
			{
				if (extraDays - 29 < 0)
				{
					break;
				}
				month ++;
				extraDays -= 29;
			}
			else
			{
				if (extraDays - daysOfMonth[index] < 0)
				{
					break;
				}

				month += 1;
				extraDays -= daysOfMonth[index];
			}

			index += 1;
		}
	}
	else
	{
		while (true)
		{
			if (extraDays - daysOfMonth[index] < 0)
			{
				break;
			}
			month ++;
			extraDays -= daysOfMonth[index];
			index ++;
		}
	}

	if (extraDays > 0)
	{
		month ++;
		date = extraDays;
	}
	else
	{
		if (month == 2 && check == 1)
		{	
			date = 29;
		}
		else
		{
			date = daysOfMonth[month - 1];
		}
	}

	hours = extraTime / 3600;
	minutes = (extraTime % 3600) / 60;

    res += (date < 10) ? "0" : "";
	res += to_string(date);
	res += (month < 10) ? "/0":"/";
	res += to_string(month);
	res += "/";
	res += to_string(currYear);
    res += (hours < 10) ? " 0":" ";
	res += to_string(hours);
    res += (minutes < 10) ? ":0":":";
	res += to_string(minutes);


	return res;
}