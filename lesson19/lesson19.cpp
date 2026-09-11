#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
#include<fstream>
#include <cstring>
using namespace std;

#define SIZE 100
#define PRINT cout

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

struct Human
{
	char* name;
	int age;
};

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	
	//int arr[] = {123, 2334, 33432, 486860, 8997789};
	//ofstream out("file.bin", ios::binary);
	//for (size_t i = 0; i < 5; i++)
	//{
	//	out.write((char*)&arr[i], sizeof(int));
	//}
	//int a = 454535;
	//ofstream out("file2.bin", ios::binary);
	//out.write((char*)& a, 4);
	//out.write("Hello C++", 10);


	//Human h = { new char[] {"Vasya"}, 16 };
	//ofstream out("h.bin", ios::binary);
	//out.write((char*)&h, sizeof(Human));
	//int len = strlen(h.name) + 1;
	//out.write((char*)&len, sizeof(int));
	//out.write(h.name, len);
	//Human h1;
	//ifstream in("h.bin", ios::binary);
	//in.read((char*)&h1, sizeof(Human));
	//int len;
	//in.read((char*)&len, sizeof(int));
	//h1.name = new char[len];
	//in.read(h1.name, len);
	//cout << h1.name << endl;
	//cout << h1.age << endl;

	//ifstream in("points.bin", ios::binary);
	//int n;
	//cin >> n;
	//in.seekg((n - 1) * sizeof(Point));
	//Point a;
	//in.read((char*)&a, sizeof(Point));
	//a.print();

	int arr[SIZE];
	PRINT << 100 << endl;
}