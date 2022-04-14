class Poly
{
private:
	double* m_coefArr;
	int m_arrSize;

public:
	Poly();
	Poly(int degree);
	Poly(double* coefArr, int coefCount);
	Poly(Poly& other);
	~Poly();

	Poly Add(Poly& other);
	Poly Subtract(Poly& other);
	Poly Multiply(Poly& other);

	int degree();
	void at(double value);

	void displayPoly();
};
