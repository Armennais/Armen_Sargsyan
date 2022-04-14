#include <iostream>
#include "bazmandam.h"

using namespace std;

Poly::Poly()
{
	m_arrSize = 1;
	m_coefArr = new double[1];
	m_coefArr[0] = 0;
}

Poly::Poly(int degree)
{
	m_arrSize = degree + 1;
	m_coefArr = new double[m_arrSize];
	for (int i = 0;i < m_arrSize; i++)
	{
		m_coefArr[i] = 0;
	}
}

Poly::Poly(double* coefArr, int coefCount)
{
	m_arrSize = coefCount;
	m_coefArr = new double[coefCount];
	for (int i = 0; i < coefCount; i++)
	{
		m_coefArr[i] = coefArr[i];
	}
}
Poly::Poly(Poly& other)
{
	m_arrSize = other.m_arrSize;
	m_coefArr = new double[m_arrSize];
	for (int i = 0; i < m_arrSize; i++)
	{
		m_coefArr[i] = other.m_coefArr[i];
	}
}
Poly::~Poly()
{
	delete[] m_coefArr;
	m_arrSize = 0;
	m_coefArr = nullptr;
}

Poly Poly::Add(Poly& other)
{
	int sizeOfAnswer = (m_arrSize >= other.m_arrSize) ? m_arrSize : other.m_arrSize;
	Poly answer(sizeOfAnswer - 1);
	if(m_arrSize >= other.m_arrSize)
	{
		for (int i = 0; i <  other.m_arrSize; i++)
		{
			answer.m_coefArr[i] = m_coefArr[i] + other.m_coefArr[i];
		}
		for (int i = other.m_arrSize; i < m_arrSize; i++)
		{
			answer.m_coefArr[i] = m_coefArr[i];
		}	
	}else
	{
		for (int i = 0;i < m_arrSize; i++)
		{
			answer.m_coefArr[i] = m_coefArr[i] + other.m_coefArr[i];
		}
		for (int i = m_arrSize;i < other.m_arrSize; i++)
		{
			answer.m_coefArr[i] = other.m_coefArr[i];
		}
	}
	return answer;
}

Poly Poly::Subtract(Poly& other)
{
	int sizeOfAnswer = (m_arrSize >= other.m_arrSize) ? m_arrSize : other.m_arrSize;
	        Poly answer(sizeOfAnswer - 1);
		if(m_arrSize >= other.m_arrSize)
		{
			for (int i = 0; i <  other.m_arrSize; i++)
			{
				answer.m_coefArr[i] = m_coefArr[i] + other.m_coefArr[i];
			}
			for (int i = other.m_arrSize; i < m_arrSize; i++)
			{
				answer.m_coefArr[i] = m_coefArr[i];
			}
		}else
		{
			for (int i = 0;i < m_arrSize; i++)
			{
				answer.m_coefArr[i] = m_coefArr[i] + other.m_coefArr[i];
			}
			for (int i = m_arrSize;i < other.m_arrSize; i++)
			{
				answer.m_coefArr[i] = other.m_coefArr[i];
			}
		}
		return answer;
}
Poly Poly::Multiply(Poly& other)
{
	int degreeOfAnswer = m_arrSize + other.m_arrSize - 2;
	Poly answer(degreeOfAnswer);
	for( int i = 0; i < m_arrSize; i++)
	{
		for( int j = 0; j < other.m_arrSize; j++)
		{
			answer.m_coefArr[i + j] += (m_coefArr[i] * other.m_coefArr[j]);
		}
	}
	return answer;
}

int Poly::degree() { return m_arrSize - 1; }

void Poly::displayPoly()
{
	int i;
	for (i = m_arrSize - 1; i >= 1; i--)
	{
		if (m_coefArr[i] != 0)
		{
			cout << m_coefArr[i] << "x^" << i << " + ";
		}
	}
	cout << m_coefArr[0];
	cout << endl;
}
























