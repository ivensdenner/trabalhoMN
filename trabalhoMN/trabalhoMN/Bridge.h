#ifndef BRIDGE_H
#define BRIDGE_H

#include "Polynomial.h"
#define NEWTON_RAPHSON 0
#define NEWTON_POL 1
typedef int METHOD;


class Bridge
{
public:
	Bridge(Polynomial *_polynomial);
	~Bridge();

	double calculate_lenght(METHOD method, double x0, double error1, double error2, int maxInter);

private:
	Polynomial polynomial;
};

#endif // BRIDGE_H
