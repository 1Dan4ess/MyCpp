#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
#include<fstream>
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

//template<class T>
//void printArray(T a, int size)
//{
//	for (size_t j = 0; j < size; j++)
//	{
//		cout << a[j] << " ";
//	}
//	cout << endl;
//}

template<class T>
void addValueArray(T*& arr, int& size, T value)
{
	T* temp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = value;
	delete[] arr;
	size++;
	arr = temp;
}

struct Point
{
	char name;
	int x;
	int y;

	void print()
	{
		cout << name << "(" << x << ", " << y << ")" << endl;
	}

};

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	//ofstream out("points.txt");
	//Point p[5];
	//for (size_t i = 0; i < 5; i++)
	//{
	//	p[i].x = rand() % 10;
	//	p[i].y = rand() % 10;
	//	p[i].name = 'A' + i;
	//	p[i].print();
	//	out << p[i].name << " " << p[i].x << " " << p[i].y << endl;
	//}

	//Point* arr = nullptr;
	//int size = 0;
	//ifstream in("points.txt");
	//Point a;
	//while (in >> a.name >> a.x >> a.y)
	//{
	//	addValueArray(arr, size, a);
	//}
	//printArray(arr, size);

	//int arr[10];
	//ifstream in("file.txt");
	//for (size_t i = 0; i < 10; i++)
	//{
	//	in >> arr[i];
	//}
	//printArray(arr, 10);

	//int row, col;
	//cin >> row >> col;
	//cout << endl;
	//int** p = nullptr;
	//createArray(p, row, col);
	//setArray(p, row, col);
	//ofstream fout;
	//fout.open("file1.txt");
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		fout << p[i][j] << " ";
	//	}
	//	fout << endl;
	//}
	//fout.close();
	//printArray(p, row, col);
	//cout << endl;
	//ifstream fin;
	//fin.open("file1.txt");
	//char buffer[80];
	//if (fin.is_open())
	//{
	//	for (size_t i = 0; i < row; i++)
	//	{
	//		fin.getline(buffer, 80);
	//		cout << buffer << endl;
	//	}
	//}
	//fin.close();


	//ofstream fout;
	//fout.open("file1.txt");
	//fout << "Hello C++" << endl;
	//fout.close();

	//ifstream fin;
	//fin.open("file1.txt");
	//char buffer[80];
	//if (fin.is_open())
	//{
	//	//fin >> buffer;
	//	fin.getline(buffer, 80);
	//	cout << buffer << endl;
	//}
	//else
	//{
	//	cout << "File not found" << endl;
	//}
	//fin.close();

}