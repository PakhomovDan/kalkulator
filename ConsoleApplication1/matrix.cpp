#include <iostream>
#include "matrix_header.h"
#include <clocale>

void MatrixInput(int a[100][100], int n, int m) {

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            std::cout << "a[" << i << "][" << j << "]= ";
            std::cin >> a[i][j];
        }
}

void SumMatrix() {
    int A[100][100];
    int B[100][100];
    int C[100][100];
    int n, m;

    do {
        std::cout << "Введите количество строк";
        std::cin >> n;
        if (n <= 0) std::cout << "Error. Количество строк не может быть меньше либо равно 0.";
    } while (n <= 0);

    do {
        std::cout << "Введите количество столбцов";
        std::cin >> m;
        if (m <= 0) std::cout << "Error. Количество столбцов не может быть меньше либо равно 0.";
    } while (m <= 0);

    MatrixInput(A, n, m);
    MatrixInput(B, n, m);

    std::cout << "Ответ: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] + B[i][j];
            std::cout << C[i][j];
        }
        std::cout << std::endl;
    }
}

void DifferenceMatrix() {
    int A[100][100];
    int B[100][100];
    int C[100][100];
    int n, m;

    do {
        std::cout << "Введите количество строк";
        std::cin >> n;
        if (n <= 0) std::cout << "Error. Количество строк не может быть меньше либо равно 0.";
    } while (n <= 0);

    do {
        std::cout << "Введите количество столбцов";
        std::cin >> m;
        if (m <= 0) std::cout << "Error. Количество столбцов не может быть меньше либо равно 0.";
    } while (m <= 0);

    MatrixInput(A, n, m);
    MatrixInput(B, n, m);

    std::cout << "Ответ: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] - B[i][j];
            std::cout << C[i][j];
        }
        std::cout << std::endl;
    }
}

void MatrixMultiplication() {
    int A[100][100];
    int B[100][100];
    int C[100][100];
    int n, m;
    int n2, m2;

    do {
        std::cout << "Введите количество строк первой матрицы.";
        std::cin >> n;
        if (n <= 0) std::cout << "Error. Количество строк не может быть меньше либо равно 0.";
    } while (n <= 0);

    do {
        std::cout << "Введите количество столбцов первой матрицы.";
        std::cin >> m;
        if (m <= 0) std::cout << "Error. Количество столбцов не может быть меньше либо равно 0.";
    } while (m <= 0);

    do {
        std::cout << "Введите количество строк второй матрицы.";
        std::cin >> n2;
        if (n2 <= 0) std::cout << "Error. Количество строк не может быть меньше либо равно 0." << std::endl;
        if (n2 != m) std::cout << "Error. Количество строк первой матрицы должно быть равно количеству столбцов второй матрицы." << std::endl;
    } while (n2 <= 0);

    do {
        std::cout << "Введите количество столбцов второй матрицы.";
        std::cin >> m2;
        if (m2 <= 0) std::cout << "Error. Количество столбцов не может быть меньше либо равно 0." << std::endl;
        if (m2 != n) std::cout << "Error. Количество стобцов первой матрицы должно быть равно количеству строк второй матрицы." << std::endl;
    } while (m2 <= 0);

    MatrixInput(A, n, m);
    MatrixInput(B, n2, m2);

    std::cout << "Ответ: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
            for (int z = 0; z < m; z++)
                C[i][j] += A[i][z] * B[z][j];
            std::cout << C[i][j];
        }
        std::cout << std::endl;
    }
}

void MatrixMultiplicationByNumber() {
    int Number;
    int A[100][100];
    int B[100][100];
    int C[100][100];
    int n, m;

    std::cout << "Введите число, на которое будет умножать матрицу";
    std::cin >> Number;

    do {
        std::cout << "Введите количество строк";
        std::cin >> n;
        if (n <= 0) std::cout << "Error. Количество строк не может быть меньше либо равно 0.";
    } while (n <= 0);

    do {
        std::cout << "Введите количество столбцов";
        std::cin >> m;
        if (m <= 0) std::cout << "Error. Количество столбцов не может быть меньше либо равно 0.";
    } while (m <= 0);

    MatrixInput(A, n, m);

    std::cout << "Ответ: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] * Number;
            std::cout << C[i][j];
        }
        std::cout << std::endl;
    }
}

void DifferenceMatrixByNumber() {
    int Number;
    int A[100][100];
    int B[100][100];
    int C[100][100];
    int n, m;

    std::cout << "Введите число, на которое будет вычитаться из матрицы";
    std::cin >> Number;

    do {
        std::cout << "Введите количество строк";
        std::cin >> n;
        if (n <= 0) std::cout << "Error. Количество строк не может быть меньше либо равно 0.";
    } while (n <= 0);

    do {
        std::cout << "Введите количество столбцов";
        std::cin >> m;
        if (m <= 0) std::cout << "Error. Количество столбцов не может быть меньше либо равно 0.";
    } while (m <= 0);

    MatrixInput(A, n, m);

    std::cout << "Ответ: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] - Number;
            std::cout << C[i][j];
        }
        std::cout << std::endl;
    }
}

void SumMatrixWithNumber() {
    int Number;
    int A[100][100];
    int B[100][100];
    int C[100][100];
    int n, m;

    std::cout << "Введите число, с которым будет складываться матрица";
    std::cin >> Number;

    do {
        std::cout << "Введите количество строк";
        std::cin >> n;
        if (n <= 0) std::cout << "Error. Количество строк не может быть меньше либо равно 0.";
    } while (n <= 0);

    do {
        std::cout << "Введите количество столбцов";
        std::cin >> m;
        if (m <= 0) std::cout << "Error. Количество столбцов не может быть меньше либо равно 0.";
    } while (m <= 0);

    MatrixInput(A, n, m);

    std::cout << "Ответ: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] + Number;
            std::cout << C[i][j];
        }
        std::cout << std::endl;
    }
}

