#define _CRT_SECURE_NO_WARNINGS
#include "ordinaryFractions_header.h"
void drobi()
{
	setlocale(LC_ALL, "Russian");
	system("cls");
	int num, k, chisl1, znam1, chisl2, znam2;
	int a, b, x, y{}, c, m;
	printf("�� ������� ����������� ������\n");
	while (y != 2)
	{
		printf("\n������� ����� �������:\n");
		printf("1-�������� ������\n");
		printf("2-��������� ������\n");
		printf("3-���������\n");
		printf("4-�������\n");
		printf("5-���������\n");
		printf("6-����������\n");
		printf("7-������������� � ���� ���������� �����\n");
		do
		{
			scanf("%d", &num);
		} while (num < 1 || num>7);
		if (num != 6 && num != 7) {
			printf("������� ��������� 1-�� �����\n");
			scanf("%d", &chisl1);
			printf("������� ����������� 1-�� ����� ");
			do
			{
				printf("�������� �� 0\n");
				scanf("%d", &znam1);
			} while (znam1 == 0);
			printf("������� ��������� 2-�� �����\n");
			scanf("%d", &chisl2);
			printf("������� ����������� 2-�� ����� ");
			do
			{
				printf("�������� �� 0\n");
				scanf("%d", &znam2);
			} while (znam2 == 0);
		}
		else
		{
			printf("������� ���������\n");
			scanf("%d", &chisl1);
			printf("������� ����������� ");
			do
			{
				printf("�������� �� 0\n");
				scanf("%d", &znam1);
			} while (znam1 == 0);
		}

		switch (num)
		{
		case 1:

			system("cls");
			printf("�� ������� �������� ������\n\n");
			m = 0;
			c = 0;
			if (znam1 == znam2)
			{
				a = chisl1 + chisl2;
				b = znam1;
			}
			else
			{
				a = chisl1 * znam2 + chisl2 * znam1;
				b = znam1 * znam2;
			}
			printf("������� ��� �������� ��������� �����?\n");
			printf("1-��\n2-���\n");
			do
			{
				scanf("%d", &x);
			} while (x < 1 || x>2);
			if (x == 1)
			{
				if (a < 0)
				{
					m = -1;
					a *= m;
				}
				while (a - b >= 0)
				{
					c++;
					a -= b;
				}
				for (int i = 2; i < 10000; i++)
				{
					while (a % i == 0 && b % i == 0)
					{
						a /= i;
						b /= i;
					}
				}
				if (m == -1)
				{
					if (c == 0)
						a *= m;
					c *= m;
				}

				if (a == 0)
					printf("����� = %d", c);
				else
				{
					if (c == 0)
						printf("����� = %d/%d", a, b);
					else
						printf("����� = %d(%d/%d)", c, a, b);
				}

			}
			else
				printf("����� = %d/%d", a, b);

			break;
		case 2:
			printf("�� ������� ��������� ������\n\n");
			m = 0;
			c = 0;
			if (znam1 == znam2)
			{
				a = chisl1 - chisl2;
				b = znam1;
			}
			else
			{
				a = chisl1 * znam2 - chisl2 * znam1;
				b = znam1 * znam2;
			}
			printf("������� ��� ��������� ��������� �����?\n");
			printf("1-��\n2-���\n");
			do
			{
				scanf("%d", &x);
			} while (x < 1 || x>2);
			if (x == 1)
			{
				if (a < 0)
				{
					m = -1;
					a *= m;
				}
				while (a - b >= 0)
				{
					c++;
					a -= b;
				}
				for (int i = 2; i < 10000; i++)
				{
					while (a % i == 0 && b % i == 0)
					{
						a /= i;
						b /= i;
					}
				}
				if (m == -1)
				{
					if (c == 0)
						a *= m;
					c *= m;
				}
				if (a == 0)
					printf("�������� = %d", c);
				else
				{
					if (c == 0)
						printf("�������� = %d/%d", a, b);
					else
						printf("�������� = %d(%d/%d)", c, a, b);
				}

			}
			else
				printf("�������� = %d/%d", a, b);
			break;
		case 3:
			printf("�� ������� ��������� ������\n\n");
			m = 0;
			c = 0;
			a = chisl1 * chisl2;
			b = znam1 * znam2;
			printf("������� ��� ��������� ��������� �����?\n");
			printf("1-��\n2-���\n");
			do
			{
				scanf("%d", &x);
			} while (x < 1 || x>2);
			if (x == 1)
			{
				if (a < 0)
				{
					m = -1;
					a *= m;
				}
				while (a - b >= 0)
				{
					c++;
					a -= b;
				}
				for (int i = 2; i < 10000; i++)
				{
					while (a % i == 0 && b % i == 0)
					{
						a /= i;
						b /= i;
					}
				}
				if (m == -1)
				{
					if (c == 0)
						a *= m;
					c *= m;
				}
				if (a == 0)
					printf("������������ = %d", c);
				else
					if (c == 0)
						printf("������������ = %d/%d", a, b);
					else
						printf("������������ = %d(%d/%d)", c, a, b);
			}
			else
				printf("������������ = %d/%d", a, b);
			break;
		case 4:
			printf("�� ������� ������� ������\n\n");
			m = 0;
			c = 0;
			if (chisl1 < 0 || chisl2 < 0)
			{
				m = -1;
				chisl1 *= m;
				chisl2 *= m;
			}
			a = chisl1 * znam2;
			b = chisl2 * znam1;
			printf("������� ��� ������� ��������� �����?\n");
			printf("1-��\n2-���\n");
			do
			{
				scanf("%d", &x);
			} while (x < 1 || x>2);
			if (x == 1)
			{
				if (a < 0)
				{
					m = -1;
					a *= m;
				}
				while (a - b >= 0)
				{
					c++;
					a -= b;
				}
				for (int i = 2; i < 10000; i++)
				{
					while (a % i == 0 && b % i == 0)
					{
						a /= i;
						b /= i;
					}
				}
				if (m == -1)
				{
					if (c == 0)
						a *= m;
					c *= m;
				}
				if (a == 0)
					printf("������� = %d", c);
				else
					if (c == 0)
						printf("������� = %d/%d", a, b);
					else
						printf("������� = %d(%d/%d)", c, a, b);
			}
			else
				printf("������� = %d/%d", a, b);
			break;
		case 5:
			printf("�� ������� ��������� ������\n\n");
			double srav1, srav2;
			srav1 = double(chisl1) / znam1;
			srav2 = double(chisl2) / znam2;
			if (srav1 > srav2)
				printf("%d/%d>%d/%d", chisl1, znam1, chisl2, znam2);
			if (srav1 == srav2)
				printf("%d/%d=%d/%d", chisl1, znam1, chisl2, znam2);
			if (srav1 < srav2)
				printf("%d/%d<%d/%d", chisl1, znam1, chisl2, znam2);
			break;
		case 6:
			printf("�� ������� ���������� ������\n\n");
			m = 0;
			c = 0;
			a = chisl1;
			b = znam1;
			printf("%d/%d", a, b);
			if (a < 0)
			{
				m = -1;
				a *= m;
			}
			while (a - b >= 0)
			{
				c++;
				a -= b;
			}
			for (int i = 2; i < 10000; i++)
			{
				while (a % i == 0 && b % i == 0)
				{
					a /= i;
					b /= i;
				}
			}
			if (m == -1)
			{
				if (c == 0)
					a *= m;
				c *= m;
			}
			if (a == chisl1 && b == znam1)
				printf("\n����� ��� ���������");
			else
			{
				if (a == 0)
					printf(" = %d", c);
				else
					printf(" = %d(%d/%d)", c, a, b);
			}

			break;
		case 7:
			printf("�� ������� ������������� � ���� ���������� �����\n\n");
			double dr;
			dr = double(chisl1) / znam1;
			printf("%d/%d=%lf", chisl1, znam1, dr);
			break;
		default:
			break;
		}
		printf("\n������� ����������?\n1-��\n2-���\n");
		do
		{
			scanf("%d", &y);
			system("cls");
		} while (y < 1 || y>2);
	}
}

