#include <iostream>
using namespace std;
int main()
{
	int chickens, cows, pigs, total_legs;
	cout << "chickens = ";
	cin >> chickens;//input chickens legs count
	cout << "cows = ";
	cin >> cows;//input cows legs count
	cout << "pigs = ";
	cin >> pigs;//input pigs legs count
	total_legs = chickens * 2 + 4 * (cows + pigs);
	cout << "Total chickens  = " << total_legs << endl;
	return 0;
}
