#include<iostream>
using namespace std;
int main()
{
    int chickens,cows,pigs,total_legs;
    cout << "chickens = ";
    cin >> chickens;
    cout << "cows = ";
    cin >> cows;
    cout << "pigs = ";
    cin >> pigs;
    total_legs = chickens*2+4*(cows+pigs);
    cout << "Result  = "<< total_legs << endl;
    return 0;
}
