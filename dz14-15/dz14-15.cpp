#include<iostream>
#include<Windows.h>
#include <iomanip>
using namespace std;

template<class T>
void setArray(T** a, int row, int col, int min = 1, int max = 10)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			a[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

template<class T>
void createArray(T**& p, int row, int col)
{
	p = new T * [row];
	for (size_t i = 0; i < row; i++)
	{
		p[i] = new T[col];
	}
}

void printArray(int** arr, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int** dobytokMatrix(int** a, int** b, int row1, int col1, int row2, int col2)
{
	int** c = nullptr;
	int col = col2, row = row1;
	createArray(c, row, col);
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			c[i][j] = 0;
			for (size_t h = 0; h < col1; h++) 
			{
				c[i][j] += a[i][h] * b[h][j];
			}
		}
	}
	return c;
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int row1, row2, col1, col2;
	cout << "1: ";
	cout << endl;
	cin >> row1 >> col1;
	cout << endl;
	int** a = nullptr;
	createArray(a, row1, col1);
	setArray(a, row1, col1);
	printArray(a, row1, col1);

	cout << endl;
	cout << "2: ";
	cout << endl;
	cin >> row2 >> col2;
	cout << endl;
	int** b = nullptr;
	createArray(b, row2, col2);
	setArray(b, row2, col2);
	printArray(b, row2, col2);

	cout << endl;
	cout << "3:" << endl;
	if (col1 == row2)
	{
		printArray(dobytokMatrix(a, b, row1, col1, row2, col2), row1, col2);
	}
	else
	{
		cout << "Помилка" << endl;
	}
}