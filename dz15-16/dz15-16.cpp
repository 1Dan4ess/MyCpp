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

void addCol(int**& a, int row, int& col, int n) 
{
	int** newA = new int* [row];
	for (int i = 0; i < row; i++) 
	{
		newA[i] = new int[col + 1];
	}
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col + 1; j++) 
		{
			if (j < n) 
			{
				newA[i][j] = a[i][j];
			}
			else if (j == n) 
			{
				newA[i][j] = 0;
			}
			else 
			{
				newA[i][j] = a[i][j - 1];
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	a = newA;
	col++;
}

void delCol(int**& a, int row, int& col, int n) 
{
	int** newA = new int* [row];
	for (int i = 0; i < row; i++) 
	{
		newA[i] = new int[col - 1];
	}
	for (int i = 0; i < row; i++) 
	{
		int newcol = 0;
		for (int j = 0; j < col; j++) 
		{
			if (j != n) 
			{
				newA[i][newcol] = a[i][j];
				newcol++;
			}		
		}
	}
	for (int i = 0; i < row; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	a = newA;
	col--;
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	//1
	//int row, col;
	//cin >> row;
	//cin >> col;
	//int** a = nullptr;

	//createArray(a, row, col);
	//setArray(a, row, col);
	//cout << endl;
	//printArray(a, row, col);
	//int n;
	//cout << "Позиція: ";
	//cin >> n;
	//addCol(a, row, col, n-1);
	//cout << endl;
	//printArray(a, row, col);


	//2
	int row, col;
	cin >> row;
	cin >> col;
	int** a = nullptr;

	createArray(a, row, col);
	setArray(a, row, col);
	cout << endl;
	printArray(a, row, col);
	int n;
	cout << "Позиція: ";
	cin >> n;
	delCol(a, row, col, n-1);
	cout << endl;
	printArray(a, row, col);
}