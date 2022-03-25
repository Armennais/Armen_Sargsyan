#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum weekD{
  Mon = 1,
  Tue,
  Wed,
  Thu,
  Fry,
  Sut,
  Sun
};

struct data{
    string dataDate = "";
    string Note = "";
    string command = "";
};
 
void  toStr(string, int *, int *, int * );
int weekDay(int,int,int);
bool isEmpty(string);




int main()
{   
    int dd = 0,mm  = 0,yy = 0; 
    string checkinp = "";
    struct data datainput;
    while(true)
    {

        cout << "Enter day: ";
        cin >> datainput.dataDate;
        cout << "Enter Note:";
    cin.ignore();
    getline(cin,datainput.Note);
    toStr(datainput.dataDate,&dd,&mm, &yy);
    string dayname = "";      
    int wday1 = weekDay(dd,mm,yy);
    weekD wday=(weekD) wday1;
    switch(wday)
      {  
         case Mon: { dayname = "Monday"; break;}
         case Tue: { dayname = "Tuesday"; break;}
         case Wed: { dayname = "Wednesday"; break;}
         case Thu: { dayname = "Thusday"; break;}
         case Fry: { dayname = "Friday"; break;}
         case Sut: { dayname = "Suturday"; break;}
         case Sun: { dayname = "Sunday"; break;}
     }
//adding file part
     string path = to_string(dd) + "_" + to_string(mm) + "_" + to_string(yy)+".txt";
     fstream fs;
     fs.open(path, fstream::in | fstream::out | fstream::app);
     if (!fs.is_open()) {
         cout << "File  closed";
     }else {
         
        if (isEmpty(path))
        {
             fs << dayname <<"\t" <<  datainput.dataDate <<  "\t" <<  datainput.Note << "\n";
        } 
        else
        {
        fs << "\t\t\t" <<  datainput.Note << "\n";
        
        }
    }

    cout << "Command: add/exit ";
    cin >> datainput.command;
    if(datainput.command == "add")
    {
        continue;
    }else if(datainput.command == "exit")
    {
        return 0;
    }else
    {
        cout << "Enter Command: add/exit: ";
        cin >> datainput.command;
    }
    
    }
    return 0;
}


int weekDay(int dd,int mm,int yy)
{
    int rst = dd + ((153 * (mm + 12 * ((14 - mm) / 12) - 3) + 2) / 5) 
        + (365 * (yy + 4800 - ((14 - mm) / 12)))
	+ ((yy + 4800 - ((14 - mm) / 12)) / 4)
	- ((yy + 4800 - ((14 - mm) / 12)) / 100)
	+ ((yy + 4800 - ((14 - mm) / 12)) / 400)
	- 32045;

	return (rst+1)%7 ;
}

void  toStr(string a,int *x, int *y, int* z)
{
    string d = "";
    string  dd = "";
    string  mm = "";
    string  yy = "";
    int c = 0;
    for(int i = 0; a[i] !='\0'; i++)
    {
       if(a[i] !='/')
       {
           d += a[i];
          c++;
       }
       else if((c == 1 || c == 2) && a[i] == '/')
       {

           if(d[0] == '0' && c == 2)
           {
               dd =d[1];
               d = " ";
           }
           else{
           dd = d;
           d="";
           }
       }
       else if((c >=2 && c <= 4) && a[i] == '/')
       {
        if(d[0] == '0' && c == 4)
            {
                mm =d[1];
               d = " ";
            }
            else{
          mm = d;
            d="";
            
       }
       
    }
    }
    yy = d;
    *x= stoi(dd);
    *y = stoi(mm);
    *z = stoi(yy);
}

bool isEmpty(string path)
{
     fstream fs;
     string str = "";

     fs.open(path, fstream::in | fstream::out | fstream::app);

    while (!fs.eof()) {

                 fs >> str;
 
             }
 
          if(str == "")
           {
           return true;
           }
           else {
 
           return false;
           }

}
