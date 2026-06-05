#pragma once
#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include <iomanip>
using namespace std;


enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}


void starLine(int size = 10, char symbol = '*')
{
	for (size_t i = 0; i < size; i++)
	{
		cout << symbol;
	}
	cout << endl;
}



float ser(int first, int second, int third)
{
	float summ = (first + second + third) / 3.f;
	return(summ);
}


void setArray(int a[], int size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		a[i] = rand() % (max - min + 1) + min;
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

void sortArray(int a[], int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}
int findArray(int a[], int size, int min, int max, int n)
{
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] == n)
		{
			return i;
		}
	}
	return -1;
}