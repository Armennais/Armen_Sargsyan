#include <iostream>
#include "myAtoi.h"
using namespace std;
int main(int argc, char * argv[])
{
	int sum1 = 0,sum2 = 0;
	for(int i = 0; i < argc;i++)
	{
		if(i != 0)
		{ 
			sum1 += atoi(argv[i]);
			sum2 += myAtoi(argv[i]);
		}
	} 
	cout << "Original atoi() : " << sum1 << "\n" << "My atoi() : " << sum2 << endl;
	return 0;
}
