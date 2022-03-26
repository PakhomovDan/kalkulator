#include "function_header.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int delay = 5000;

void Menu()
{

	string NumberFunc = "";
	setlocale(0, "");
	bool Restart = true;
	while (Restart)
	{
		// Выбор ф-ции
		cout << "выберите функ-цию: \n";

		cout << "1.Полином стемени N\n2.Степенная\n3.Показательная\n4.Логарифмическая\n5.Синусоида\n6.Косинусоида\n0.Закрыть программу\n";
		cin >> NumberFunc;

		while (NumberFunc != "1" && NumberFunc != "2" && NumberFunc != "3" && NumberFunc != "4" && NumberFunc != "5" && NumberFunc != "6" && NumberFunc != "0")
		{
			cout << "Некоректный выбор\n";
			cout << "1.Полином стемени N\n2.Степенная\n3.Показательная\n4.Логарифмическая\n5.Синусоида\n6.Косинусоида\n0.Закрыть программу\n";
			cin >> NumberFunc;

		}
		int Vibor = stoi(NumberFunc);
		switch (Vibor)
		{
		case 1:case 2:case 3:case 4:case 5:case 6: ViborOperacii(Vibor); break;

			break;
		}
		if (Vibor == 0)break;

	}

}


void ViborOperacii(int a)
{
	cout << "выберите что хотите сделать\n";
	string Deistvie;
	cout << "1.Вычислить определенный интегралл\n2.Построить график функции\n3.Найти корень на отрезке\n4.Найти экстремумы\n0.Главное меню\n";
	cin >> Deistvie;
	while (Deistvie != "1" && Deistvie != "2" && Deistvie != "3" && Deistvie != "4" && Deistvie != "0")
	{
		cout << "Некоректный выбор\n";
		cout << "1.Вычислить определенный интегралл\n2.Построить график функции\n3.Найти корень на отрезке\n4.Найти экстремумы\n0.Главное меню\n";
		cin >> Deistvie;
	}
	int ViborDeistvie = stoi(Deistvie);

	switch (ViborDeistvie)
	{

	case 1:
		if (a == 1) { IntegralPolinoma(); }
		else if (a == 2) { IntegralStepennaya(); }
		else if (a == 3) { IntegralPokazatelnaya(); }
		else if (a == 4) { IntegralLogarifmicheskaya(); }
		else if (a == 5) { IntegralSinusoida(); }
		else if (a == 6) { IntegralKosinusoida(); }
		break;

	case 2:
		if (a == 1) { GrafPolinom(); }
		else if (a == 2) { GrafStepennoi(); }
		else if (a == 3) { GrafPokazatelnaya(); }
		else if (a == 4) { GrafLogarifmicheskoi(); }
		else if (a == 5) { GrafSinusoida(); }
		else if (a == 6) { GrafKosinusoida(); }
		break;

	case 3: if (a == 1) { PoiskKornyaPolindroma(); }
		  else if (a == 2) { PoiskKornyaStepennoi(); }
		  else if (a == 3) { PoiskKornyaPokazatelnoi(); }
		  else if (a == 4) { PoiskKornyaLogarifmicheskoi(); }
		  else if (a == 5) { PoiskKornyaSinusoida(); }
		  else if (a == 6) { PoiskKornyaKosinusoida(); }
		  break;

	case 4: if (a == 1) { ExtremumPolinom(); }
		  else if (a == 2) { ExtremumStepenoi(); }
		  else if (a == 3) { ExtremumPokazatelnoi(); }
		  else if (a == 4) { ExtremumLogarifmicheskoi(); }
		  else if (a == 5) { ExtermumSinusoida(); }
		  else if (a == 6) { ExtremumKosinusoida(); }
		  break;

	}

}
//
void IntegralPolinoma()
{
	int StepenPolinoma;
	double FirstPredel, SecondPredel, Summ1 = 0, Summ2 = 0;
	cout << "Введите пределы интегрирования\n";
	cin >> FirstPredel >> SecondPredel;

	cout << "Введите степень полинома\n";
	cin >> StepenPolinoma;
	double proizvedenie, zahvatproizved, koef;

	for (double N = 0; N <= StepenPolinoma; N++) {
		cout << "Введите коэффициент при x^" << N << endl;
		cin >> koef;

		proizvedenie = FirstPredel;

		zahvatproizved = proizvedenie;

		for (int prohod = 0; prohod < N; prohod++)
			proizvedenie *= zahvatproizved;

		proizvedenie *= koef / (N + 1);
		Summ1 += proizvedenie;

		proizvedenie = SecondPredel;
		zahvatproizved = proizvedenie;

		for (int prohod = 0; prohod < N; prohod++)
			proizvedenie *= zahvatproizved;

		proizvedenie *= koef / (N + 1);
		Summ2 += proizvedenie;
	}
	cout << "Результат: " << Summ2 - Summ1 << endl;
	system("pause");

}
void IntegralStepennaya()
{

	double FirstPredel, SecondPredel, schet1 = 0, schet2 = 0;
	cout << "Введите пределы интегрирования\n";
	cin >> FirstPredel >> SecondPredel;
	double A, B, C;

	cout << "Ax^B+C\n Введите A \n";
	cin >> A;

	cout << "Введите B \n";
	cin >> B;

	cout << "Введите C \n";
	cin >> C;

	if (B == 0)
		cout << "Результат: " << (A + C) * (SecondPredel - FirstPredel) << endl;
	else if (B > 0) {
		schet1 = A * pow(FirstPredel, B + 1) / (B + 1) + C * FirstPredel;
		schet2 = A * pow(SecondPredel, B + 1) / (B + 1) + C * SecondPredel;
		cout << "Результат: " << schet2 - schet1 << endl;
	}
	else if (FirstPredel * SecondPredel <= 0)
		cout << "Рассходящийся интеграл\n";
	else if (B == -1) {
		schet1 = A * log(abs(FirstPredel)) + C * FirstPredel;
		schet2 = A * log(abs(SecondPredel)) + C * SecondPredel;
		cout << "Результат: " << schet2 - schet1 << endl;
	}
	else {
		schet1 = A * pow(FirstPredel, B + 1) / (B + 1) + C * FirstPredel;
		schet2 = A * pow(SecondPredel, B + 1) / (B + 1) + C * SecondPredel;
		cout << "Результат: " << schet2 - schet1 << endl;
	}
	system("pause");

}
void IntegralPokazatelnaya()
{

	double FirstPredel, SecondPredel, schet1 = 0, schet2 = 0;
	cout << "Введите пределы интегрирования\n";
	cin >> FirstPredel >> SecondPredel;
	double A, B, C, D;
	cout << "A*B^(C*x)+D\nВведите А \n";
	cin >> A;

	do {
		cout << "Введите B \n";
		cin >> B;
		if (B < 0) {
			system("cls");
			cout << "B не может быть меньше 0\n";
		}
	} while (B < 0);
	cout << "Bведите C \n";
	cin >> C;
	cout << "Bведите D\n ";
	cin >> D;
	if (C == 0) {
		schet1 = A * FirstPredel + D * FirstPredel;
		schet2 = A * SecondPredel + D * SecondPredel;
		cout << "Результат:  " << schet2 - schet1 << endl;
	}
	else if (B == 0) {
		if ((FirstPredel < 0 || SecondPredel < 0) && (C > 0))
			cout << "x не может быть меньше 0 при B = 0 и C > 0\n";
		else if ((FirstPredel > 0 || SecondPredel > 0) && (C < 0))
			cout << "x не может быть больше 0 при B = 0 и C < 0\n";
		else {
			if (FirstPredel == 0) schet1 = A + D * FirstPredel;
			else schet1 = D * FirstPredel;
			if (SecondPredel == 0) schet2 = A + D * SecondPredel;
			else schet2 = D * SecondPredel;
			cout << "Результат: " << schet2 - schet1 << endl;
		}
	}
	else if (B == 1) {
		if (A + D == 0)
			cout << "Для всех значений x на данном отрезке функция = 0\n";
		else
			cout << "Корней нет\n";
	}
	else {
		schet1 = A * pow(B, C * FirstPredel) / (C * log(B)) + D * FirstPredel;
		schet2 = A * pow(B, C * SecondPredel) / (C * log(B)) + D * SecondPredel;
		cout << "Результат: " << schet2 - schet1 << endl;
	}
	system("pause");
}
void IntegralLogarifmicheskaya()
{

	double FirstPredel, SecondPredel, schet1 = 0, schet2 = 0;
	cout << "Введите пределы интегрирования\n";
	cin >> FirstPredel >> SecondPredel;

	double A, B, C;
	cout << "A*ln(B*x)+C\nВведите А \n";
	cin >> A;
	do {
		cout << "Введите B \n";
		cin >> B;
		if (B == 0) {
			system("cls");
			cout << "B не может быть равен 0\n";
		}
	} while (B == 0);
	cout << "Введите С " << endl;
	cin >> C;
	if (B * FirstPredel <= 0 || B * SecondPredel <= 0)
		cout << "B*x должно быть больше 0\n";
	else {
		schet1 = A * FirstPredel * (log(B * FirstPredel) - 1) + C * FirstPredel;
		schet2 = A * SecondPredel * (log(B * SecondPredel) - 1) + C * SecondPredel;
		cout << "Результат: " << schet2 - schet1 << endl;
	}
	system("pause");


}
void IntegralSinusoida()
{

	double FirstPredel, SecondPredel, schet1 = 0, schet2 = 0;
	cout << "Введите пределы интегрирования\n";
	cin >> FirstPredel >> SecondPredel;

	double A, B, C, D;
	cout << "a*sin(b*x+c)+d\nВведите А \n";
	cin >> A;

	cout << "Введите B\n ";
	cin >> B;

	cout << "Введите C\n ";
	cin >> C;

	cout << "Введите D\n ";
	cin >> D;

	if (B == 0) {
		cout << "Результат: " << (A * sin(C) + D) * (SecondPredel - FirstPredel) << endl;
	}
	else {
		schet1 = -A * cos(B * FirstPredel + C) / B + D * FirstPredel;
		schet2 = -A * cos(B * SecondPredel + C) / B + D * SecondPredel;
		cout << "Результат: " << schet2 - schet1 << endl;
	}
	system("pause");

}
void IntegralKosinusoida()
{

	double FirstPredel, SecondPredel, schet1 = 0, schet2 = 0;
	cout << "Введите пределы интегрирования\n";
	cin >> FirstPredel >> SecondPredel;
	double A, B, C, D;

	cout << "a*cos(b*x+c)+d\nВведите А \n";
	cin >> A;

	cout << "Введите B\n ";
	cin >> B;

	cout << "Введите C\n ";
	cin >> C;

	cout << "Введите D\n ";
	cin >> D;


	if (B == 0) {
		cout << "Результат: " << (A * cos(C) + D) * (SecondPredel - FirstPredel) << endl;
	}
	else {
		schet1 = A * sin(B * FirstPredel + C) / B + D * FirstPredel;
		schet2 = A * sin(B * SecondPredel + C) / B + D * SecondPredel;
		cout << "Результат: " << schet2 - schet1 << endl;
	}
	system("pause");

}


