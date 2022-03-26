#define _CRT_SECURE_NO_WARNINGS
#include "matstatic_header.h"

void mat() //мат. ожидание
{
	int x;
	double a[100], b[100], c[100], sum1 = 0, sum2 = 0, M = 0, k;
	printf("Введите количество пар чисел: ");
	do
	{
		scanf("%d", &x);
	} while (x <= 0);

	do
	{
		k = 0;
		printf("Сумма вероятностей должна быть равна 1\n");
		for (int i = 0; i < x; i++)
		{
			printf("Введите %d-е число: ", i + 1);
			scanf("%lf", &a[i]);
			do
			{
				printf("Введите вероятность для этого числа: ");
				scanf("%lf", &b[i]);
			} while (b[i] > 1 || b[i] < 0);
			M += a[i] * b[i];
			k += b[i];

		}
		
	} while (k != 1);
	printf("M(X)=%1.3lf\n", M);
}
void dis() { //Дисперсия
	int x;
	double a[100], b[100], c[100], sum1 = 0, sum2 = 0, D, k;
	printf("Введите количество пар чисел: ");
	do
	{
		scanf("%d", &x);
	} while (x <= 0);
	do
	{
		k = 0;
		printf("Сумма вероятностей должна быть равна 1\n");
		for (int i = 0; i < x; i++)
		{
			printf("Введите %d-е число: ", i + 1);
			scanf("%lf", &a[i]);
			do
			{
				printf("Введите вероятность для этого числа: ");
				scanf("%lf", &b[i]);
			} while (b[i] > 1 || b[i] < 0);
			c[i] = a[i] * b[i];
			sum1 += c[i];
			k += b[i];

		}
		if (b[1] == 0, 6 && b[2] == 0, 3 && b[3] == 0, 1 || b[1] == 0, 3 && b[2] == 0, 6 && b[3] == 0, 1)
			k = 1;
	} while (k != 1);

	for (int i = 0; i < x; i++)
	{
		c[i] *= a[i];
		sum2 += c[i];
	}
	D = sum2 - sum1 * sum1;

	for (int i = 0; i < x; i++)
		printf("x(%d)          %1.2lf\n", i, a[i]);

	for (int i = 0; i < x; i++)
		printf("p(%d)          %1.2lf\n", i, b[i]);
	for (int i = 0; i < x; i++)
		printf("x(%d)*p(%d)     %1.2lf\n", i, i, b[i]);
	for (int i = 0; i < x; i++)
		printf("x^2(%d)*p(%d)   %1.2lf\n", i, i, b[i]);

	printf("\n\nДИСПЕРСИЯ D(X)=%lf\n", D);

}
void ver() //вероятность m/n
{
	int m, n;
	double P;
	printf("Вы выбрали вероятность m/n\n");
	printf("Введите количество благоприятных элементов: "); scanf("%d", &m);
	printf("Введите общее число всех равновозможных элементарных исходов: "); scanf("%d", &n);
	P = double(m) / n;
	printf("P=%.3lf\n", P);
}
void verr() //калькулятор
{
	setlocale(LC_ALL, "Russian");
	system("cls");
	int num, k, y{};
	printf("Вы выбрали калькулятор теории вероятности и мат. статистики\n");
	while (y != 2)
	{
		printf("Введите номер задание:\n");
		printf("1-Вероятность m\n");
		printf("2-Дисперсия для дискретного распределения величин\n");
		printf("3-Мат. ожидание для дискретного распределения величин\n");
		do
		{
			scanf("%d", &num);
		} while (num < 1 || num>3);
		switch (num)
		{
		case 1:
			ver();
			break;
		case 2:
			dis();
			break;
		case 3:
			mat();
			break;
		default:
			break;
		}
		printf("\nЖелаете продолжить?\n1-да\n2-нет\n");
		do
		{
			scanf("%d", &y);
		} while (y < 1 || y>2);
	}


}
