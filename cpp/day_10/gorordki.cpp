#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std; 

int inputPlayer();
int choosePlayer(int player);
void gameing(int x);

int main()
{
	int choosen = choosePlayer(inputPlayer());
	gameing(choosen);
	return 0;
}

int inputPlayer()
{
	cout << "For a first play: \n\t 1. User : \n\t 2. Computer :\n ";
	cout << "Choose player : ";
	int player;
	cin >> player;
	return player;

}

int choosePlayer(int player)
{
	if(player == 1)
	{
	    return 1;
	}else if(player == 2)
	{
	    return 2;
	}
	return 0;
}

void gameing(int x)
{

	string arr[] = {"erevan",
	                "moscow", 
	                "prague",
	                "paris", 
	                "berlin",
	                "ankara", 
	                "baku", 
	                "udinese",
	                "ekaterinburg",
	                "grozni",
	                "irkutsk", 
	                "kirovakan",
	                "ninve", 
	                "elizavetpol", 
	                "valencia",
	                "astana",
	                "dublin",
	                "zaltsburg"
	                "pekin",
	                "mumbai"
	};
    int size = sizeof(arr)/sizeof(arr[0]);
	int rand_ind = rand() % size;
	string user;
	bool check = false;

	while (true)
	{
		if (x == 2)
		{
	        cout << "=================================" << endl;
			cout << "computer->\t" << arr[rand_ind] << "\t\t|";
			x = 1;
			check = true;
		}
		if (x == 1)
		{
		    cout << "\n=================================" << endl;
			cout << "user->   \t";
			cin >> user;
			x = 2;
		}

		if (check && arr[rand_ind][arr[rand_ind].length() - 1] != user[0])
		{
			cout << "-> You Lose <-" << endl << endl;
			break;
		}

		if (check)
		{
			arr[rand_ind] = "0";
		};

		for (int i = 0; i < size; i++)
		{
			if (arr[i][0] == user[user.length() - 1])
			{
				rand_ind = i;
				break;
			}

			if (i == (size - 1))
			{
				cout << "-> You Win <-" << endl << endl;
				break;
			}
		}
	}
}