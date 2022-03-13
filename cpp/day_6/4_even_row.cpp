#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
 

 
 
int main () 
{
    srand(time(0));
    const int m = 15, n = 2;
    int num = 0;
    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
 
    
    
    bool check = true;
   for (int i = 0; i < m; i++) {
       for (int j = 0; j < n; j++) {
           if (matrix[i][j] % 2 == 0) {
               num++;
           }
       }
       if (num == n) {
           cout <<"Even row = ";        
           for (int k = 0; k < n; k++) {
               cout << matrix[i][k] << " ";
           }
           check = false;
           break;
       }
       num = 0;
   }
   if (check) {
       cout << "No";
   }
   cout << endl;
    return 0;
    
}
