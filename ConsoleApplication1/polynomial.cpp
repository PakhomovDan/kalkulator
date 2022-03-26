#define _CRT_SECURE_NO_WARNINGS
#include "polynomial_header.h"

//меню
void MenuPolynomial()
{
    int var;//переменная для циклического меню калькулятора
    int a[100], b[100], c[100], extent1 = 0, extent2 = 0, extent3 = 0; //а-массив первого многочленя,b-массив для второго многочлена,с-массив для многочлена в ответе; extent1,extent2,extent3-значения максимальных степеней первого многочлена, второго многочлена и многочлена в ответе соотвественно
    do
    {
        printf("«Калькулятор многочленов»\n\nВыберите режим работы программы:\n");
        printf("Нажмите 1, если хотите перейти в режим «Сложение многочленов»;\n");
        printf("Нажмите 2, если хотите перейти в режим «Вычитание многочленов»;\n");
        printf("Нажмите 3, если хотите перейти в режим «Умножение многочленов»;\n");
        printf("Нажмите 4, если хотите перейти в режим «Умножение многочлена на число»;\n");
        printf("Нажмите 5, если хотите перейти в режим «Вычисление производной от многочлена»;\n");
        printf("Нажмите 6, если хотите перейти в режим «Деление многочленов в столбик»;\n");
        printf("Нажмите 0, если хотите выйти из калькулятора многочленов.\n");
        do
        {
            printf("Вы выбрали вариант №");
            scanf("%d", &var);
            if (var < 0 || var>6)
                printf("Введите число от 0 до 6\n");
        } while (var < 0 || var>6);
        printf("\n");
        if (var == 1)
        {
            printf("Вы выбрали режим «Сложение многочленов».\n");
            int set;//переменная для продолжения работы программы или выхода в меню калькулятора
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                Addition(a, extent1, b, extent2, c, extent3);
        }
        if (var == 2)
        {
            printf("Вы выбрали режим «Вычитание многочленов».\n");
            int set;//переменная для продолжения работы программы или выхода в меню калькулятора
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                Substraction(a, extent1, b, extent2, c, extent3);
        }
        if (var == 3)
        {
            printf("Вы выбрали режим «Умножение многочленов».\n");
            int set;//переменная для продолжения работы программы или выхода в меню калькулятора
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                Multiplication1(a, extent1, b, extent2, c, extent3);
        }
        if (var == 4)
        {
            printf("Вы выбрали режим «Умножение многочлена на число».\n");
            int set;//переменная для продолжения работы программы или выхода в меню калькулятора
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                Multiplication2(a, extent1, c, extent3);
        }
        if (var == 5)
        {
            printf("Вы выбрали режим «Вычисление производной от многочлена».\n");
            int set;//переменная для продолжения работы программы или выхода в меню калькулятора
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                Derivative(a, extent1, c, extent3);
        }
        if (var == 6)
        {
            printf("Вы выбрали режим «Деление многочленов в столбик».\n");
            int set;//переменная для продолжения работы программы или выхода в меню калькулятора
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                Division(a, extent1, b, extent2, c, extent3);
        }
    } while (var != 0);
}
//ввод первого многочлена
void InputFirst(int* a, int& extent1)
{
    do
    {
        scanf("%d", &extent1);
        if (extent1 < 1 || extent1>21)
            printf("Введите число от 1 до 20 ");
    } while (extent1 < 1 || extent1>21);
    for (int i = extent1; i >= 0; i--)
    {
        printf("Введите коэффициент при x^%d ", i);
        scanf("%d", &a[i]);
    }
}

