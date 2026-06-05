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

void starLine()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "*";
	}
	cout << endl;
}
float ser(int first, int second, int third)
{
	float summ = (first + second + third)/3.f;
	return(summ);
}


void setArray(int arr[], int size, int min = 0, int max = 9)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void printArray(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}