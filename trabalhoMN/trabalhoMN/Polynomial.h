#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


class Polynomial
{
public:
	Polynomial(int _degree);
	virtual ~Polynomial();

	int		getDegree();
	float *	getCoefficients();
	float	getCoefficient(int index);
	void	setCoefficient(float value, int index);
	float	derivative(Polynomial polynomial); // Função do Esdras

private:
	int		degree;
	float	*coefficients;
};

#endif // POLYNOMIAL_H
