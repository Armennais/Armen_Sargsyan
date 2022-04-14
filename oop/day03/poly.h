#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
 
class Polynomial
{
public:
   static const int maxTerms = 100; 
 
   Polynomial();
   Polynomial operator+( const Polynomial & ) const; 
   Polynomial operator-( const Polynomial & ) const; 
   Polynomial operator*( const Polynomial & ) const; 
   Polynomial &operator=( const Polynomial & ); 
   Polynomial &operator+=( const Polynomial & );
   Polynomial &operator-=( const Polynomial & );
   Polynomial &operator*=( const Polynomial & );
   void enterTerms();
   void printPolynomial() const;
   int getNumberOfTerms() const; 
   int getTermExponent( int ) const;
   int getTermCoefficient( int ) const;
   void setCoefficient( int, int ); 
   ~Polynomial(); 
private:
   int numberOfTerms;
   int exponents[ maxTerms ]; 
   int coefficients[ maxTerms ]; 
   static void polynomialCombine( Polynomial & ); 
}; 
 
#endif