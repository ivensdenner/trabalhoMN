#ifndef NUMERIC_METHODS
#define NUMERIC_METHODS

#include "Polynomial.h"

double newtonRaphson(Polynomial *polynomial, double x0, double error1, double error2, int maxInter);
double newton_pol(int a[], double x, double e1, int itermax);

#endif // NUMERIC_METHODS
