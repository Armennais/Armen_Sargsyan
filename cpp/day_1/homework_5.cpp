#include <iostream>
using namespace std;
int main()
{
	int length, width, perimeter, area;
	cout << "Input edges of rectangle : \n";
	cin >> length >> width;	// Input length and width at once
	perimeter = 2 *(length + width);	//calculate the perimeter of rectangle and assigns on variable
	area = length * width;	//calculate the area of rectangle and assigns on variable
	cout << "Perimeter = " << perimeter << "    " << "Area = " << area << endl;
	return 0;
}
