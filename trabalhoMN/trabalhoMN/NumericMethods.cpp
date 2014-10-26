#include "NumericMethods.h"
#include <cmath>
#include <iostream>


double newtonRaphson(Polynomial *polynomial, double x0, double error1, double error2, int maxInter)
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


double newton_pol(int a[], double x, double e1, int itermax)
{
	double b, c, raiz, deltax;

	deltax = x;
	for (int k = 1; k < itermax; k++){
		b = a[0];
		c = b;

		for (int i = 1; i <= 3; i++){ //o laço vai de 1 até a penultima posição do vetor, que nesse caso é 3
			b = a[i] + b*x;
			c = b + c*x;
		}

		b = a[4] + b*x; //ela considera a[4] já sendo o ultima posição do vetor

		if (abs(b) < e1){
			raiz = x;
			std::cout << "atingiu o erro\n";//linha só pra controle de erro, pode ser retirada
			return raiz;
		}


		deltax = b / c;
		x = x - deltax;
		std::cout << x << "\n"; //linha mostrando o x em cada iteração, pode ser retirada tbm

		//if (abs(deltax) < erro2){
		//	raiz = x;
		//	return raiz;
		//}
	}

	raiz = x;
	std::cout << "não convergiu depois de " << itermax << "iterações";
	return raiz;
}
