#ifndef Date_h
#define Date_h

class Date
{
private:
	int _year;
	int _month;
	int _day;

public:
	Date(int year, int month, int day);
	
	int getYear();
	void setYear(int year);

	int getMonth();
        void setMonth(int month);
	
	int getDay();
	void setDay(int day);

};
#endif //Date_h
