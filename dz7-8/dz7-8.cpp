#include<iostream>
#include<Windows.h>
#include <iomanip>
using namespace std;


int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);


//3
	int min = 0, max = 9;
	const int row = 5, col = 5;
	int a[row][col];
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			a[i][j] = rand() % (max - min + 1) + min;
		}
	}
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int n;
	char dir;
	cout << "Напрямок(ліво - l, право - r, вниз - d, вгору - u): ";
	cin >> dir;
	cout << "Кількість розрядів: ";
	cin >> n;
	if (dir == 'l')
	{
		int b[row][col];
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				int col2 = (j - n + col) % col;
				b[i][col2] = a[i][j];
			}
		}
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
	else if (dir == 'r')
	{
		int b[row][col];
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				int col2 = (j + n + col) % col;
				b[i][col2] = a[i][j];
			}
		}
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
	else if (dir == 'd')
	{
		int b[row][col];
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				int row2 = (i + n) % row;
				b[row2][j] = a[i][j];
			}
		}

		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
	else if (dir == 'u')
	{
		int b[row][col];
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				int row2 = (i - n + row) % row;
				b[row2][j] = a[i][j];
			}
		}

		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
	else
	{
		cout << "Помилка" << endl;
	}
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}