//ввод второго многочлена
void InputSecond(int* b, int& extent2)
{
    printf("Введите максимальную степень переменной х второго многочлена: ");
    do
    {
        scanf("%d", &extent2);
        if (extent2 < 1 || extent2>21)
            printf("Введите число от 1 до 20 ");
    } while (extent2 < 1 || extent2>21);
    for (int j = extent2; j >= 0; j--)
    {
        printf("Введите коэффициент при x^%d ", j);
        scanf("%d", &b[j]);
    }
    printf("\n");
}
//вывод первого многочлена
void OutputFirst(int* a, int& extent1)
{
    int k = extent1 + 1;
    for (int i = extent1; i >= 0; i--)
    {
        if (a[i] == 0)
            k--;
    }
    if (k != 0)
    {
        printf("(");
        for (int i = extent1; i >= 0; i--)
        {
            int nextI;
            nextI = i - 1;
            if (a[i] >= 0)
            {
                if (a[0] != 0)
                {
                    if (a[i] != 1)
                    {
                        if (i != 0 && i != 1 && a[i] != 0)
                        {
                            printf("%dx^%d", a[i], i);
                            if (a[nextI] > 0)
                                printf("+");
                        }
                        if (i == 1 && a[i] != 0)
                            printf("%dx", a[i]);
                    }
                    if (a[i] == 1)
                    {
                        if (i != 0 && i != 1 && a[i] != 0)
                        {
                            printf("x^%d", i);
                            if (a[nextI] > 0)
                                printf("+");
                        }
                        if (i == 1 && a[i] != 0)
                            printf("x");
                    }
                    if (i == 0)
                        printf("+%d", a[0]);
                }
                if (a[0] == 0)
                {
                    if (a[i] != 1)
                    {
                        if (a[nextI] == 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("%dx^%d+", a[i], i);
                            if (i == 1 && a[i] != 0)
                                printf("%dx", a[i]);
                        }
                        if (a[nextI] != 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("%dx^%d+", a[i], i);
                            if (i == 1 && a[i] != 0)
                                printf("%dx", a[i]);
                        }
                    }
                    if (a[i] == 1)
                    {
                        if (a[nextI] == 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("x^%d+", i);
                            if (i == 1 && a[i] != 0)
                                printf("x");
                        }
                        if (a[nextI] != 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("x^%d+", i);
                            if (i == 1 && a[i] != 0)
                                printf("x");
                        }
                    }
                }
            }

            if (a[i] <= 0)
            {
                if (a[0] != 0)
                {
                    if (a[i] != -1)
                    {
                        if (i != 0 && i != 1 && a[i] != 0)
                            printf("%dx^%d", a[i], i);
                        if (i == 1 && a[i] != 0)
                            printf("%dx", a[i]);
                    }
                    if (a[i] == -1)
                    {
                        if (i != 0 && i != 1 && a[i] != 0)
                            printf("-x^%d", i);
                        if (i == 1 && a[i] != 0)
                            printf("-x");
                    }
                    if (i == 0)
                        printf("%d", a[0]);
                }
                if (a[0] == 0)
                {
                    if (a[i] != -1)
                    {
                        if (a[nextI] == 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("%dx^%d+", a[i], i);
                            if (i == 1 && a[i] != 0)
                                printf("%dx", a[i]);
                        }
                        if (a[nextI] != 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("%dx^%d+", a[i], i);
                            if (i == 1 && a[i] != 0)
                                printf("%dx", a[i]);
                        }
                    }
                    if (a[i] == -1)
                    {
                        if (a[nextI] == 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("x^%d", i);
                            if (i == 1 && a[i] != 0)
                                printf("-x");
                        }
                        if (a[nextI] != 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("x^%d", i);
                            if (i == 1 && a[i] != 0)
                                printf("-x");
                        }
                    }
                }
            }
        }
        printf(")");
    }
    else
        printf("0");
}
//вывод второго многочлена
void OutputSecond(int* b, int& extent2)
{
    int k = extent2 + 1;
    for (int j = extent2; j >= 0; j--)
    {
        if (b[j] == 0)
            k--;
    }
    if (k != 0)
    {
        printf("(");
        for (int j = extent2; j >= 0; j--)
        {
            int nextJ;
            nextJ = j - 1;
            if (b[j] >= 0)
            {
                if (b[0] != 0)
                {
                    if (b[j] != 1)
                    {
                        if (j != 0 && j != 1 && b[j] != 0)
                        {
                            printf("%dx^%d", b[j], j);
                            if (b[nextJ] > 0)
                                printf("+");
                        }
                        if (j == 1 && b[j] != 0)
                            printf("%dx", b[j]);
                    }
                    if (b[j] == 1)
                    {
                        if (j != 0 && j != 1 && b[j] != 0)
                        {
                            printf("x^%d", j);
                            if (b[nextJ] > 0)
                                printf("+");
                        }
                        if (j == 1 && b[j] != 0)
                            printf("x");
                    }
                    if (j == 0)
                        printf("+%d", b[0]);
                }
                if (b[0] == 0)
                {
                    if (b[j] != 1)
                    {
                        if (b[nextJ] == 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("%dx^%d+", b[j], j);
                            if (j == 1 && b[j] != 0)
                                printf("%dx", b[j]);
                        }
                        if (b[nextJ] != 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("%dx^%d+", b[j], j);
                            if (j == 1 && b[j] != 0)
                                printf("%dx", b[j]);
                        }
                    }
                    if (b[j] == 1)
                    {
                        if (b[nextJ] == 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("x^%d+", j);
                            if (j == 1 && b[j] != 0)
                                printf("x");
                        }
                        if (b[nextJ] != 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("x^%d+", j);
                            if (j == 1 && b[j] != 0)
                                printf("x");
                        }
                    }
                }
            }
            if (b[j] <= 0)
            {
                if (b[0] != 0)
                {
                    if (b[j] != -1)
                    {
                        if (j != 0 && j != 1 && b[j] != 0)
                            printf("%dx^%d", b[j], j);
                        if (j == 1 && b[j] != 0)
                            printf("%dx", b[j]);
                    }
                    if (b[j] == -1)
                    {
                        if (j != 0 && j != 1 && b[j] != 0)
                            printf("-x^%d", j);
                        if (j == 1 && b[j] != 0)
                            printf("-x");
                    }
                    if (j == 0)
                        printf("%d", b[0]);
                }
                if (b[0] == 0)
                {
                    if (b[j] != -1)
                    {
                        if (b[nextJ] == 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("%dx^%d", b[j], j);
                            if (j == 1 && b[j] != 0)
                                printf("%dx", b[j]);
                        }
                        if (b[nextJ] != 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("%dx^%d", b[j], j);
                            if (j == 1 && b[j] == 0)
                                printf("%dx", b[j]);
                        }
                    }
                    if (b[j] == -1)
                    {
                        if (b[nextJ] == 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("x^%d", j);
                            if (j == 1 && b[j] != 0)
                                printf("-x");
                        }
                        if (b[nextJ] != 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("x^%d", j);
                            if (j == 1 && b[j] != 0)
                                printf("-x");
                        }
                    }
                }
            }
        }
        printf(")");
    }
    else
        printf("0");
}
//вывод для функций
void OtputFunctions(int* c, int& extent3)
{
    int k = extent3 + 1;
    for (int g = extent3; g >= 0; g--)
    {
        if (c[g] == 0)
            k--;
    }
    if (k != 0)
    {
        for (int g = extent3; g >= 0; g--)
        {
            int nextG;
            nextG = g - 1;
            if (c[g] >= 0)
            {
                if (c[0] != 0)
                {
                    if (c[g] != 1)
                    {
                        if (g != 0 && g != 1 && c[g] != 0)
                        {
                            printf("%dx^%d", c[g], g);
                            if (c[nextG] > 0)
                                printf("+");
                        }
                        if (g == 1 && c[g] != 0)
                            printf("%dx", c[g]);
                    }
                    if (c[g] == 1)
                    {
                        if (g != 0 && g != 1 && c[g] != 0)
                        {
                            printf("x^%d", g);
                            if (c[nextG] > 0)
                                printf("+");
                        }
                        if (g == 1 && c[g] != 0)
                            printf("x");
                    }
                    if (g == 0)
                        printf("+%d", c[0]);
                }
                if (c[0] == 0)
                {
                    if (c[g] != 1)
                    {
                        if (c[nextG] == 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("%dx^%d+", c[g], g);
                            if (g == 1 && c[g] != 0)
                                printf("%dx", c[g]);
                        }
                        if (c[nextG] != 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("%dx^%d+", c[g], g);
                            if (g == 1 && c[g] != 0)
                                printf("%dx", c[g]);
                        }
                    }
                    if (c[g] == 1)
                    {
                        if (c[nextG] == 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("x^%d+", g);
                            if (g == 1 && c[g] != 0)
                                printf("x");
                        }
                        if (c[nextG] != 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("x^%d+", g);
                            if (g == 1 && c[g] != 0)
                                printf("x");
                        }
                    }
                }
            }
            if (c[g] <= 0)
            {
                if (c[0] != 0)
                {
                    if (c[g] != -1)
                    {
                        if (g != 0 && g != 1 && c[g] != 0)
                        {
                            printf("%dx^%d", c[g], g);
                            if (c[nextG] > 0)
                                printf("+");
                        }
                        if (g == 1 && c[g] != 0)
                        {
                            printf("%dx", c[g]);
                            if (c[nextG] > 0)
                                printf("+");
                        }
                    }
                    if (c[g] == -1)
                    {
                        if (g != 0 && g != 1 && c[g] != 0)
                        {
                            printf("-x^%d", g);
                            if (c[nextG] > 0)
                                printf("+");
                        }
                        if (g == 1 && c[g] != 0)
                        {
                            printf("-x");
                            if (c[nextG] > 0)
                                printf("+");
                        }
                    }
                    if (g == 0)
                        printf("%d", c[0]);
                }
                if (c[0] == 0)
                {
                    if (c[g] != -1)
                    {
                        if (c[nextG] == 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                            {
                                printf("%dx^%d", c[g], g);
                                if (c[nextG] > 0)
                                    printf("+");
                            }
                            if (g == 1 && c[g] != 0)
                                printf("%dx", c[g]);
                        }
                        if (c[nextG] != 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("%dx^%d", c[g], g);
                            if (g == 1 && c[g] == 0)
                                printf("%dx", c[g]);
                        }
                    }
                    if (c[g] == -1)
                    {
                        if (c[nextG] == 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("x^%d", g);
                            if (g == 1 && c[g] != 0)
                                printf("-x");
                        }
                        if (c[nextG] != 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("x^%d", g);
                            if (g == 1 && c[g] != 0)
                                printf("-x");
                        }
                    }
                }
            }
        }
    }
    else
        printf("0");
    printf("\n\n");
}
//cложение двух многочленов
void Addition(int* a, int& extent1, int* b, int& extent2, int* c, int& extent3)
{
    printf("Введите максимальную степень переменной х первого многочлена: ");
    InputFirst(a, extent1);
    InputSecond(b, extent2);
    OutputFirst(a, extent1);
    printf("+");
    OutputSecond(b, extent2);
    printf("=");
    if (extent1 > extent2)
    {
        extent3 = extent1;
        for (int k = extent3; k > extent2; k--)
            b[k] = 0;
    }
    else
    {
        extent3 = extent2;
        for (int k = extent3; k > extent1; k--)
            a[k] = 0;
    }
    for (int i = 0; i <= extent3; i++)
    {
        c[i] = a[i] + b[i];
    }
    OtputFunctions(c, extent3);
}

