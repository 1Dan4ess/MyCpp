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

void printArray(int a[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void printArray2(int** arr, int row, int col)
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

//void createArray(int**& p, int row, int col)
//{
//	p = new int * [row];
//	for (size_t i = 0; i < row; i++)
//	{
//		p[i] = new int[col];
//	}
//}


template<class T>
void createArray(T**& p, int row, int col)
{
	p = new T * [row];
	for (size_t i = 0; i < row; i++)
	{
		p[i] = new T[col];
	}
}

int*** createMatrix(int* arr)
{
	int size = _msize(arr) / sizeof(int);
	int count = 0;
	for (size_t i = 2; i < size; i++)
	{
		if (size % i == 0)
		{
			count++;
		}
	}
	int*** m = new int** [count];
	int k = 0;
	for (size_t i = 2; i < size; i++)
	{
		if (size % i == 0)
		{
			int row = i;
			int col = size / i;
			createArray(m[k], row, col);
			for (size_t j = 0; j < size; j++)
			{
				m[k][j / col][j % col] = arr[j];
			}
			k++;
		}
	}
	return m;
}

void print(int*** arr)
{
	int count = _msize(arr) / sizeof(int**);
	for (size_t k = 0; k < count; k++)
	{
		int row = _msize(arr[k]) / sizeof(int*);
		int col = _msize(arr[k][0]) / sizeof(int);
		printArray2(arr[k], row, col);
		cout << endl;
	}
}

int** dobytokMatrix(int** a, int** b, int** c, int row1, int col1, int row2, int col2)
{
	for (size_t i = 0; i < row1; i++)
	{
		for (size_t j = 0; j < col2; j++)
		{
			c[i][j] = a[i][j] * b[j][i];
		}
	}
	return c;
}

int** multiMatrix(int** a, int** b)
{
	int r1 = _msize(a) / sizeof(int*);
	int c1 = _msize(a[0]) / sizeof(int);
	int r2 = _msize(a) / sizeof(int*);
	int c2 = _msize(a[0]) / sizeof(int);

	int** m = nullptr;
	createArray(m, r1, c2);
	for (size_t i = 0; i < r1; i++)
	{
		for (size_t j = 0; j < c2; j++)
		{
			m[i][j] = a[i][j] * b[j][i];
		}
	}
	return m;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);



	int row1, row2, col1, col2;
	cout << "1: ";
	cin >> row1 >> col1;
	cout << endl;
	int** a = nullptr;
	createArray(a, row1, col1);
	setArray(a, row1, col1);
	printArray2(a, row1, col1);


	cout << endl;
	cout << "2: ";
	cin >> row2 >> col2;
	cout << endl;
	int** b = nullptr;
	createArray(b, row2, col2);
	setArray(b, row2, col2);
	printArray2(b, row2, col2);

	/*cout << endl;
	int** c = nullptr;
	createArray(c, row1, col2);*/


	/*int n;
	cin >> n;
	int* p = new int[n];
	setArray(p, n);
	printArray(p, n);
	int*** arr = createMatrix(p);
	print(arr);*/



	/*double** a;
	a = new double*;
	*a = new double(5);
	cout << **a << endl;*/
}