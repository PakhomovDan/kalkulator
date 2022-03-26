#include "combinatorika_header.h"

void Arrangement(int inp) {
	int n, m, res = 1;
	system("cls");
	(inp == 1) ? cout << "Размещение с повторением" << endl : cout << "Размещение без повторений" << endl;

	do {
		cout << "Введите количество всех эелементов(1 < n <= 10): ";
		cin >> n;
		if (n <= 1 || n > 10) cout << "Количество элементов должно быть больше 1 и меньше 11" << endl;
	} while (n <= 1 || n > 10);

	do {
		cout << "Введите m: ";
		cin >> m;
		if (m < 1 || n < m || n == m) cout << "m должно быть больше 1, меньше, чем n" << endl;
	} while (m < 1 || n < m || n == m);
	system("cls");


	if (inp == 1) { // с повторением
		res = pow(n, m);
	}
	else { // без повторений
		int st = 1, st1;
		st1 = n - m;
		for (int i = 1; i <= n; i++) {
			st *= i;
			if ((n - m) > i) st1 *= i;
		}
		res = st / st1;
	}

	cout << "n= " << n << endl << "m= " << m << endl;
	cout << "Результат= " << res << endl;
};


//сочетание с повторением или без
void Combinations(int inp) {
	int n, m, res = 1;
	system("cls");

	(inp == 3) ? cout << "Сочетание с повторением" << endl : cout << " сочетание без повторений" << endl;

	do {
		cout << "Введите количество всех эелементов(n < 10): ";
		cin >> n;
		if (n <= 1 || n >= 10) cout << "Количество элементов должно быть больше 1" << endl;
	} while (n <= 1 || n >= 10);

	do {
		cout << "Введите m: ";
		cin >> m;
		if (m < 1 || n < m || n == m || n + m > 12) cout << "m должно быть больше 1, меньше, чем 4 (0<m<4)" << endl;
	} while (m < 1 || n < m || n == m || n + m > 12);
	system("cls");

	if (inp == 3) {// с повторением 
		int st = 1, st1;
		st = m + n - 1;
		st1 = n - 1;
		for (int i = 1; i < n + m - 1; i++) {
			st *= i;
			if (n - 1 > i)st1 *= i;
		}
		res = st / st1;
	}
	else {// без повторений
		int st = 1, st1 = 1, st2 = 1;
		st2 = n - m;
		for (int i = 1; i <= n; i++) {
			st *= i;
			if (m > i) st1 *= i;
			if (n - m > i) st2 *= i;
		}
		res = st / (st1 * st2);
	}

	cout << "n= " << n << endl << "m= " << m << endl;
	cout << "Результат= " << res << endl;
};


int fact(int i)
{
	if (i == 0) return 1;
	else return i * fact(i - 1);
}

//перестановки с повторением и без
void Permutations(int inp) {
	system("cls");
	int n, res = 1;

	(inp == 5) ? cout << "перестановки с повторением " << endl : cout << "перестановки без повторений" << endl;

	do {
		cout << "Введине общее n: ";
		cin >> n;
	} while (n <= 0 || n > 10);

	int k, k1, st = 1, sum = 0,c=0;
	if (inp == 5) {// перестановки с повторением
		do {
			cout << "Введите количество одинаковых элементов: ";
			cin >> k;
		} while (k <= 0);

		do {
			c++;
			cout << c << ":";
			cin >> k1;
			st *= fact(k1);
			sum += k1;
		} while (c < k);
		res = fact(n) / double(st);
		//cout << res;
	}
	else {
		for (int i = 1; i <= n; i++) {// без повторений
			res *= i;
		}
	}


	if (res <= 0 || sum != n && inp == 5) cout << "Ошибка, перепроверьте данные" << endl;
	else {
		cout << "n= " << n << endl;
		cout << "Результат= " << res << endl;
	}
};

void combinatorika_main()
{
	system("cls");
	int inp, inp2;

	do {
		cout << "1 - размещение с повторением" << endl;
		cout << "2 - размещение без повторений" << endl;
		cout << "3 - сочетание с повторением" << endl;
		cout << "4 - сочетание без повторений" << endl;
		cout << "5 - перестановки с повторением" << endl;
		cout << "6 - перестановки без повторений" << endl;
		cout << "Выберите формулу комбинаторики: ";
		cin >> inp;

		switch (inp) {
		case 1:
			Arrangement(inp); // размещение с повторением
			break;
		case 2:
			Arrangement(inp); // размещение без повторений
			break;
		case 3:
			Combinations(inp); // сочетание с повторением
			break;
		case 4:
			Combinations(inp); // сочетание без повторений
			break;
		case 5:
			Permutations(inp); // перестановки с повторением
			break;
		case 6:
			Permutations(inp); // перестановки без повторений
			break;
		default: cout << "Неверный ввод, введите 1, 2, 3, 4, 5 или 6" << endl;
		}
		cout << "Вернуться к выбору вормулы? 0 - завершить программу, продолжить - любое другое число" << endl;
		cout << "Введите: ";
		cin >> inp2;
		system("cls");
	} while (inp2 != 0);
}