//Графики функций
void GrafPolinom()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		printf(" SDL_Error: %s\n", SDL_GetError());
	else
	{
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"Построение графиков",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
			printf(" Ошибка %s\n", SDL_GetError());
		else
		{
			struct point {
				double x = SCREEN_WIDTH / 2;
				double y = SCREEN_HEIGHT / 2;
			}O;


			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawLine(renderer, (int)O.x, 0, (int)O.x, SCREEN_HEIGHT);
			SDL_RenderDrawLine(renderer, 0, (int)O.y, SCREEN_WIDTH, (int)O.y);
			SDL_RenderPresent(renderer);

			int N;
			const int nMax = 100;
			double kof[nMax];
			double x1, x2, y1, y2;
			do {
				cout << "Введите степень полинома" << endl;
				cin >> N;
				if (N > nMax - 1) {
					system("cls");
					cout << "Степень полинома должна быть меньше 100" << endl;
				}
				else if (N < 1) {
					system("cls");
					cout << "Степень полинома должна быть больше 0" << endl;
				}
			} while (N > nMax - 1 || N < 1);

			cout << "Введите коэффициенты" << endl;
			for (int k = 0; k <= N; k++) {
				cout << "Введите коэффициент при x^" << k << endl;
				cin >> kof[k];
			}
			cout << "Введите концы отрезка построения графика" << endl;
			cin >> x1 >> x2;
			if (x1 > x2) {
				double x3 = x1;
				x1 = x2;
				x2 = x1;
				cout << "Внимание, введён отрезок [" << x1 << ";" << x2 << "]" << endl;
			}
			y1 = 0;
			for (int k = 0; k <= N; k++)
				y1 += kof[k] * pow(x1, k);
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
			double size;
			cout << "Введите во сколько раз увеличить масштаб ( например в 20 )" << endl;
			cin >> size;
			for (double l = x1 + 1; l < x2; l += 0.1) {
				y2 = 0;
				for (int k = 0; k <= N; k++)
					y2 += kof[k] * pow(l, k);
				SDL_RenderDrawLine(renderer, O.x + x1 * size, O.y - y1 * size, O.x + l * size, O.y - y2 * size);
				SDL_RenderPresent(renderer);
				x1 = l;
				y1 = y2;
			}
			cout << "Внимание, задержка показа графика 5 секунд" << endl;
			SDL_Delay(delay);

			SDL_DestroyRenderer(renderer);

			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	system("pause");
};
void GrafStepennoi()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		printf(" SDL_Error: %s\n", SDL_GetError());
	else
	{
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"Построение графиков",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
			printf(" Ошибка %s\n", SDL_GetError());
		else
		{
			struct point {
				double x = SCREEN_WIDTH / 2;
				double y = SCREEN_HEIGHT / 2;
			}O;


			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawLine(renderer, (int)O.x, 0, (int)O.x, SCREEN_HEIGHT);
			SDL_RenderDrawLine(renderer, 0, (int)O.y, SCREEN_WIDTH, (int)O.y);
			SDL_RenderPresent(renderer);
			double x1, x2, y1, y2;
			double A, B, C;
			cout << "ax^b+c" << endl;
			cout << "введите a " << endl;
			cin >> A;
			cout << "введите b " << endl;
			cin >> B;
			cout << "введите c " << endl;
			cin >> C;
			cout << "Введите x1 и x2" << endl;
			cin >> x1 >> x2;
			if (x1 > x2) {
				double x3 = x1;
				x1 = x2;
				x2 = x1;
				cout << "Внимание, введён отрезок [" << x1 << ";" << x2 << "]" << endl;
			}
			y1 = A * pow(x1, B) + C;
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
			double size;
			cout << "Введите во сколько раз увеличить масштаб ( например в 20 )" << endl;
			cin >> size;
			for (double l = x1 + 1; l < x2; l += 0.1) {
				y2 = A * pow(l, B) + C;
				if (!(B < 0 && ((l > -0.2 && l < 0.2) || (x1 > -0.2 && x1 < 0.2)))) {
					SDL_RenderDrawLine(renderer, O.x + x1 * size, O.y - y1 * size, O.x + l * size, O.y - y2 * size);
					SDL_RenderPresent(renderer);
				}
				x1 = l;
				y1 = y2;
			}
			cout << "Внимание, задержка показа графика 5 секунд" << endl;
			SDL_Delay(delay);
			system("pause");

			SDL_DestroyRenderer(renderer);

			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	system("pause");

};
void GrafPokazatelnaya()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		printf(" SDL_Error: %s\n", SDL_GetError());
	else
	{
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"Построение графиков",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
			printf(" Ошибка %s\n", SDL_GetError());
		else
		{
			struct point {
				double x = SCREEN_WIDTH / 2;
				double y = SCREEN_HEIGHT / 2;
			}O;


			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawLine(renderer, (int)O.x, 0, (int)O.x, SCREEN_HEIGHT);
			SDL_RenderDrawLine(renderer, 0, (int)O.y, SCREEN_WIDTH, (int)O.y);
			SDL_RenderPresent(renderer);
			double x1, x2, y1, y2;
			double A, B, C, D;
			cout << "a*b^(c*x)+d" << endl;
			cout << "введите a " << endl;
			cin >> A;
			do {
				cout << "введите b " << endl;
				cin >> B;
				if (B < 0) {
					system("cls");
					cout << "b не может быть меньше 0" << endl;
				}
			} while (B < 0);
			cout << "введите c " << endl;
			cin >> C;
			cout << "введите d " << endl;
			cin >> D;
			cout << "Введите x1 и x2" << endl;
			cin >> x1 >> x2;
			if (x1 > x2) {
				double x3 = x1;
				x1 = x2;
				x2 = x1;
				cout << "Внимание, введён отрезок [" << x1 << ";" << x2 << "]" << endl;
			}
			y1 = A * pow(B, C * x1) + D;
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
			double size;
			cout << "Введите во сколько раз увеличить масштаб ( например в 20 )" << endl;
			cin >> size;
			for (double l = x1 + 1; l < x2; l += 0.1) {
				y2 = A * pow(B, C * l) + D;
				if (B == 0 && C > 0 && (l < 0 || x1 < 0)) {}
				else if (B == 0 && C < 0 && (l > 0 || x1 > 0)) {}
				else if (B == 0 && ((l > -0.2 && l < 0.2) || (x1 > -0.2 && x1 < 0.2))) {}
				else {
					SDL_RenderDrawLine(renderer, O.x + x1 * size, O.y - y1 * size, O.x + l * size, O.y - y2 * size);
					SDL_RenderPresent(renderer);
				}
				x1 = l;
				y1 = y2;
			}
			cout << "Внимание, задержка показа графика 5 секунд" << endl;
			SDL_Delay(delay);
			system("pause");
			system("pause");

			SDL_DestroyRenderer(renderer);

			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	system("pause");

};
void GrafLogarifmicheskoi()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		printf(" SDL_Error: %s\n", SDL_GetError());
	else
	{
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"Построение графиков",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
			printf(" Ошибка %s\n", SDL_GetError());
		else
		{
			struct point {
				double x = SCREEN_WIDTH / 2;
				double y = SCREEN_HEIGHT / 2;
			}O;


			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawLine(renderer, (int)O.x, 0, (int)O.x, SCREEN_HEIGHT);
			SDL_RenderDrawLine(renderer, 0, (int)O.y, SCREEN_WIDTH, (int)O.y);
			SDL_RenderPresent(renderer);
			double x1, x2, y1, y2;
			double A, B, C;
			cout << "a*ln(b*x)+c" << endl;
			cout << "введите a " << endl;
			cin >> A;
			do {
				cout << "введите b " << endl;
				cin >> B;
				if (B == 0) {
					system("cls");
					cout << "b не может быть равен 0" << endl;
				}
			} while (B == 0);
			cout << "введите c " << endl;
			cin >> C;
			cout << "Введите x1 и x2" << endl;
			cin >> x1 >> x2;
			if (x1 > x2) {
				double x3 = x1;
				x1 = x2;
				x2 = x1;
				cout << "Внимание, введён отрезок [" << x1 << ";" << x2 << "]" << endl;
			}
			if (B > 0 && x1 <= 0) x1 = 0.1;
			else if (B < 0 && x2 > 0) x2 = -0.1;
			y1 = A * log(B * x1) + C;
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
			double size;
			cout << "Введите во сколько раз увеличить масштаб ( например в 20 )" << endl;
			cin >> size;
			for (double l = x1 + 1; l < x2; l += 0.1) {
				y2 = A * log(B * x1) + C;
				SDL_RenderDrawLine(renderer, O.x + x1 * size, O.y - y1 * size, O.x + l * size, O.y - y2 * size);
				SDL_RenderPresent(renderer);
				x1 = l;
				y1 = y2;
			}
			cout << "Внимание, задержка показа графика 5 секунд" << endl;
			SDL_Delay(delay);
			system("pause");
			SDL_Delay(delay);
			system("pause");


			SDL_DestroyRenderer(renderer);

			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	system("pause");
};
void GrafSinusoida()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		printf(" SDL_Error: %s\n", SDL_GetError());
	else
	{
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"Построение графиков",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
			printf(" Ошибка %s\n", SDL_GetError());
		else
		{
			struct point {
				double x = SCREEN_WIDTH / 2;
				double y = SCREEN_HEIGHT / 2;
			}O;


			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawLine(renderer, (int)O.x, 0, (int)O.x, SCREEN_HEIGHT);
			SDL_RenderDrawLine(renderer, 0, (int)O.y, SCREEN_WIDTH, (int)O.y);
			SDL_RenderPresent(renderer);
			double x1, x2, y1, y2;
			double A, B, C, D;
			cout << "a*sin(b*x+c)+d" << endl;
			cout << "введите a " << endl;
			cin >> A;
			cout << "введите b " << endl;
			cin >> B;
			cout << "введите c " << endl;
			cin >> C;
			cout << "введите d " << endl;
			cin >> D;
			cout << "Введите x1 и x2" << endl;
			cin >> x1 >> x2;
			if (x1 > x2) {
				double x3 = x1;
				x1 = x2;
				x2 = x1;
				cout << "Внимание, введён отрезок [" << x1 << ";" << x2 << "]" << endl;
			}
			y1 = A * sin(B * x1 + C) + D;
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
			double size;
			cout << "Введите во сколько раз увеличить масштаб ( например в 20 )" << endl;
			cin >> size;
			for (double l = x1 + 1; l < x2; l += 0.1) {
				y2 = A * sin(B * x1 + C) + D;
				SDL_RenderDrawLine(renderer, O.x + x1 * size, O.y - y1 * size, O.x + l * size, O.y - y2 * size);
				SDL_RenderPresent(renderer);
				x1 = l;
				y1 = y2;
			}
			cout << "Внимание, задержка показа графика 5 секунд" << endl;
			SDL_Delay(delay);
			system("pause");


			SDL_DestroyRenderer(renderer);

			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	system("pause");

};
void GrafKosinusoida()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		printf(" SDL_Error: %s\n", SDL_GetError());
	else
	{
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"Построение графиков",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
			printf(" Ошибка %s\n", SDL_GetError());
		else
		{
			struct point {
				double x = SCREEN_WIDTH / 2;
				double y = SCREEN_HEIGHT / 2;
			}O;


			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawLine(renderer, (int)O.x, 0, (int)O.x, SCREEN_HEIGHT);
			SDL_RenderDrawLine(renderer, 0, (int)O.y, SCREEN_WIDTH, (int)O.y);
			SDL_RenderPresent(renderer);
			double x1, x2, y1, y2;
			double A, B, C, D;
			cout << "a*cos(b*x+c)+d" << endl;
			cout << "введите a " << endl;
			cin >> A;
			cout << "введите b " << endl;
			cin >> B;
			cout << "введите c " << endl;
			cin >> C;
			cout << "введите d " << endl;
			cin >> D;
			cout << "Введите x1 и x2" << endl;
			cin >> x1 >> x2;
			if (x1 > x2) {
				double x3 = x1;
				x1 = x2;
				x2 = x1;
				cout << "Внимание, введён отрезок [" << x1 << ";" << x2 << "]" << endl;
			}
			y1 = A * cos(B * x1 + C) + D;
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
			double size;
			cout << "Введите во сколько раз увеличить масштаб ( например в 20 )" << endl;
			cin >> size;
			for (double l = x1 + 1; l < x2; l += 0.1) {
				y2 = A * cos(B * x1 + C) + D;
				SDL_RenderDrawLine(renderer, O.x + x1 * size, O.y - y1 * size, O.x + l * size, O.y - y2 * size);
				SDL_RenderPresent(renderer);
				x1 = l;
				y1 = y2;
			}
			cout << "Внимание, задержка показа графика 5 секунд" << endl;
			SDL_Delay(delay);
			system("pause");


			SDL_DestroyRenderer(renderer);

			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	system("pause");
};

//поиск корня Y=0

double Znachenie(int n, double mass[], double x) {
	double Summ = mass[0];
	for (int i = 1; i <= n; i++)
		Summ += mass[i] * pow(x, i);
	return Summ;
}

complex<double> Kompleks(int n, double mass[], complex<double> x)
{
	complex<double> SummKomplex = pow(x, n);
	for (int i = 0; i < n; i++)
		SummKomplex += mass[i] * pow(x, i);
	return SummKomplex;
}

complex<double>* KompleksKoren(double mass[], int n)
{
	int Povtorenie = 675;
	complex<double> z = complex<double>(0.4, 0.9);

	int size = sizeof(z);
	complex<double>* Vernut = new complex<double>[n];

	for (int i = 0; i < n; i++)
		Vernut[i] = pow(z, i);

	for (int Prohod = 0; Prohod < Povtorenie; Prohod++)
	{
		for (int i = 0; i < n; i++)
		{
			complex<double> B = Kompleks(n, mass, Vernut[i]);

			for (int l = 0; l < n; l++)		if (l != i)		B /= Vernut[i] - Vernut[l];

			Vernut[i] -= B;
		}
	}

	return Vernut;
}


void PoiskKornyaPolindroma()
{
	double NachaloOtrezka, KonecOtrezka;
	double DeistvitelnayaChast = 0;

	int StepenPolinoma;
	bool check = false, Proverka = false;;

	do {

		cout << "Введите степень полинома\n";
		cin >> StepenPolinoma;

		if (StepenPolinoma < 1) {
			cout << "Степень не может быть меньше 1\n";
		}
		else if (StepenPolinoma > 100) {
			cout << "Степень не может быть больше 100\n";
		}
	} while (StepenPolinoma < 1 || StepenPolinoma>100);
	double* MassKoef = new double[StepenPolinoma + 1];
	for (int Koef = 0; Koef <= StepenPolinoma; Koef++) {
		if (Koef == StepenPolinoma) {
			do {
				cout << "Введите коэффициент при x^" << Koef << endl;
				cin >> MassKoef[Koef];
				if (MassKoef[Koef] == 0) 	cout << "Коэффициент наибольшей степенидолжен не равняться 0 0\n";

			} while (MassKoef[Koef] == 0);
		}
		else {
			cout << "Коэффициент  x^=" << Koef << endl;
			cin >> MassKoef[Koef];
			if (MassKoef[Koef] != 0) check = true;
		}
	}
	if (check == true) {
		for (int i = 0; i <= StepenPolinoma; i++) {
			MassKoef[i] = MassKoef[i] / MassKoef[StepenPolinoma];
		}
		cout << "Введите границы отрезка\n";
		double Swapper;
		cin >> NachaloOtrezka >> KonecOtrezka;

		if (NachaloOtrezka > KonecOtrezka) {
			Swapper = NachaloOtrezka;
			NachaloOtrezka = KonecOtrezka;
			KonecOtrezka = Swapper;
		}
		complex<double>* KompleksniiSchet = KompleksKoren(MassKoef, StepenPolinoma);
		cout << "Корни: ";

		for (int i = 0; i < StepenPolinoma; i++) {
			if (KompleksniiSchet[i].imag() > -0.1 && KompleksniiSchet[i].imag() < 0.1 && KompleksniiSchet[i].real() >= NachaloOtrezka && KompleksniiSchet[i].real() <= KonecOtrezka) {
				if (KompleksniiSchet[i].imag() > -0.1 && KompleksniiSchet[i].imag() < 0.1) {
					if (i != 0) {
						if (abs(KompleksniiSchet[i].real() - DeistvitelnayaChast) > 0.0001) {
							cout << KompleksniiSchet[i].real() << " ";
							DeistvitelnayaChast = KompleksniiSchet[i].real();
							Proverka = true;
						}
					}
					else {
						cout << KompleksniiSchet[i].real() << " ";
						DeistvitelnayaChast = KompleksniiSchet[i].real();
						Proverka = true;
					}

				}
			}
		}
		if (Proverka == false)cout << "Корней на отрезке нет\n";

	}
	else	cout << "Корень 0\n";

	system("pause");

};
void PoiskKornyaStepennoi()
{
	double NachaloOtrezka, KonecOtrezka, A, C;

	int B;
	bool Proverka = false;

	cout << "Ax^B+C\n";

	cout << "введите a \n";	cin >> A;

	cout << "введите B-целочисленное \n";	cin >> B;

	cout << "введите C \n";	cin >> C;

	cout << "Введите границы отрезка\n";
	cin >> NachaloOtrezka >> KonecOtrezka;

	if (NachaloOtrezka > KonecOtrezka) {
		double Swapper = NachaloOtrezka;
		NachaloOtrezka = KonecOtrezka;
		KonecOtrezka = Swapper;

	}
	double x;

	if (A == 0 && C == 0)		cout << "Для любого значения x из данного отрезка функция равна 0\n";

	else if (A == 0)	cout << "Корней нет\n";

	else if (C == 0 && B > 0)	cout << "Корень= 0\n";

	else if (B % 2 == 0) {
		cout << "Корень: ";
		if (A * C < 0) {
			x = pow(-C / A, 1 / (double)B);
			if (x >= NachaloOtrezka && x <= KonecOtrezka) {
				Proverka = true;
				cout << x << " ";
			}
			if (-x >= NachaloOtrezka && -x <= KonecOtrezka) {
				Proverka = true;
				cout << -x << " ";
			}
			if (Proverka == false)
				cout << "корней на отрезке нет\n";

		}
		else cout << "корней на отрезке нет\n";
	}
	else {
		cout << "Корень: \n";
		if (C / A > 0) {
			x = pow(C / A, 1 / (double)B);
			x = -1 * x;
		}
		else		x = pow(-C / A, 1 / (double)B);

		if (x >= NachaloOtrezka && x <= KonecOtrezka)	cout << x << " " << endl;
		else	cout << "корней на данном отрезке нет\n";

	}
};
void PoiskKornyaPokazatelnoi()
{

	double NachaloOtrezka, KonecOtrezka, Swapper;
	double A, B, C, D, X;
	cout << "a*b^(c*x)+d" << endl;
	cout << "введите A " << endl;
	cin >> A;
	do {
		cout << "введите B " << endl;
		cin >> B;
		if (B < 0) {
			system("cls");
			cout << "B не может быть меньше 0" << endl;
		}
	} while (B < 0);
	cout << "введите C " << endl;
	cin >> C;
	cout << "введите D " << endl;
	cin >> D;
	cout << "Введите границы отрезка\n";
	cin >> NachaloOtrezka >> KonecOtrezka;

	if (NachaloOtrezka > KonecOtrezka) {
		Swapper = NachaloOtrezka;
		NachaloOtrezka = KonecOtrezka;
		KonecOtrezka = Swapper;

	}
	if (C == 0)
	{
		if (A + D == 0) cout << "Для любого значения  функция равна 0\n";
		else cout << "Корней нет\n";
	}
	else if (B == 0) {
		if (D == 0) {
			if (C > 0) {
				if (KonecOtrezka < 0) cout << "Корней нет\n";
				else if (NachaloOtrezka < 0) cout << "Корни ( 0 , " << KonecOtrezka << ")\n";
				else cout << "Корни ( " << NachaloOtrezka << " , " << KonecOtrezka << " )\n";
			}
			else {
				if (NachaloOtrezka > 0) cout << "Корней нет\n";
				else if (KonecOtrezka > 0) cout << "Корни ( " << NachaloOtrezka << " , " << KonecOtrezka << " )\n";
				else cout << "Корни ( " << KonecOtrezka << " , " << NachaloOtrezka << " )\n";
			}
		}
		else {
			cout << "Корней нет\n";
		}
	}
	else if (D * A > 0) cout << "Корней нет\n";

	else if (D * A == 0)
	{
		if (D != 0 || A != 0) cout << "Корней нет\n";
		else cout << "Для любого значения функция равна 0\n";
	}
	else {
		X = log(-D / A) / (log(B) * C);

		if (X >= NachaloOtrezka && X <= KonecOtrezka)		cout << "Корень= " << X << endl;

		else			cout << "Корней на отрезке нет\n";
	}
	system("pause");
};
void PoiskKornyaLogarifmicheskoi()
{

	double NachaloOtrezka, KonecOtrezka;
	double A, B, C;
	cout << "А*ln(В*x)+С\n";
	cout << "введите А \n";
	cin >> A;
	do {
		cout << "введите В \n";
		cin >> B;
		if (B == 0) {

			cout << "B не может быть равен 0\n";
		}
	} while (B == 0);
	cout << "Введите C \n";
	cin >> C;
	cout << "Введите границы отрезка\n";
	cin >> NachaloOtrezka >> KonecOtrezka;

	if (NachaloOtrezka > KonecOtrezka) {
		double Swapper = NachaloOtrezka;
		NachaloOtrezka = KonecOtrezka;
		KonecOtrezka = Swapper;

	}
	if (A == 0) {
		if (C == 0) {
			if (B > 0) {
				if (KonecOtrezka <= 0) cout << "Корней нет\n";
				else if (NachaloOtrezka <= 0) cout << "Корни= ( 0 ; " << KonecOtrezka << " ]\n";
				else cout << "Корни ( " << NachaloOtrezka << " , " << KonecOtrezka << ")\n";
			}
			else {
				if (NachaloOtrezka >= 0) cout << "Корней нет\n";
				else if (KonecOtrezka >= 0) cout << "[ " << NachaloOtrezka << " ; " << KonecOtrezka << ")\n";
				else cout << "Корни ( " << KonecOtrezka << " , " << NachaloOtrezka << " )\n";
			}
		}
		else
			cout << "Корней нет\n";
	}
	else {
		double x = exp(-C / A) / B;
		if (x >= NachaloOtrezka && x <= KonecOtrezka)
			cout << "Корень= " << x << endl;
		else
			cout << "Kорней на данном отрезке нет\n";
	}
	system("pause");
};
void PoiskKornyaSinusoida()
{

	double NachaloOtrezka, KonecOtrezka, Swapper;
	double A, B, C, D;
	bool Proverka = false;
	cout << "A*sin(B*x+C)+D\n";

	cout << "введите A \n";	cin >> A;

	cout << "введите B \n";	cin >> B;

	cout << "введите C \n";	cin >> C;

	cout << "введите D\n ";	cin >> D;

	cout << "Введите границы отрезка\n";
	cin >> NachaloOtrezka >> KonecOtrezka;

	if (NachaloOtrezka > KonecOtrezka) {
		Swapper = NachaloOtrezka;
		NachaloOtrezka = KonecOtrezka;
		KonecOtrezka = Swapper;
	}

	if (A == 0) {
		if (D == 0) cout << "Для любого значения функция равна 0\n";
		else cout << "Корней нет\n";
	}
	else if (B == 0) {
		if (A * sin(C) + D == 0) cout << "Для любого значения x из данного отрезка функция равна 0\n";
		else cout << "Корней нет\n";
	}
	else {

		double x = (asin(-D / A) - C) / B;
		cout << "Корень = ";
		for (double j = x; j >= NachaloOtrezka; j -= 2 * M_PI / abs(B)) {
			if (j >= NachaloOtrezka && j <= KonecOtrezka) {
				cout << j << " ";
				Proverka = true;
			}
		}
		for (double j = x + 2 * M_PI / abs(B); j <= KonecOtrezka; j += 2 * M_PI / abs(B)) {
			if (j >= NachaloOtrezka && j <= KonecOtrezka) {
				cout << j << " ";
				Proverka = true;
			}
		}
		x = (M_PI - asin(-D / A) - C) / B;
		for (double j = x; j >= NachaloOtrezka; j -= 2 * M_PI / abs(B)) {
			if (j >= NachaloOtrezka && j <= KonecOtrezka) {
				cout << j << " ";
				Proverka = true;
			}
		}
		for (double j = x + 2 * M_PI / abs(B); j <= KonecOtrezka; j += 2 * M_PI / abs(B)) {
			if (j >= NachaloOtrezka && j <= KonecOtrezka) {
				cout << j << " ";
				Proverka = true;
			}
		}
		if (Proverka = false)
			cout << "корней на отрезке нет\n";
		else
			cout << endl;
	}
	system("pause");
};
void PoiskKornyaKosinusoida()
{

	double  NachaloOtrezka, KonecOtrezka, Swapper;
	double A, B, C, D;
	bool Proverka = false;

	cout << "A*cos(B*x+C)+D" << endl;

	cout << "введите A \n";	cin >> A;

	cout << "введите B \n";	cin >> B;

	cout << "введите C \n";	cin >> C;

	cout << "введите D\n ";	cin >> D;

	cout << "Введите границы отрезка\n";
	cin >> NachaloOtrezka >> KonecOtrezka;

	if (NachaloOtrezka > KonecOtrezka) {
		Swapper = NachaloOtrezka;
		NachaloOtrezka = KonecOtrezka;
		KonecOtrezka = Swapper;
	}

	if (A == 0) {
		if (D == 0) cout << "Для любого значения функция равна 0\n";
		else cout << "Корней нет\n";
	}
	else if (B == 0) {
		if (A * cos(C) + D == 0) cout << "Для любого значения x из данного отрезка функция равна 0\n";
		else cout << "Корней нет\n";
	}
	else {

		double x = (acos(-D / A) - C) / B;
		cout << "Корень = ";
		for (double j = x; j >= NachaloOtrezka; j -= 2 * M_PI / abs(B)) {
			if (j >= NachaloOtrezka && j <= KonecOtrezka) {
				cout << j << " ";
				Proverka = true;
			}
		}
		for (double j = x + 2 * M_PI / abs(B); j <= KonecOtrezka; j += 2 * M_PI / abs(B)) {
			if (j >= NachaloOtrezka && j <= KonecOtrezka) {
				cout << j << " ";
				Proverka = true;
			}
		}
		x = (-acos(-D / A) - C) / B;
		for (double j = x; j >= NachaloOtrezka; j -= 2 * M_PI / abs(B)) {
			if (j >= NachaloOtrezka && j <= KonecOtrezka) {
				cout << j << " ";
				Proverka = true;
			}
		}
		for (double j = x + 2 * M_PI / abs(B); j <= KonecOtrezka; j += 2 * M_PI / abs(B)) {
			if (j >= NachaloOtrezka && j <= KonecOtrezka) {
				cout << j << " ";
				Proverka = true;
			}
		}
		if (Proverka == false)
			cout << "корней на отрезке нет\n";
		else
			cout << endl;
	}
	system("pause");
};


//поиск  экстремумов
void ExtremumPolinom()
{
	double NachaloOtrezka, KonecOtrezka, Swapper;
	int StepenPolindroma;
	bool Proverka = false;
	cout << "Введите степень\n";
	cin >> StepenPolindroma;
	double* mass = new double[StepenPolindroma + 1];
	for (int Koef = 0; Koef <= StepenPolindroma; Koef++) {
		if (Koef == StepenPolindroma) {
			do {
				cout << "Введите коэффициент при x^" << Koef << endl;
				cin >> mass[Koef];
				if (mass[Koef] == 0) {
					system("cls");
					cout << "Коэффициент наибольшей степени не должен быть равен 0\n";
				}
			} while (mass[Koef] == 0);
		}
		else {
			cout << "Введите коэффициент при x^" << Koef << endl;
			cin >> mass[Koef];
		}
	}
	cout << "массив:\n";
	for (int j = 0; j <= StepenPolindroma; j++) {
		cout << mass[j] << endl;
	}
	for (int j = 1; j <= StepenPolindroma; j++) {
		mass[j - 1] = mass[j] * j;
	}
	cout << "массив:\n";
	for (int j = 0; j <= StepenPolindroma - 1; j++) {
		cout << mass[j] << endl;
	}
	for (int j = 0; j <= StepenPolindroma - 1; j++) {
		mass[j] = mass[j] / mass[StepenPolindroma - 1];
	}
	cout << "массив:\n";
	for (int j = 0; j <= StepenPolindroma - 1; j++) {
		cout << mass[j] << endl;
	}

	cout << "Введите границы отрезка\n";
	cin >> NachaloOtrezka >> KonecOtrezka;

	if (NachaloOtrezka > KonecOtrezka) {
		Swapper = NachaloOtrezka;
		NachaloOtrezka = KonecOtrezka;
		KonecOtrezka = Swapper;
	}

	complex<double>* KomplexniiSchet = KompleksKoren(mass, StepenPolindroma - 1);
	cout << "Точки экстремумов: ";

	for (int i = 0; i < StepenPolindroma - 1; i++) {
		if (KomplexniiSchet[i].imag() > -0.1 && KomplexniiSchet[i].imag() < 0.1 && KomplexniiSchet[i].real() >= NachaloOtrezka && KomplexniiSchet[i].real() <= KonecOtrezka) {
			if (KomplexniiSchet[i].real() > -0.1 && KomplexniiSchet[i].real() < 0.1) KomplexniiSchet[i] = 0;
			double y1 = Znachenie(StepenPolindroma - 1, mass, KomplexniiSchet[i].real() - 0.001),
				y2 = Znachenie(StepenPolindroma - 1, mass, KomplexniiSchet[i].real() + 0.001);
			if (y1 * y2 < 0) {
				cout << KomplexniiSchet[i].real() << " ";
				Proverka = true;
			}
		}
	}
	if (Proverka == false)
		cout << "Точек экстремумов на отрезке нет\n";
	cout << endl;
	system("pause");
};
void ExtremumStepenoi()
{
	double a, b, c, x, y, min, max;
	int n, m;
	printf("Введите a,b и с:\ny(x)=ax^b+c\n");
	cout << "a=\n";
	cin >> a;
	cout << "b=\n";
	cin >> b;
	cout << "c=\n";
	cin >> c;
	cout << "Начало отрезка=\n";
	cin >> n;
	do
	{
		cout << "Конец отрезка=\n";
		cin >> m;
	} while (m <= n);

	if (b <= 0)
		printf("Глобальных экстремумов нет\n");
	else
	{
		if (b - 1 == 0)
		{
			printf("Производная y=%1.2lf\n", a);
			printf("Глобальных экстремумов нет\n");
			printf("Локальный экстремумы на заданном интервале:\n");
			x = a * n + c;
			y = a * m + c;
			if (x > y)
			{
				min = y;
				max = x;
			}
			if (x < y)
			{
				min = x;
				max = y;
			}
			if (x == y)
			{
				min = c;
				max = x;
			}
			printf("Ymin=%1.2lf\n", min);
			printf("Ymax=%1.2lf\n", max);
		}
		else
		{
			printf("Производная y=%1.2lfx^%1.2lf\n", a * b, b - 1);
			printf("%1.2lfx^%1.2lf=0\n", a * b, b - 1);
			printf("x=0\n");
			for (int i = 0; i < b - 1; i++)
			{
				n *= n;
				m *= m;
			}
			x = a * n + c;
			y = a * m + c;
			if (x > y)
			{
				max = x;
				min = y;
				if (c > max)
					max = c;
				if (c < min)
					min = c;
			}
			if (x < y)
			{
				max = y;
				min = x;
				if (c > max)
					max = c;
				if (c < min)
					min = c;
			}
			if (x == y)
			{
				if (c > x)
				{
					max = c;
					min = x;
				}
				else
				{
					min = c;
					max = x;
				}
			}
			printf("Ymin=%1.2lf\n", min);
			printf("Ymax=%1.2lf\n", max);
		}
	}
};
void ExtremumPokazatelnoi()
{
	double A, B, C, D;
	cout << "A*B^(C*x)+D\n";
	cout << "введите a \n";
	cin >> A;
	do {
		cout << "введите B \n";
		cin >> B;
		if (B < 0) {

			cout << "B не может быть меньше 0\n";
		}
	} while (B < 0);
	cout << "введите C \n";
	cin >> C;
	cout << "введите D \n";
	cin >> D;
	cout << "У данной функции нет экстремумов\n";
	system("pause");
};
void ExtremumLogarifmicheskoi()
{
	double a, b, c, d;
	printf("Введите a,b,c и d:\ny(x)=a*b^(c*x)+d\n");
	cout << "a=\n";
	cin >> a;
	cout << "b=\n";
	cin >> b;
	cout << "c=\n";
	cin >> c;
	cout << "d=\n";
	cin >> d;
	if (b == 0)
		printf("Не определён, так как ln(b*x)>0\n");
	else
		printf("Глобальных экстремумов нет\n");
};
void ExtermumSinusoida()
{
	double NachaloOtrezka, KonecOtrezka, Swapper;
	double A, B, C, D;
	bool Proverka = false;
	cout << "a*sin(b*x+c)+d\n";
	cout << "введите a \n";
	cin >> A;
	cout << "введите b \n";
	cin >> B;
	cout << "введите c \n";
	cin >> C;
	cout << "введите d \n";
	cin >> D;
	cout << "Введите границы отрезка\n";
	cin >> NachaloOtrezka >> KonecOtrezka;

	if (NachaloOtrezka > KonecOtrezka) {
		Swapper = NachaloOtrezka;
		NachaloOtrezka = KonecOtrezka;
		KonecOtrezka = Swapper;
	}
	if (B == 0 || A == 0)
		cout << "У функции нет экстремумов\n";
	else {

		cout << "экстремумов = ";
		int k = -2;
		double x = (M_PI - 2 * C) / (2 * B);
		while (x >= NachaloOtrezka) {
			Proverka = true;
			cout << x << " ";
			x = (M_PI - 2 * C + k * M_PI) / (2 * B);
			k -= 2;
		}
		x = (M_PI - 2 * C + 2 * M_PI) / (2 * B);
		k = 4;
		while (x <= KonecOtrezka) {
			Proverka = true;
			cout << x << " ";
			x = (M_PI - 2 * C + k * M_PI) / (2 * B);
			k += 2;
		}
		if (Proverka == false)
			cout << "точек экстремумов нет\n";
		cout << endl;
	}
	system("pause");
};
void ExtremumKosinusoida()
{
	double NachaloOtrezka, KonecOtrezka, Swapper;
	double A, B, C, D;
	bool Proverka = false;
	cout << "a*cos(b*x+c)+d\n";
	cout << "введите a \n";
	cin >> A;
	cout << "введите b \n";
	cin >> B;
	cout << "введите c \n";
	cin >> C;
	cout << "введите d \n";
	cin >> D;

	cout << "Введите границы отрезка\n";
	cin >> NachaloOtrezka >> KonecOtrezka;

	if (NachaloOtrezka > KonecOtrezka) {
		Swapper = NachaloOtrezka;
		NachaloOtrezka = KonecOtrezka;
		KonecOtrezka = Swapper;
	}
	if (B == 0 || A == 0)
		cout << "У функции нет экстремумов\n";
	if (B == 0 || A == 0)
		cout << "У функции нет экстремумов\n";
	else {

		cout << "Точки экстремумов : ";
		int k = -1;
		double x = -C / B;
		while (x >= NachaloOtrezka) {
			Proverka = true;
			cout << x << " ";
			x = (M_PI * k - C) / B;
			k--;
		}
		k = 1;
		x = x = (M_PI * k - C) / B;
		while (x <= KonecOtrezka) {
			Proverka = true;
			cout << x << " ";
			x = x = (M_PI * k - C) / B;
			k++;
		}
		if (Proverka == false)
			cout << "точек экстремумов нет" << endl;
		cout << endl;
	}
	system("pause");
};