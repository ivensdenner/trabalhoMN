#ifndef NUMERIC_METHODS_H
#define NUMERIC_METHODS_H

#include "Polynomial.h"

double newton_raphson(Polynomial *polynomial, double x0, double error1, double error2, int maxInter);
double newton_pol(Polynomial *polynomial, double x, double e1, int itermax);

#endif // NUMERIC_METHODS_H
