#include <iostream>
#include <string>
using namespace std;
void swap(char* a, char* b);
int main()
{
    string num;

    int a,b;
    cout << "Input number: ";
    //Imput array elements
    cin >> num;
    cout << endl << "Input position to swap: ";
    
    cin >> a >> b;
    
    //check that 'a' and 'b' is in range
    if ((a < 0 || a > num.size()) || (b < 0 || b > num.size()))
    {
        do
        {
            cout << "Out of range,try again: ";
            cin >> a >> b;
        }while((a < 0 || a > num.size()) || (b < 0 || b > num.size()));
    }
    //this for negative numbers
    if (num[0] == '-')
    {
        a += 1;
        b += 1;
    }
    
    swap(&num[a-1],&num[b - 1]);
    cout << "Output: " << num << endl;
    return 0;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
