#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void PrintMatr(int**, int, int, const char*); //Функция вывода матрицы
void PrintMatr(double**, int, int, const char*); //
void PrintVect(double*, int, const char*); //Функция вывода решения
void NewMatr(int**&, int, int); //Функция выделения памяти
void NewMatr(double**&, int, int); //
void DelMatr(int**&, int, int); //Функция освобождения памяти
void DelMatr(double**&, int, int); //
void GetRandMatr(int**, int, int, int, int); //Функция рандомного заполнения матрицы
void TriangMatr(int**, double**, int);
void Solve(int**, double*, int);

int main()
{
	setlocale(LC_ALL, "Rus");
	int key = 0;
	int n = 3, m = 4;
	double* x = new double[n];
	int** A;
	do
	{
		cout << "1) СЛАУ методом Гаусса" << endl
			<< "2) Определитель матрицы методом Гаусса" << endl
			<< "3) Обратная матрица методом Гаусса" << endl
			<< "0) выход" << endl;
		cout << endl << "Выберите действие: ";
		cin >> key;
		cout << endl;
		switch (key)
		{
		case 1:
			NewMatr(A, n, m);
			GetRandMatr(A, n, m, 1, 10);
			PrintMatr(A, n, m, "A");
			Solve(A, x, n);
			PrintVect(x, n, "x");
			DelMatr(A, n, m);
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		default:
			if (key != 0)
			{
				cout << "Такого действия нет !" << endl << endl;
			}
			break;
		}
	} while (key != 0);
	delete[]x;
	x = nullptr;
}

void PrintMatr(int** M, int n, int m, const char* namematr)
{
	cout << endl << " " << namematr << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "   " << M[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void PrintMatr(double** M, int n, int m, const char* namematr)
{
	cout << endl << " " << namematr << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "   " << M[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void PrintVect(double* x, int n, const char* namevect)
{
	cout << endl << " " << namevect << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "    " << x[i];
	}
	cout << endl;
}

void NewMatr(int**& M, int n, int m)
{
	cout << "\t-New int matr-" << endl;
	M = new int* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new int[m];
	}
}

void NewMatr(double**& M, int n, int m)
{
	cout << "\t-New double matr-" << endl;
	M = new double* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new double[m];
	}
}

void DelMatr(int**& M, int n, int m)
{
	cout << "\t-Delete int matr-" << endl;
	for (int i = 0; i < n; i++)
	{
		delete[] M[i];
	}
	delete[] M;
}

void DelMatr(double**& M, int n, int m)
{
	cout << "\t-Delete double matr-" << endl;
	for (int i = 0; i < n; i++)
	{
		delete[] M[i];
	}
	delete[] M;
}

void GetRandMatr(int** M, int n, int m, int a, int b)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			M[i][j] = rand() % (b - a - 1) + a;
		}
	}
}

void TriangMatr(int** A, double** B, int n)
{
	double coefficient;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = k + 1; i < n; i++)
		{
			coefficient = -1. * B[i][k] / B[k][k];
			for (int j = k; j < n + 1; j++)
			{
				B[i][j] = B[i][j] + B[k][j] * coefficient;
			}
		}
	}
	PrintMatr(B, n, n + 1, "B");
}

void Solve(int** A, double* x, int n)
{
	double res = 0;
	double** B;
	NewMatr(B, n, n + 1);
	TriangMatr(A, B, n);
	for (int i = n - 1; i >= 0; i--)
	{
		res = 0;
		for (int j = i + 1; j <= n - 1; j++)
		{
			res = res - x[j] * B[i][j];
		}
		res += B[i][n];
		x[i] = res / B[i][i];
	}
	DelMatr(B, n, n + 1);
}