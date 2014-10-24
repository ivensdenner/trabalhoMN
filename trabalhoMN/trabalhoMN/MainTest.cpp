#include <iostream>
#include "Polynomial.h"
#include "NumericMethods.h"


int main(int argc, char **argv)
{
	Polynomial *polynomial;
	int degree;

	std::cout << "Digite o grau do polinomio: ";
	std::cin >> degree;

	polynomial = new Polynomial(degree);
	std::cout << "Digite os coeficientes: ";
	for (int i = 0; i <= degree; i++)
	{
		std::cout << "Digite o coeficiente " << i << ": ";
		float coef;
		std::cin >> coef;
		polynomial->setCoefficient(coef, i);
	}

	float root = newtonRaphson(polynomial, 0.5, 0.0001, 0.0001, 5);
	std::cout << "Raiz: " << root << std::endl;

	system("pause");

	return 0;
}
