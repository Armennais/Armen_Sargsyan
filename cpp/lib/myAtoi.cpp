#include "myAtoi.h"
int myAtoi (char * arr)
{
	int res = 0,negative = 1,i = 0;
	if (arr[0] == '-')
	{
		negative = -1;
		i++;
	}
	
	for( i; arr[i] != '\0';++i)
	{
		if (arr[i] >= 48 && arr[i] <= 57)
		{
			res = res * 10 + arr[i] - '0';
		}else	
		{
			res = 0;
		}
	}
	return res * negative;
}
