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
	p = new T* [row];
	for (size_t i = 0; i < row; i++)
	{
		p[i] = new T[col];
	}
}

template<class T>
void printArray(T** a, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T>
void addrow(T**& a, int& row, int col, T* newrow = nullptr)
{
	T** temp = new T * [row + 1];
	for (size_t i = 0; i < row; i++)
	{
		temp[i] = a[i];
	}

	temp[row] = new T[col];
	for (size_t i = 0; i < col; i++)
	{
		temp[row][i] = (newrow != nullptr) ? newrow[i] : 0;
	}
	delete[] a;
	row++;
	a = temp;
}

template<class T>
void deleteArray(T**& a, int& row)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	a = nullptr;
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int row, col;
	cin >> row >> col;
	int** p = nullptr;
	createArray(p, row, col);
	setArray(p, row, col);
	printArray(p, row, col);
	int* t = new int[col];

	addrow(p, row, col, t);
	delete[] t;
	cout << endl;
	printArray(p, row, col);
	deleteArray(p, row);



	//*(*(p + i) + j) = p[i][j];

	//int a = 5;
	//int* p1 = &a;
	//int** p2 = &p1;
	//cout << *p1 << endl;
	//cout << p1 << endl;
	//cout << p2 << endl;
	//cout << *p2 << endl;
	//cout << **p2 << endl;
}