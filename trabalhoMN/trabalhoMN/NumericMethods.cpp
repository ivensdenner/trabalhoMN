#include "NumericMethods.h"
#include <cmath>
#include <iostream>


double isolamento(Polynomial *polynomial)
{
	double x0 = 0;
	while ((polynomial->funcao(x0))>1)
		x0 = x0 + 0.1;

	return x0;
}


double newton_raphson(Polynomial *polynomial, double x0, double error1, double error2, int maxInter)
{
	double x1;
	double root;
	bool rootFound = false;
	int k;

	if (fabs(polynomial->funcao(x0)) < error1)
	{
		root = x0;
		rootFound = true;
	}
	
	std::cout << "0" << "\t" << x0 << "\t" << polynomial->funcao(x0) << std::endl;
	k = 1;
	while (!rootFound)
	{
		x1 = x0 - (polynomial->funcao(x0) / polynomial->derivadaNumerica(x0));
		std::cout << k << "\t" << x1 << "\t" << polynomial->funcao(x1) << std::endl;
		if (fabs(polynomial->funcao(x1)) < error1 || fabs(x1 - x0) < error2 || k >= maxInter)
		{
			root = x1;
			rootFound = true;
		}
		
		x0 = x1;
		k++;
	}
	
	return root;
}


double newton_pol(Polynomial *polynomial, double x, double e1, int itermax)
{
	double b, c, raiz, deltax;

	std::cout << "0" << "\t" << x << "\t" << polynomial->funcao(x) << std::endl;

	deltax = x;
	for (int k = 0; k < itermax; k++){
		b = polynomial->getCoefficient(polynomial->getDegree());
		c = b;

		for (int i = (polynomial->getDegree() - 1); i >= 1; i--){ //o laço vai de 1 até a penultima posição do vetor, que nesse caso é 3
			b = polynomial->getCoefficient(i) + b*x;
			c = b + c*x;
		}

		b = polynomial->getCoefficient(0) + b*x; //ela considera a[4] já sendo o ultima posição do vetor

		if (fabs(b) < e1){
			raiz = x;
			std::cout << "atingiu o erro" << std::endl;//linha só pra controle de erro, pode ser retirada
			return raiz;
		}


		deltax = b / c;
		x = x - deltax;
		std::cout << (k + 1) << "\t" << x << "\t" << polynomial->funcao(x) << std::endl;

		if (fabs(deltax) < e1){
			raiz = x;
			return raiz;
		}
	}

	raiz = x;
	std::cout << "nao convergiu depois de " << itermax << "iteracoes" << std::endl;
	return raiz;
}
