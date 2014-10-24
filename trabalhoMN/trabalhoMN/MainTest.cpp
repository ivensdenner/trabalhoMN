#include <iostream>
#include "Polynomial.h"
#include "NumericMethods.h"
#include "Polynomial.h"


int main(int argc, char **argv)
{
	Polynomial *polynomial;
	int degree;

	std::cout << "Digite o grau do polinomio: ";
	std::cin >> degree;
	degree = 4;

	polynomial = new Polynomial(degree);
	std::cout << "Digite os coeficientes: ";
	for (int i = 0; i <= degree; i++)
	{
		std::cout << "Digite o coeficiente " << i << ": ";
		double coef;
		std::cin >> coef;
		polynomial->setCoefficient(coef, i);
	}

	double root = newtonRaphson(polynomial, 2, 0.0001, 0.0001, 50);
	std::cout << "Raiz: " << root << std::endl;
	//std::cout << "Resultado: " << polynomial->derivadaNumerica(2) << std::endl;

	system("pause");

	return 0;
}
