#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "function.h"
using namespace std;
bool goToRegion()
{
	        string a;
		cout << "Do you want to book room (yes/no)? ";
		cin >> a;
		if(toUpWord(a) == "YES")
		{
			return true;
		}
		return false;

}
/*string printStars(hotelInfo c)
{
	    string str = "";
	    int star = c.starrate;
	    for (int i = 0; i < star; i++) {
		    str += "*";
	    }
	    return str;
}*/
int size()
{
	    int count = 0;
	    string line;
	    ifstream ifs("info.txt");
	    while (getline(ifs, line)) {
		    ++count;
	    }
	    ifs.close();
	    return count;
}
int size(string path)
{
	int count = 0;
	string line;
	ifstream ifs(path);
	while (getline(ifs, line)) {
		++count;
	}
	ifs.close();
	return count;
}

bool stob(string str)
{
	    transform(str.begin(), str.end(), str.begin(), ::tolower);
	    istringstream is(str);
	    bool b;
	    is >> std::boolalpha >> b;
	    return b;
}
void toStr(string a, int* x, int* y, int* z)
{
	string d = "";
	string dd = "";
	string mm = "";
	string yy = "";
	int c = 0;
	bool b = false;
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] != '/') {
			d += a[i];
			c++;
		 }
		 else if ((c == 1 || c == 2) && a[i] == '/' && b == false) {
                 	if (d[0] == '0') {
	                	dd = d[1];
		        	d = "";
		        	b = true;
		  	}else {
		 		 dd = d;
			 	d = "";
			 	b = true;
		   	}
	           }else if ((c >= 2 && c <= 4) && a[i] == '/' && b == true) {
		         if (d[0] == '0') {
			         mm = d[1];
			          d = "";
			  }else {

				  mm = d;
			  	  d = "";											            	}
		   }
	}		
        yy = d;
	*x = stoi(dd);
	*y = stoi(mm);
	*z = stoi(yy);
}
bool isBig(string date1, string date2)
{

	    int d = 0;
	    int m = 0;
	    int y = 0;
	    int dd = 0;
	    int mm = 0;
	    int yy = 0;
	    toStr(date1, &d, &m, &y);
	    toStr(date2, &dd, &mm, &yy);

	    if (y > yy || (y == yy && m > mm) || (y == yy && m == mm && d >= dd)) {
		    return true;
	    }
	    else {
		    return false;
	    }
}


char to_upper(char a)
{
	    if (a >= 'a' && a <= 'z') {
		            return a - 32;
			        }
	        return a;
}
string toUpWord(string a)
{
	    string b = "";
	    for (int i = 0; a[i] != '\0'; i++) {
		    b += to_upper(a[i]);
	    }
		    return b;
}

void addFile(string h, string rt, int rc)
{
	    string path = "userFile.txt";
	    fstream fs;
	    fs.open(path, fstream::in | fstream::out | fstream::app);
	    if (!fs.is_open()) {
		    cout << "File not found!";
	    }
	    else {
		    string a = h +" " + to_string(rc) + " " + rt ;
		    fs << a << endl;

	    }
	    fs.close();
}




















