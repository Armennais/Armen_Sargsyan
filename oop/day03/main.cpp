#include <iostream> 
#include "poly.h"
using namespace std;
 
int main()
{
   Polynomial a, b, c, t;
 
   a.enterTerms();
   b.enterTerms();
   t = a;  
   cout << "First polynomial is:\n";
   a.printPolynomial();
   cout << "Second polynomial is:\n";
   b.printPolynomial();
   cout << "\nAdding :\n";
   c = a + b;
   c.printPolynomial();
   cout << "\n+= :\n";
   a += b;
   a.printPolynomial();
   cout << "\nSubtracting :\n";
   a = t;  
   c = a - b;
   c.printPolynomial();
   cout << "\n-= the polynomials:\n";
   a -= b;
   a.printPolynomial();
   cout << "\nMultiplying :\n";
   a = t;  
   c = a * b;
   c.printPolynomial();
   cout << "\n*= :\n";
   a *= b;
   a.printPolynomial();
   cout << endl;
} 
