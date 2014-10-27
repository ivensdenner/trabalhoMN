#include "Menu.h"
#include <iostream>


Menu::Menu()
{
	guess = 0;
	error1 = 0;
	error2 = 0;
	maxInter = 10; // TODO Permtir que o usuario defina o numero maximo de iteracoes
	exit = false;
	h_guess = false;
	n = 0;
	bk = NULL;
}


Menu::~Menu()
{
	for (int i = 0; i < n; i++)
		delete[] bk[i];
	delete[] bk;
}


void Menu::start()
{
	int opcao;

	std::cout << "Trabalho de Metodos Numericos" << std::endl;
	std::cout << "1 - Entrar com chute inicial" << std::endl;
	std::cout << "2 - Executar sem chute inicial" << std::endl;
	std::cout << "0 - Sair" << std::endl;

	do
	{
		std::cout << "Opcao: ";
		std::cin >> opcao;
	} while (opcao < 0 || opcao > 2);

	switch (opcao)
	{
	case 1:
		std::cout << "Digite o chute incial: ";
		std::cin >> guess;
		h_guess = true;
		break;

	case 2:
		h_guess = false;
		break;

	default:
		exit = true;
		break;
	}


	if (!exit)
	{
		std::cout << "Digite o numero de opcoes: ";
		std::cin >> n;

		if (bk != NULL)
		{
			for (int i = 0; i < n; i++)
				delete[] bk[i];
			delete[] bk;
		}
		bk = new double*[n]; // Alocando espaco para os Bk's das n opcoes
		for (int i = 0; i < n; i++)
		{
			bk[i] = new double[5];
		}

		for (int i = 0; i < n; i++)
		{
			std::cout << "Opcao " << (i + 1) << std::endl;
			for (int j = 0; j <= 4; j++)
			{
				std::cout << "Digite o valor para b" << j << ": ";
				std::cin >> bk[i][j];
			}
		}

		std::cout << "Precisao" << std::endl;
		std::cout << "Digite um valor para e1: ";
		std::cin >> error1;
		std::cout << "Digite um valor para e2: ";
		std::cin >> error2;
	}
}


bool Menu::to_exit()
{
	return exit;
}


bool Menu::has_guess()
{
	return h_guess;
}


int Menu::get_n()
{
	return n;
}


double * Menu::get_bk(int i)
{
	if (i >= 0 && i < n)
	{
		return bk[i];
	}
	else
	{
		return NULL;
	}
}


double Menu::get_guess()
{
	return guess;
}


void Menu::set_guess(double _guess)
{
	guess = _guess;
}


double Menu::get_error1()
{
	return error1;
}


double Menu::get_error2()
{
	return error2;
}


int Menu::get_max_iter()
{
	return maxInter;
}
