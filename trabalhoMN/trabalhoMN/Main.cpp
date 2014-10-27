#include "Menu.h"
#include "Bridge.h"
#include <iostream>
#include "NumericMethods.h"


int main()
{
	Menu menu;
	Bridge *bridge = NULL;
	Polynomial *polynomial = NULL;
	double c1; // Recebe o comprimento calculado usando Newton_Rahson
	double c2; // Recebe o comprimento calculado usando Newton_Pol

	while (menu.to_exit() == false)
	{
		menu.start();
		if (menu.to_exit() == false)
		{
			for (int i = 0; i < menu.get_n(); i++)
			{
				polynomial = new Polynomial(4, menu.get_bk(i));
				bridge = new Bridge(polynomial);

				if (menu.has_guess() == false)
				{
					menu.set_guess(isolamento(polynomial));
				}

				std::cout << "------------------------------------------------------------------" << std::endl;
				std::cout << "Opcao " << (i + 1) <<": b4=" << polynomial->getCoefficient(4)
					<< ", b3=" << polynomial->getCoefficient(3)
					<< ", b2=" << polynomial->getCoefficient(2)
					<< ", b1=" << polynomial->getCoefficient(1)
					<< ", b0=" << polynomial->getCoefficient(0) << std::endl;
				std::cout << "Calculando valor de c utilizando Newton Original..." << std::endl;
				c1 = bridge->calculate_lenght(NEWTON_RAPHSON, menu.get_guess(), menu.get_error1(), menu.get_error2(), menu.get_max_iter());
				std::cout << "c = " << c1 << " metros." << std::endl << std::endl;

				std::cout << "Calculando valor de c utilizando Newton p/ Polinomios..." << std::endl;
				c2 = bridge->calculate_lenght(NEWTON_POL, menu.get_guess(), menu.get_error1(), menu.get_error2(), menu.get_max_iter());
				std::cout << "c = " << c2 << " metros." << std::endl << std::endl;

				delete polynomial;
				delete bridge;
			}
		}
	}

	return 0;
}
