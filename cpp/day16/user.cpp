#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "../lib/function.h"
using namespace std;

struct hotelInfo
{
	string hotelname;
	int starrate;
	int singlRoom;
	int twinRoom;
	int trplRoom;
	int vipRoom;
	bool spa;
	bool souna;
	bool gameRoom;
	bool fitnes;
	bool kidClub;
	bool lobiBar;
	bool laundry;
	int SGLprice;
};
struct checkinUser
{
	string strHotelName;
	string strRoomType;
	int roomCount;

};
string printStars(hotelInfo);
int checkRoomCount(string hotelname, string roomtype, checkinUser chUser)
{
	int sum = 0;

	if ((toUpWord(hotelname) == toUpWord(chUser.strHotelName)) && (toUpWord(roomtype) == toUpWord(chUser.strRoomType)))
	{

		sum += chUser.roomCount;
	}
	return sum;
}
int main()
{
	struct hotelInfo hif[size()];
	string sarr[14];
	ifstream ifs("info.txt");
	string str = "";
	int index1 = 0, index2 = 0;
	while (!ifs.eof())
	{
		ifs >> str;
		sarr[index1] = str;
		index1++;
		if (index1 == 14)
		{
			hif[index2].hotelname = sarr[0];
			hif[index2].starrate = stoi(sarr[1]);
			hif[index2].singlRoom = stoi(sarr[2]);
			hif[index2].twinRoom = stoi(sarr[3]);
			hif[index2].trplRoom = stoi(sarr[4]);
			hif[index2].vipRoom = stoi(sarr[5]);
			hif[index2].spa = stob(sarr[6]);
			hif[index2].souna = stob(sarr[7]);
			hif[index2].gameRoom = stob(sarr[8]);
			hif[index2].fitnes = stob(sarr[9]);
			hif[index2].kidClub = stob(sarr[10]);
			hif[index2].lobiBar = stob(sarr[11]);
			hif[index2].laundry = stob(sarr[12]);
			hif[index2].SGLprice = stoi(sarr[13]);
			index1 = 0;
			index2++;
		}
	}
	ifs.close();
	cout << "             Wellcome          " << endl;
	cout << "|===========Hotel List==========|" << endl;
	for (int i = 0; i < size(); i++)
	{
		cout << "\t" << hif[i].hotelname << " Hotel\t|  " << printStars(hif[i]) << endl;
		cout << "|-------------------------------|" << endl;
	}

	string input_hotel;
	choose:
		double temp = 1.0;
	cout << "\n" <<
		"Input your favorite hotel name: ";
	cin >> input_hotel;
	cout << endl;
	for (int i = 0; i < size(); i++)
	{
		if (toUpWord(hif[i].hotelname) == toUpWord(input_hotel))
		{
			cout << "\t" << hif[i].hotelname << " Hotel " << printStars(hif[i]) << endl;
			cout << "_______________________________" << endl;
			if (hif[i].singlRoom > 0)
			{
				cout << "   SGL  | " << hif[i].singlRoom << "  | " << hif[i].SGLprice << " AMD" << endl;
				cout << "_______________________________" << endl;
			}

			if (hif[i].twinRoom > 0)
			{
				cout << "   TWN  | " << hif[i].twinRoom << " | " << hif[i].SGLprice *1.5 << " AMD" << endl;
				cout << "_______________________________" << endl;
			}
			if (hif[i].trplRoom > 0)
			{
				cout << "   TRPL | " << hif[i].trplRoom << "  | " << hif[i].SGLprice *2.5 << " AMD" << endl;
				cout << "_______________________________" << endl;
			}
			if (hif[i].vipRoom > 0)
			{
				cout << "   VIP  | " << hif[i].vipRoom << "  | " << hif[i].SGLprice * 3 << " AMD" << endl;
				cout << "_______________________________" << endl;
			}
			cout << endl;
			string ans = "";
			tryA:
				cout << "Do You want to book a room?(yes/no) ";
			cin >> ans;
			if (ans == "yes")
			{

				regionROOM: int count = 0;
				string troom = "";
				int croom = 0;
				bool a = false;

				cout << "Input your room type(SGL/TWN/TRPL/VIP): ";
				cin.ignore();
				cin >> troom;

				int sumfinish = 0;
				struct checkinUser chechin_User_arr[size("userFile.txt")];
				string checkinRooms[3];
				string ltr = "";
				ifstream ifsf("userFile.txt");
				int x = 0, y = 0;
				while (!ifsf.eof())
				{
					ifsf >> ltr;
					checkinRooms[x] = ltr;
					x++;
					if (x == 3)
					{
						chechin_User_arr[y].strHotelName = checkinRooms[0];
						chechin_User_arr[y].strRoomType = checkinRooms[2];
						chechin_User_arr[y].roomCount = stoi(checkinRooms[1]);
						y++;
						x = 0;
					}
				}

				if (toUpWord(troom) == "SGL")
				{

					for (int j = 0; j<size("userFile.txt"); j++)
					{
						sumfinish += checkRoomCount(hif[i].hotelname, troom, chechin_User_arr[j]);
					}
					count = hif[i].singlRoom - sumfinish;
					cout << "\n|Check-in  rooms count\t|\tFree rooms|\n__________________________________________|\n|\t" << sumfinish << "\t\t|\t" << count << "\t|\n" << endl;

					cout << "How many rooms you want book: ";
					cin >> croom;
					if (count >= 0 && count >= croom)
					{
						addFile(input_hotel, troom, croom);
					}
					else
					{

						cout << "Sorry!!! We have " << count << " " << toUpWord(troom) << " rooms are free:\n";
					}

					if (goToRegion())
					{
						goto regionROOM;
					}
				}
				else if (toUpWord(troom) == "TWN")
				{
					for (int j = 0; j<size("userFile.txt"); j++)
					{
						sumfinish += checkRoomCount(hif[i].hotelname, troom, chechin_User_arr[j]);
					}
					count = hif[i].twinRoom - sumfinish;
					cout << "\n|Check-in  rooms count\t|\tFree rooms|\n__________________________________________|\n|\t" << sumfinish << "\t\t|\t" << count << "\t|\n" << endl;

					cout << "How many rooms you want book: ";
					cin >> croom;
					if (count >= 0 && count >= croom)
					{
						addFile(input_hotel, troom, croom);
					}
					else
					{

						cout << "Sorry!!! We have " << count << " " << toUpWord(troom) << " rooms are free:\n";
					}

					if (goToRegion())
					{
						goto regionROOM;
					}
				}
				else if (toUpWord(troom) == "TRPL")
				{
					for (int j = 0; j<size("userFile.txt"); j++)
					{
						sumfinish += checkRoomCount(hif[i].hotelname, troom, chechin_User_arr[j]);
					}
					count = hif[i].trplRoom - sumfinish;
					cout << "\n|Check-in  rooms count\t|\tFree rooms|\n__________________________________________|\n|\t" << sumfinish << "\t\t|\t" << count << "\t|\n" << endl;

					cout << "How many rooms you want book: ";
					cin >> croom;
					if (count >= 0 && count >= croom)
					{
						addFile(input_hotel, troom, croom);
					}
					else
					{

						cout << "Sorry!!! We have " << count << " " << toUpWord(troom) << " rooms are free:\n";
					}

					if (goToRegion())
					{
						goto regionROOM;
					}
				}
				else if (toUpWord(troom) == "VIP")
				{
					for (int j = 0; j<size("userFile.txt"); j++)
					{
						sumfinish += checkRoomCount(hif[i].hotelname, troom, chechin_User_arr[j]);
					}
					count = hif[i].vipRoom - sumfinish;
					cout << "\n|Check-in  rooms count\t|\tFree rooms|\n__________________________________________|\n|\t" << sumfinish << "\t\t|\t" << count << "\t|\n" << endl;

					cout << "How many rooms you want book: ";
					cin >> croom;
					if (count >= 0 && count >= croom)
					{
						addFile(input_hotel, troom, croom);
					}
					else
					{

						cout << "Sorry!!! We have " << count << " " << toUpWord(troom) << " rooms are free:\n";
					}

					if (goToRegion())
					{
						goto regionROOM;
					}
				}
				else
				{
					goto regionROOM;
				}
			}
			else if (ans == "no")
			{
				goto choose;
			}
			else
			{
				goto tryA;
			}
		}
	}

	return 0;
}
string printStars(hotelInfo c)
{
	string str = "";
	int star = c.starrate;
	for (int i = 0; i < star; i++)
	{
		str += "*";
	}
	return str;
}
