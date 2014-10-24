#include "Polynomial.h"
#include <cmath>


Polynomial::Polynomial(int _degree)
{
	degree = _degree;
	coefficients = new double[degree + 1];

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


double * Polynomial::getCoefficients()
{
	return coefficients;
}


double Polynomial::getCoefficient(int index)
{
	if (index <= degree && index >= 0)
		return coefficients[index];
	else
		return 0;
}


void Polynomial::setCoefficient(double value, int index)
{
	if (index <= degree && index >= 0)
		coefficients[index] = value;
}


double Polynomial::funcao(double x)
{
	double fdex = 0;

	for (int i = 0; i <= degree; i++)
		fdex += coefficients[i] * pow(x, i);

	return fdex;
}


double* Polynomial::derivadaSimbolica()
{
	double *der = new double[degree - 1];

	for (int i = 1; i <= degree; i++)
		der[i - 1] = i * coefficients[i];

	return der;
}


double Polynomial::derivadaNumerica(double x)
{
	double h = pow(2.0, -20.0);

	double der = (funcao(x + h) - funcao(x)) / h;

	return der;
}
