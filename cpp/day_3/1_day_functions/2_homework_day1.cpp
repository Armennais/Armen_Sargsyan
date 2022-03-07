#include<iostream>
using namespace std;

void multiple_table (int mult_num)
{
	int c = 0;
	int limit = 10;
        
	while(c<=limit)
	{
        	cout << mult_num << " * " << c << " = " << c*mult_num<<endl; //Print multiplication table 
        	c++;
    	}
    
}

int main()
{
	int mult_num;
        cout << "Input multiple number : ";
	cin >> mult_num; //Input number to print its table
 	multiple_table(mult_num);
}
