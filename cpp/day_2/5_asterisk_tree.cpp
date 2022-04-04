#include <iostream>
using namespace std;

int main()
{
	int c, i = 0;
	cout << "Enter count: \n";
      	cin >> c;
	const int count = c;
	i = count;
  
	//Asterisk example 1
	
	while (i > 0)
	{
		int j = 0;
		while (j < i)
		{
			cout << " *";
			j++;
		}

    	j = 0;
    	cout << " " << endl;
    	i--;	
	}


  //Asterisk example 2

  	while (i < count)
  	{
    		int j = 0;
    		while (j <= i)
    		{
      			cout << " *";
      			j++;
    		}
    		j = 0;
    		cout << " " << endl;
    		i++;
  	}	
  	i = 0;

  //Asterisk example 3

  	while (i < count)
  	{
    		int j = 0;
   		while (j < count - i)
    		{	
      			cout << " ";
      			j++;
    		}
    		j = 0;
    		while (j <= i)
    		{
      			cout << "*";
      			j++;
    		}
    		j = 0;
    		i++;

    		cout << " " << endl;
  	}

  	i = 0;


  //Another Asterisk example 3
  
  
  	while (i < count)
  	{
    		int j = 0;

    		while (j < count - i)
    		{
      			cout << " ";
      			j++;
    		}

    		j = 0;
    		while (j <= i)
    		{
      			cout << " *";
      			j++;
    		}
    		j = 0;
    		i++;
    		cout << " " << endl;
  	}

  i = 0;

  //Asterisk example 4

  	while (i < count)
  	{
    		int j = 0;
    		while (j < count - i)
    		{
      			cout << " ";
      			j++;
    		}
    		j = 0;
    		while (j <= 2 *i)
    		{
      			cout << "*";
      			j++;
    		}
    		j = 0;
    		i++;
    		cout << " " << endl;
  	}

  return 0;
}
