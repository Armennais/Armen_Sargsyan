#include<string.h> 
#include<iostream>  
using namespace std;

void Lower_case(char str[]);
bool isPalindrome(char str[]);

int main() {
    char str1[50];
    cout << "Input: ";
    cin >> str1;
    if(isPalindrome(str1))
    {
	cout <<	"True \n";
    }else
    {
 	cout << "False \n";
    }

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

bool isPalindrome(char str[]) {

    int l = 0;
    int h = strlen(str) - 1;

    Lower_case(str);
    cout << "Output: ";
    while (h > l) {
        if (str[l++] != str[h--]) {
            return false;
            
        }
    }
    return true;
}
