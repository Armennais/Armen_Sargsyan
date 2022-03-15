#include <iostream>
#include "myAtoi.h"
using namespace std;
int main(int argc, char * argv[])
{
	int sum = 0;
	for(int i = 0; i < argc;i++)
	{
		if(i != 0)
		{
			sum = sum + myAtoi(argv[i]);
		}
	} 
	cout << sum << endl;
	return 0;
}
