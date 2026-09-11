#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
#include<fstream>
#include <cstring>
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

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	//1
	//ifstream in("dz18(1.1).txt");
	//ifstream in2("dz18(1.2).txt");
	//char buffer[100];
	//char buffer2[100];
	//if (in.is_open() and in2.is_open()) 
	//{
	//	while (in.getline(buffer, 80) and in2.getline(buffer2, 80)) 
	//	{
	//		if (strcmp(buffer, buffer2) != 0) 
	//		{
	//			cout << "1: " << buffer << endl;
	//			cout << "2: " << buffer2 << endl;
	//			cout << endl;
	//		}
	//	}
	//}
	//else
	//{
	//	cout << "Empty file" << endl;
	//}
	//in.close();
	//in2.close();


	//2
	//ofstream out("dz18(2.2).txt");
	//ifstream in("dz18(2.1).txt");
	//char buffer[100];
	//char chars;
	//int strings = 0;
	//int chars2 = 0;
	//int golos = 0;
	//int sogl = 0;
	//int numbers = 0;
	//while (in.getline(buffer, 100)) 
	//{
	//	strings += 1;
	//	for (int i = 0; buffer[i] != '\0'; i++) 
	//	{
	//		chars2 += 1;
	//		if (strchr("AEIOUYaeiouy", buffer[i])) 
	//		{
	//			golos += 1;
	//		}
	//		else if (strchr("BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz", buffer[i])) 
	//		{
	//			sogl += 1;
	//		}
	//		else if (strchr("1234567890", buffer[i]))
	//		{
	//			numbers += 1;
	//		}
	//	}
	//	chars2 += 1;
	//}
	//out << "Символи: " << chars2 - strings << endl;
	//out << "Рядки: " << strings << endl;
	//out << "Голосні: " << golos << endl;
	//out << "Приголосні: " << sogl << endl;
	//out << "Цифри: " << numbers << endl;
	//out.close();
	//in.close();
}