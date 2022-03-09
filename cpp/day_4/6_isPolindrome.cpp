#include<string.h> 
#include<iostream>  
using namespace std;

void Lower_case(char str[]);
void isPalindrome(char str[]);

int main() {
    char str1[50];
    cout << "Input: ";
    cin >> str1;
    isPalindrome(str1);

    return 0;
}

void Lower_case(char str[]){
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
        i++;
    } 
} 

void isPalindrome(char str[]) {

    int l = 0;
    int h = strlen(str) - 1;

    Lower_case(str);
    cout << "Output: ";
    while (h > l) {
        if (str[l++] != str[h--]) {
            cout << "False\n";
            return;
        }
    }
    cout << "True \n";
}
