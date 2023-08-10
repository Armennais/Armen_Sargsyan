#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct cars {
    string carName;
    int minPrice;
    int maxPrice;
    int mileage;
    double engineCap;
    string transmision;
    string color;
};
void printList(cars);
int num_lines();
int main ()
{
	struct cars str_cars[7];
	string str = "";
	string array_C[7];
	ifstream cFile("cars.txt");
	int i1 = 0,i2 = 0;
	while (!cFile.eof())
	{	
		cFile >> str;
		array_C[i1] = str;
		i1++;
		if(i1 == 7)
		{
			str_cars[i2].carName = array_C[0];
			str_cars[i2].minPrice = stoi(array_C[1]);
			str_cars[i2].maxPrice = stoi(array_C[2]);
			str_cars[i2].mileage = stoi(array_C[3]);
			str_cars[i2].engineCap = stod(array_C[4]);
			str_cars[i2].transmision = array_C[5];
			str_cars[i2].color = array_C[6];
			i1 = 0;
			i2++;
		}
	}
	cFile.close();
	string list ;
	cout << "What you want:\n'list' -to show all car names:\n'search' - to search a car: ";
	
	getline(cin,list);
	if(list == "list")
	{
		cout << "____________________" << endl;
		for(int i = 0; i < num_lines();i++)
		{
			cout << str_cars[i].carName << " ";
			if((i + 1) % 3 == 0 && i != 0)
			{
				cout << "\n";
			}
		}	
	}
	if(list == "search")
	{
		string model;
		int minP,maxP;
		int filter;
		cout << "We have anly 3 type of search car\n";
		cout << "First enter filter count: ";
		cin >> filter;
		
		if(filter == 1)
		{
			cout << "Enter the car model: ";
	                cin >> model;

			for(int i = 0;i < num_lines();i++)
			{
				if((model == str_cars[i].carName) && (minP == 0))
				{
					printList(str_cars[i]);
				}
			}
		}else if(filter == 2)
		{
			cout << "Enter the car model: ";
	                cin >> model;
			cout << "Enter the car min price: ";
                	cin.ignore();
			cin >> minP;
			for(int i = 0;i < num_lines();i++)
                        {
				if((model == str_cars[i].carName) && (minP <= str_cars[i].minPrice))

                                {
                                        cout << endl;
                                        printList(str_cars[i]);
                                }

			}
			
		}else if(filter == 3)
		{
			cout << "Enter the car model: ";
                	cin >> model;
			cout << "Enter the car min price: ";
                        cin.ignore();
                        cin >> minP;
			cout << "Enter the car max price: ";
			cin >> maxP;
                        for(int i = 0;i < num_lines();i++)
                        {
                                if((model == str_cars[i].carName) && ((minP <= str_cars[i].minPrice) && (maxP >= str_cars[i].minPrice)))
                                {
                                        cout << endl;
                                        printList(str_cars[i]);
                                }
                        }

		}else
		{
			cout << "you must be input [1-3] range number: ";
			return 0;
		}
	}
	
	return 0;
}
int num_lines()
{
	int count = 0;
	string line;
	ifstream ifs("cars.txt");
	while(getline(ifs, line))
	{
		++count;
	}
	ifs.close();
	return count;
}
void printList(cars c)
{
	cout << "===============================" << endl;	
	cout << "Model:      \t" << c.carName << endl;
	cout << "-------------------------------" << endl;
        cout << "Min Price:  \t" << c.minPrice << endl;
	cout << "-------------------------------" << endl;
        cout << "Max Price:  \t" << c.maxPrice << endl;
	cout << "-------------------------------" << endl;
        cout << "Mileage:    \t" <<  c.mileage << endl;
	cout << "-------------------------------" << endl;
        cout << "Engine:     \t" << c.engineCap << endl;
	cout << "-------------------------------" << endl;
        cout << "Transmision:\t" << c.transmision << endl;
	cout << "-------------------------------" << endl;
        cout << "Color:      \t" << c.color << endl;
	cout << "===============================" << endl;
}