//вычитание двух многочленов
void Substraction(int* a, int& extent1, int* b, int& extent2, int* c, int& extent3)
{
    printf("Введите максимальную степень переменной х первого многочлена: ");
    InputFirst(a, extent1);
    InputSecond(b, extent2);
    OutputFirst(a, extent1);
    printf("-");
    OutputSecond(b, extent2);
    printf("=");
    if (extent1 > extent2)
    {
        extent3 = extent1;
        for (int k = extent3; k > extent2; k--)
            b[k] = 0;
    }
    else
    {
        extent3 = extent2;
        for (int k = extent3; k > extent1; k--)
            a[k] = 0;
    }
    for (int i = 0; i <= extent3; i++)
    {
        c[i] = a[i] - b[i];
    }
    OtputFunctions(c, extent3);
}

//умножение многочленов
void Multiplication1(int* a, int& extent1, int* b, int& extent2, int* c, int& extent3)
{
    printf("Введите максимальную степень переменной х первого многочлена: ");
    InputFirst(a, extent1);
    InputSecond(b, extent2);
    OutputFirst(a, extent1);
    printf("*");
    OutputSecond(b, extent2);
    printf("=");
    extent3 = extent1 + extent2;
    for (int k = 0; k <= extent3; k++)
        c[k] = 0;
    for (int k = extent3; k > extent1; k--)
        a[k] = 0;
    for (int k = extent3; k > extent2; k--)
        b[k] = 0;
    for (int i = 0; i <= extent3; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            c[i] = c[i] + a[j] * b[i - j];
        }
    }
    OtputFunctions(c, extent3);
}

//умножение многочлена на число
void Multiplication2(int* a, int& extent1, int* c, int& extent3)
{
    int n;
    printf("Введите максимальную степень переменной х многочлена: ");
    InputFirst(a, extent1);
    printf("Введите число, на которое хотите умножить многочлен: ");
    scanf("%d", &n);
    printf("%d*", n);
    OutputFirst(a, extent1);
    printf("=");
    extent3 = extent1;
    for (int i = 0; i <= extent3; i++)
    {
        c[i] = n * a[i];
    }
    OtputFunctions(c, extent3);
}

//производная от многочлена
void Derivative(int* a, int& extent1, int* c, int& extent3)
{
    printf("Введите максимальную степень переменной х многочлена: ");
    InputFirst(a, extent1);
    OutputFirst(a, extent1);
    printf("'=");
    extent3 = extent1 - 1;
    for (int i = 1; i <= extent1; i++)
        c[i - 1] = i * a[i];
    OtputFunctions(c, extent3);
}

//деление многочленов в столбик
void Division(int* a, int& extent1, int* b, int& extent2, int* c, int& extent3)
{
    printf("Извините, функция не реализована.\n\n");
}