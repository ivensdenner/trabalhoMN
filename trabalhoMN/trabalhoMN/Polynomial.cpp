#include "Polynomial.h"
#include <cmath>


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


float Polynomial::getResult(float x)
{
	float result = 0;

	for (int i = 0; i <= degree; i++)
		result += coefficients[i] * powf(x, i);

	return result;
}


float Polynomial::derivative(float x)
{
	// XXX A função abaixo é temporária!! A definitia é a do Esdras!
	return ((4 * coefficients[4] * powf(x, 3)) + (3 * coefficients[3] * powf(x, 2)) + (2 * coefficients[2] * x) + coefficients[1]);
	//return ((3 * coefficients[3] * powf(x, 2)) + (2 * coefficients[2] * x) + coefficients[1]);
}
