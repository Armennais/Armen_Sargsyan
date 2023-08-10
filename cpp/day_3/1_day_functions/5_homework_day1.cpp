#include <iostream>
using namespace std;
int perimeter (int length, int width)
{
	return (2 * (length + width));
}

int area (int length, int width)
{
	return (length * width);
}	

int main()
{
	int length, width;
	cout << "Input edges of rectangle : \n";
	cin >> length >> width;	// Input length and width at once
	cout << "Perimeter = " << perimeter(length, width) << endl;
	cout << "Area = " << area(length, width) << endl;
	return 0;
}
