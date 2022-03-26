#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "combinatorika_header.h"
#include "ordinaryFractions_header.h"
#include "matstatic_header.h"
#include "matrix_header.h"
#include "polynomial_header.h"
#include "function_header.h"

using namespace std;


int SDL_main(int argc, char* argv[])
{
	setlocale(0, "");

	int inp, inp2;

	do {
		cout << "1 - Калькулятор формул комбинаторики" << endl;
		cout << "2 - Матричный калькулятор" << endl;
		cout << "3 - Тер.вер. и мат. статистика" << endl;
		cout << "4 - Калькулятор обыкновенных дробей" << endl;
		cout << "5 - Работа с функциями" << endl;
		cout << "6 - Калькулятор многочленов" << endl;
		cout << "Выберите калькулятор: ";
		cin >> inp;

		switch (inp) {
		case 1:
			combinatorika_main();// калькулятор формул комбинаторики
			break;
		case 2:
			matrix_main();// матричный калькулятор
			break;
		case 3:
			verr();// Тер.вер. и мат. статистика
			break;
		case 4:
			drobi();// калькулятор обыкновенных дробей
			break;
		case 5:
			Menu();// работа с функциями
			break;
		case 6:
			MenuPolynomial();// калькулятор многочленов
			break;
		default: cout << "Неверный ввод, введите 1, 2, 3, 4, 5 или 6" << endl;
		}
		cout << "Вернуться к выбору калькулятора? 0 - завершить программу, продолжить - любое другое число" << endl;
		cout << "Введите: ";
		cin >> inp2;
		system("cls");
	} while (inp2 != 0);


	return 1;
}

