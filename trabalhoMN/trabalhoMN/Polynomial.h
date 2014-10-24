#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


class Polynomial
{
public:
	Polynomial(int _degree);
	virtual ~Polynomial();

	int getDegree();
	double * getCoefficients();
	double getCoefficient(int index);
	void setCoefficient(double value, int index);
	double funcao(double x);
	double* derivadaSimbolica();
	double derivadaNumerica(double x);

private:
	int degree;
	double *coefficients;
};

#endif // POLYNOMIAL_H