void MatrixTransposition() {
    int A[100][100];
    int T[100][100];
    int n, m;

    do {
        std::cout << "Введите количество строк";
        std::cin >> n;
        if (n <= 0) std::cout << "Error. Количество строк не может быть меньше либо равно 0.";
    } while (n <= 0);

    do {
        std::cout << "Введите количество столбцов";
        std::cin >> m;
        if (m <= 0) std::cout << "Error. Количество столбцов не может быть меньше либо равно 0.";
    } while (m <= 0);

    MatrixInput(A, n, m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            std::cout << T[i][j];
        std::cout << std::endl;
    }
}

//определитель матрицы
void matrixDeterminant() {
    int n;
    double tmp, d;

    do {
        std::cout << "Введите размер матрицы: ";
        std::cin >> n;
        if (n <= 0) {
            std::cout << "Некорректный ввод!\n";
        }

    } while (n <= 0);

    auto** arr = new double* [n];

    for (int i = 0; i < n; i++) 
        arr[i] = new double[n];
    
    std::cout << "Введите матрицу:\n";
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] = ", i, j);
            std::cin >> arr[i][j];
        }

    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = -arr[i][k] / arr[k][k];
            for (int j = 0; j < n; j++) 
                arr[i][j] += arr[k][j] * tmp;
            
        }
    }

    std::cout.precision(2);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            std::cout.width(8);
        
    
    d = 1;
    for (int i = 0; i < n; i++) 
        d *= arr[i][i];
    
    std::cout << std::fixed << "\nОпределитель матрицы: " << d << "\n";
}

void matrixInversionRealise(double** A, int N)
{
    double temp;

    auto** arr = new double* [N];

    for (int i = 0; i < N; i++)
        arr[i] = new double[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = 0.0;

            if (i == j)
                arr[i][j] = 1.0;
        }

    for (int k = 0; k < N; k++)
    {
        temp = A[k][k];

        for (int j = 0; j < N; j++)
        {
            A[k][j] /= temp;
            arr[k][j] /= temp;
        }

        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                arr[i][j] -= arr[k][j] * temp;
            }
        }
    }

    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                arr[i][j] -= arr[k][j] * temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = arr[i][j];

}

//обратная матрица
void matrixInversion() {

    int A[100][100];
    int n, m;
    do {
        std::cout << "Введите количество строк квадратной матрицы: ";
        std::cin >> n;
        if (n <= 0) std::cout << "Error. Количество строк не может быть меньше либо равно 0.";
    } while (n <= 0);
    m = n;
    MatrixInput(A, n, m);
    double temp;

    auto** arr = new double* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new double[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0.0;

            if (i == j)
                arr[i][j] = 1.0;
        }

    for (int k = 0; k < n; k++)
    {
        temp = A[k][k];

        for (int j = 0; j < n; j++)
        {
            A[k][j] /= temp;
            arr[k][j] /= temp;
        }

        for (int i = k + 1; i < n; i++)
        {
            temp = A[i][k];

            for (int j = 0; j < n; j++)
            {
                A[i][j] -= A[k][j] * temp;
                arr[i][j] -= arr[k][j] * temp;
            }
        }
    }

    for (int k = n - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];

            for (int j = 0; j < n; j++)
            {
                A[i][j] -= A[k][j] * temp;
                arr[i][j] -= arr[k][j] * temp;
            }
        }
    }

    std::cout << "Обратная матрица: "<<'\n';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = arr[i][j];
            std::cout << "arr["<<i<<"]["<< j << "]=" << arr[i][j] << "\n";
        }
    
}

void matrix_main() {
    setlocale(LC_ALL, "rus");
    system("cls");
    int Variant = 0, Variant2;
    do
    {
        std::cout << "Меню вариантов: " << std::endl;
        std::cout << "1 - Сложение матриц" << std::endl;
        std::cout << "2 - Разность матриц" << std::endl;
        std::cout << "3 - Умножение матриц" << std::endl;
        std::cout << "4 - Умножение матрицы на число" << std::endl;
        std::cout << "5 - Сложение матрицы с числом" << std::endl;
        std::cout << "6 - Вычитание числа из матрицы" << std::endl;
        std::cout << "7 - Транспонирование" << std::endl;
        std::cout << "8 - Определитель матрицы" << std::endl;
        std::cout << "9 - Обратная матрица" << std::endl;
        std::cout << "0 - Выход из матричного калькулятора." << std::endl;

        std::cout << "Введите вариант: ";
        std::cin >> Variant;
        switch (Variant)
        {
        case 1: SumMatrix();  break;
        case 2: DifferenceMatrix(); break;
        case 3: MatrixMultiplication(); break;
        case 4: MatrixMultiplicationByNumber(); break;
        case 5: SumMatrixWithNumber(); break;
        case 6: DifferenceMatrixByNumber(); break;
        case 7: MatrixTransposition(); break;
        case 8: matrixDeterminant(); break;
        case 9: matrixInversion(); break;
        case 0: std::cout << "Выход из калькулятора матриц."; break;
        default: std::cout << "Error. Такого варианта не существует. Повторите попытку. "; break;
        }
        std::cout << "Выйти из калькулятора матриц? 0 - выход " << std::endl;
        std::cout << "Введите: ";
        std::cin >> Variant2;
        system("cls");
    } while (Variant2 != 0);
}