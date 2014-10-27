#ifndef MENU_H
#define MENU_H


class Menu
{
public:
	Menu();
	~Menu();

	void start();
	bool to_exit();
	bool has_guess();

	int get_n();
	double * get_bk(int i);
	double get_guess();
	void set_guess(double _guess);
	double get_error1();
	double get_error2();
	int get_max_iter();

private:
	int n;
	double **bk;
	double guess;
	double error1;
	double error2;
	int maxInter;
	bool exit; // Flag que define se o programa deve ser encerrado ou nao
	bool h_guess; // Flag que indica se o usuario entrou com um chute inicial
};

#endif // MENU_H
