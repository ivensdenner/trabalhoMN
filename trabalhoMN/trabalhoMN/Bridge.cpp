#include "Bridge.h"
#include "NumericMethods.h"


Bridge::Bridge(Polynomial *_polynomial) : polynomial(*_polynomial)
{
}


Bridge::~Bridge()
{
}


double Bridge::calculate_lenght(METHOD method, double x0, double error1, double error2, int maxInter)
{
	if (method == NEWTON_RAPHSON)
	{
		return (2 * newton_raphson(&polynomial, x0, error1, error2, maxInter));
	}
	else
	{
		return (2 * newton_pol(&polynomial, x0, error1, maxInter));
	}
}
