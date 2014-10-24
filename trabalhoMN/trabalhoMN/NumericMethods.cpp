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
