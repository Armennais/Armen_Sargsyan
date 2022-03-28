#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct info {
    string countryName;
    string capital;
    string domain;
    int population;
    int area;
    int gdp;
    int phonecode;
};
enum enum1 {
    Armenia = 374,
    Brazil = 55,
    Chile = 56,
    Turkey = 90,
    Albania = 355,
    Belarus = 375,
    Iran = 98
};
int main(int argc, char* argv[])
{
    enum1 en;
    int earr[7] = { Armenia, Brazil, Chile, Turkey, Albania, Belarus, Iran };
    struct info str_table[7];
    ofstream ofs("countries.txt");
    ofs << "Armenia Yerevan .am 3300000 29743 1260000\n\
                Brazil Brazil .br 1300000 329743 4520000\n\
                Chile Santioago .cl 12000 479743 230000\n\
                Turkey Ankara .tr 778043 780580 821800\n\
                Albania Tirana .al 2987 28748 12800\n\
                Belarus Minsk .by 9685 207600 69240\n\
                Iran Tehran .ir 76924 1648 411900";
    ofs.close();
    string str = "";
    string array_C[6];
    ifstream mfile("countries.txt");
    int i = 0, ind = 0;
    while (!mfile.eof()) {
        mfile >> str;

        array_C[i] = str;
        i++;
        if (i == 6) {
            str_table[ind].countryName = array_C[0];
            str_table[ind].capital = array_C[1];
            str_table[ind].domain = array_C[2];
            str_table[ind].population = stoi(array_C[3]);
            str_table[ind].area = stoi(array_C[4]);
            str_table[ind].gdp = stoi(array_C[5]);
            str_table[ind].phonecode = earr[ind];
            i = 0;
            ind++;
        }
    }

    mfile.close();

    if (strcmp(argv[1], "compare") == 0 ) {
        string n1, n2;
        cout << "Input   first country: ";
        cin >> n1;
        cout << "Input  second country: ";
        cin >> n2;
        int first_index, second_index;
        for (int i = 0; i < 8; i++) {
            if (n1 == str_table[i].countryName) {
                first_index = i;
            }

            if (n2 == str_table[i].countryName) {
                second_index = i;
            }
        }

        cout << "========================================" << endl;
        cout << "\t\t|" << str_table[first_index].countryName << "\t|" << str_table[second_index].countryName << endl;
        cout << "========================================" << endl;
        
        cout << "Capital" << "\t\t|" << str_table[first_index].capital << "\t|" << str_table[second_index].capital << endl;
        
        cout << "Domain" << "\t\t|" << str_table[first_index].domain << "\t\t|" << str_table[second_index].domain << endl;
             
    
        if (str_table[first_index].population > str_table[second_index].population)
        {
            cout << "Population" << "\t|" << str_table[first_index].population << "\t>" << str_table[second_index].population << endl;
        }else if (str_table[first_index].population < str_table[second_index].population)
        {
            cout << "Population" << "\t|" << str_table[first_index].population << "\t<" << str_table[second_index].population << endl;
        }else
        {
            cout << "Population" << "\t|" << str_table[first_index].population << "\t=" << str_table[second_index].population << endl;
        }

        if (str_table[first_index].area > str_table[second_index].area) 
        {
            cout << "Area" << "\t\t|" << str_table[first_index].area << "\t\t>" << str_table[second_index].area << endl;
        }else if (str_table[first_index].area < str_table[second_index].area) 
        {
            cout << "Area" << "\t\t|" << str_table[first_index].area << "\t\t<" << str_table[second_index].area << endl;
        }else 
        {
            cout << "Area" << "\t\t|" << str_table[first_index].area << "\t\t=" << str_table[second_index].area << endl;
        }

        if (str_table[first_index].gdp > str_table[second_index].gdp) 
        {
            cout << "GDP" << "\t\t|" << str_table[first_index].gdp << "\t>" << str_table[second_index].gdp << endl;
        }else if (str_table[first_index].gdp < str_table[second_index].gdp) 
        {
            cout << "GDP" << "\t\t|" << str_table[first_index].gdp << "\t<" << str_table[second_index].gdp << endl;
        }else 
        {
            cout << "GDP" << "\t\t|" << str_table[first_index].gdp << "\t=" << str_table[second_index].gdp << endl;
        }

        cout << "Phone code" << "\t|" << str_table[first_index].phonecode << "\t\t|" << str_table[second_index].phonecode << endl;
    }

    else if (strcmp(argv[1], "search") == 0) {
        string input = "";
        string input1 = "";
        cout << "Input search mode (Country / Capital / domain): ";
        cin >> input;
        cout << "input " << input << ":";
        cin >> input1;

        if (input == "capital") {
            for (int i = 0; i < 7; i++) {
                if (str_table[i].capital == input1) {
                    cout << "Output:  Country - " << str_table[i].countryName << endl;
                    cout << "\t Capital - " << str_table[i].capital << endl;
                    cout << "\t Domain - " << str_table[i].domain << endl;
                    cout << "\t Population - " << str_table[i].population << endl;
                    cout << "\t Area - " << str_table[i].area << endl;
                    cout << "\t GDP - " << str_table[i].gdp << endl;
                    cout << "\t Phone Code - " << str_table[i].phonecode << endl;
                }
            }
        }else if (input == "countryName") {
            for (int i = 0; i < 7; i++) {
                if (str_table[i].countryName == input1) {
                    cout << "Output:  Country - " << str_table[i].countryName << endl;
                    cout << "\t Capital - " << str_table[i].capital << endl;
                    cout << "\t Domain - " << str_table[i].domain << endl;
                    cout << "\t Population - " << str_table[i].population << endl;
                    cout << "\t Area - " << str_table[i].area << endl;
                    cout << "\t GDP - " << str_table[i].gdp << endl;
                    cout << "\t Phone Code - " << str_table[i].phonecode << endl;
                }
            }
        }else if (input == "domain") 
        {
            for (int i = 0; i < 7; i++) 
            {
                if (str_table[i].domain == input1) 
                {
                    cout << "Output:  Country - " << str_table[i].countryName << endl;
                    cout << "\t Capital - " << str_table[i].capital << endl;
                    cout << "\t Domain - " << str_table[i].domain << endl;
                    cout << "\t Population - " << str_table[i].population << endl;
                    cout << "\t Area - " << str_table[i].area << endl;
                    cout << "\t GDP - " << str_table[i].gdp << endl;
                    cout << "\t Phone Code - " << str_table[i].phonecode << endl;
                }
            }
        }else 
        {
            cout << "Please Input search mode (Country / Capital / domain): " << endl;
        }
    }
  }
