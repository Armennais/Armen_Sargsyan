#include <iostream>
using namespace std;
 
void swap(int *num1, int *num2) {
   int temp;
   
   temp = *num1;
   *num1 = *num2;
   *num2 = temp;
}
 
int main() {
   int num1, num2;
 
   cout<<"Enter the number 1 : ";
   cin>>num1;
   cout<<"Enter the number 2 : ";
   cin>>num2;
 
   swap(&num1, &num2);
 
   cout<<"\nnumber 1 : "<< num1 << "\nnumber 2 : "<< num2;
 
   return (0);
}
