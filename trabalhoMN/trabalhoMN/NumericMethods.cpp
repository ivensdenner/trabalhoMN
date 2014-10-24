#include "NumericMethods.h"
#include <cmath>


float newtonRaphson(Polynomial polynomial, float x0, float error1, float error2, int maxInter)
{
	float x1;
	float root;
	bool rootFound = false;
	int k;

	if (fabsf(polynomial.getResult(x0)) < error1)
	{
		root = x0;
		rootFound - true;
	}
	
	k = 1;
	while (!rootFound)
	{
		x1 = x0 - (polynomial.getResult(x0) / polynomial.derivative(x0));
		if (fabsf(polynomial.getResult(x1)) < error1 || fabsf(x1 - x0) < error2 || k >= maxInter)
		{
			root = x1;
			rootFound = true;
		}
		
		x0 = x1;
		k++;
	}
	
	return root;
}
