#include<iostream>
#include<Windows.h>
#include <iomanip>
using namespace std;

void setArray(int a[], int size, int min = 1, int max = 10)
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

float funcMax(int* arr, int size) 
{
    int maxx = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > maxx)
		{
			maxx = arr[i];
		}
	}
	return maxx;
}

float funcMin(int* arr, int size) 
{
    int minn = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < minn)
		{
			minn = arr[i];
		}
	}
	return minn;
}

float funcSer(int* arr, int size) 
{
	float summ = 0;
    for (int i = 0; i < size; i++) 
	{
		summ += arr[i];
	}
	return summ / size;
}


float action(int* a, int size1, int* b, int size2, float(*actions)(int*, int), int n)
{
	float res1 = actions(a, size1);
	float res2 = actions(b, size2);

	if (n == 0) 
	{
		if (res1 > res2)
		{
			return res1;
		}
		else
		{
			return res2;
		}
	}
	else if (n == 1) 
	{
		if (res1 < res2)
		{
			return res1;
		}
		else
		{
			return res2;
		}
	}
	else 
	{
		return (res1 + res2) / 2.0;
	}
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int size1, size2;
	cout << "Розмір масиву a: "; cin >> size1;
	cout << "Розмір масиву b: "; cin >> size2;

	int* a = new int[size1];
	int* b = new int[size2];
	setArray(a, size1);
	setArray(b, size2);
	cout << "a: ";
	printArray(a, size1);
	cout << "b: ";
	printArray(b, size2);

	cout <<"Дії: 0 = Макс, 1 = Мін, 2 = Сер" << endl;
	int n; 
	cin >> n;
	float(*actions[])(int*, int) = {funcMax, funcMin, funcSer};
	cout << "Результат: " << action(a, size1, b, size2, actions[n], n) << endl;
}