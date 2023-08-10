#include <iostream>
#include <fstream>
using namespace std;

int l(string);
void translate(string);
int main()
{
    string source, a;
    cout << "Choose the language\n\t 1 -> hy - en \n\t 2 -> en - hy" << endl;
    cin >> source;
    if (source == "1") {
        a = "hy-en.txt";
    }
    else if (source == "2") {
        a = "en-hy.txt";
    }
    else {
        cout << "Input 1 or 2";
        return 0;
    }
    bararan(a);
    return 0;
}

void bararan(string a)
{
    ifstream ifn;
    string input;
    cout << "Enter the word: ";
    cin.ignore();
    getline(cin, input);
    string str = "";
    int count = 0;
    string path = "translater.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    int len_of = 0;
    ifstream ifn1(a);
    while (!ifn1.eof()) {
        string str = " ";
        ifn1 >> str;
        len_of++;
    }

    string s_array[len_of];
    int il = l(input);
    string inputarray[il];
    int k = 0;
    string arr = "";
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ') {
            arr += input[i];
        }
        else if (input[i] == ' ') {
            inputarray[k] = arr;
            k++;
            arr = "";
        }
    }
    inputarray[k] = arr;
    if (!fs.is_open()) {
        cout << "File  closed";
    }
    else {
        int j = 0;
        for (int z = 0; z < il; z++) {
            ifn.open(a);
            while (!ifn.eof()) {
                str = " ";
                ifn >> str;
                s_array[j] = str;
                j++;
            }
            for (int i = 0; i < len_of; i++) {
                if (inputarray[z] == s_array[i]) {
                    fs << s_array[i + 2] << " ";
                }
            }
        }
    }
}
int l(string a)
{
    int n = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == ' ') {
            n++;
        }
    }
    return n + 1;
}
