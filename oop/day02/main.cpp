#include <iostream>
#include "bazmandam.h"
using namespace std;

int main()
{
	int d1;
	int d2;
	cout << "1st Poly: Enter degree: ";
	cin >> d1;
	double * arr = new double[d1 + 1];
	for ( int i = d1; i >= 0; i--)
	{
		cout << "Enter coefficient of x^" << i <<":";
		cin >> arr[i];
	}
	cout << "1st Poly: Enter degree: ";	         
	cin >> d2;
	double * arr2 = new double[d2 + 1];
	for ( int i = d2; i >= 0; i--)
	{
		cout << "Enter coefficient of x^" << i <<":";
		cin >> arr2[i];
	}	
	Poly fObj(arr,d1 + 1);
	Poly sObj(arr2,d2 + 1);
	fObj.displayPoly();
	sObj.displayPoly();
 	return 0;
}
