#include "combinatorika_header.h"

void Arrangement(int inp) {
	int n, m, res = 1;
	system("cls");
	(inp == 1) ? cout << "���������� � �����������" << endl : cout << "���������� ��� ����������" << endl;

	do {
		cout << "������� ���������� ���� ����������(1 < n <= 10): ";
		cin >> n;
		if (n <= 1 || n > 10) cout << "���������� ��������� ������ ���� ������ 1 � ������ 11" << endl;
	} while (n <= 1 || n > 10);

	do {
		cout << "������� m: ";
		cin >> m;
		if (m < 1 || n < m || n == m) cout << "m ������ ���� ������ 1, ������, ��� n" << endl;
	} while (m < 1 || n < m || n == m);
	system("cls");


	if (inp == 1) { // � �����������
		res = pow(n, m);
	}
	else { // ��� ����������
		int st = 1, st1;
		st1 = n - m;
		for (int i = 1; i <= n; i++) {
			st *= i;
			if ((n - m) > i) st1 *= i;
		}
		res = st / st1;
	}

	cout << "n= " << n << endl << "m= " << m << endl;
	cout << "���������= " << res << endl;
};


//��������� � ����������� ��� ���
void Combinations(int inp) {
	int n, m, res = 1;
	system("cls");

	(inp == 3) ? cout << "��������� � �����������" << endl : cout << " ��������� ��� ����������" << endl;

	do {
		cout << "������� ���������� ���� ����������(n < 10): ";
		cin >> n;
		if (n <= 1 || n >= 10) cout << "���������� ��������� ������ ���� ������ 1" << endl;
	} while (n <= 1 || n >= 10);

	do {
		cout << "������� m: ";
		cin >> m;
		if (m < 1 || n < m || n == m || n + m > 12) cout << "m ������ ���� ������ 1, ������, ��� 4 (0<m<4)" << endl;
	} while (m < 1 || n < m || n == m || n + m > 12);
	system("cls");

	if (inp == 3) {// � ����������� 
		int st = 1, st1;
		st = m + n - 1;
		st1 = n - 1;
		for (int i = 1; i < n + m - 1; i++) {
			st *= i;
			if (n - 1 > i)st1 *= i;
		}
		res = st / st1;
	}
	else {// ��� ����������
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
	cout << "���������= " << res << endl;
};


int fact(int i)
{
	if (i == 0) return 1;
	else return i * fact(i - 1);
}

//������������ � ����������� � ���
void Permutations(int inp) {
	system("cls");
	int n, res = 1;

	(inp == 5) ? cout << "������������ � ����������� " << endl : cout << "������������ ��� ����������" << endl;

	do {
		cout << "������� ����� n: ";
		cin >> n;
	} while (n <= 0 || n > 10);

	int k, k1, st = 1, sum = 0,c=0;
	if (inp == 5) {// ������������ � �����������
		do {
			cout << "������� ���������� ���������� ���������: ";
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
		for (int i = 1; i <= n; i++) {// ��� ����������
			res *= i;
		}
	}


	if (res <= 0 || sum != n && inp == 5) cout << "������, ������������� ������" << endl;
	else {
		cout << "n= " << n << endl;
		cout << "���������= " << res << endl;
	}
};

void combinatorika_main()
{
	system("cls");
	int inp, inp2;

	do {
		cout << "1 - ���������� � �����������" << endl;
		cout << "2 - ���������� ��� ����������" << endl;
		cout << "3 - ��������� � �����������" << endl;
		cout << "4 - ��������� ��� ����������" << endl;
		cout << "5 - ������������ � �����������" << endl;
		cout << "6 - ������������ ��� ����������" << endl;
		cout << "�������� ������� �������������: ";
		cin >> inp;

		switch (inp) {
		case 1:
			Arrangement(inp); // ���������� � �����������
			break;
		case 2:
			Arrangement(inp); // ���������� ��� ����������
			break;
		case 3:
			Combinations(inp); // ��������� � �����������
			break;
		case 4:
			Combinations(inp); // ��������� ��� ����������
			break;
		case 5:
			Permutations(inp); // ������������ � �����������
			break;
		case 6:
			Permutations(inp); // ������������ ��� ����������
			break;
		default: cout << "�������� ����, ������� 1, 2, 3, 4, 5 ��� 6" << endl;
		}
		cout << "��������� � ������ �������? 0 - ��������� ���������, ���������� - ����� ������ �����" << endl;
		cout << "�������: ";
		cin >> inp2;
		system("cls");
	} while (inp2 != 0);
}
