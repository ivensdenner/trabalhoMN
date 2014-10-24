#include "Polynomial.h"


Polynomial::Polynomial(int _degree)
{
	degree = _degree;
	coefficients = new float[degree + 1];

	for (int i = 0; i <= degree; i++)
	{
		coefficients[i] = 1;
	}
}


Polynomial::~Polynomial()
{
	delete coefficients;
}


int Polynomial::getDegree()
{
	return degree;
}


float * Polynomial::getCoefficients()
{
	return coefficients;
}


float Polynomial::getCoefficient(int index)
{
	if (index <= degree && index >= 0)
		return coefficients[index];
	else
		return 0;
}


void Polynomial::setCoefficient(float value, int index)
{
	if (index <= degree && index >= 0)
		coefficients[index] = value;
}
