#include <iostream>
using namespace std;

void count_legs()
{
        int chickens, cows, pigs, total_legs;
        cout << "chickens = ";
        cin >> chickens;
        cout << "cows = ";
        cin >> cows;
        cout << "pigs = ";
        cin >> pigs;
        total_legs = chickens * 2 + 4 * (cows + pigs);
        cout << "Result  = " << total_legs << endl;
}

int main()
{
	count_legs();
	return 0;
}
