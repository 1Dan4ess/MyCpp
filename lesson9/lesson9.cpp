#include<iostream>
#include<Windows.h>
#include <iomanip>
using namespace std;


template<class T>
int findArray(T a[], int size, T n)
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

template<class T>
void printArray(T a[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

template<class T>
T maxArray(T a[], int size)
{
	T maxi = a[0];
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] > maxi)
		{
			maxi = a[i];
		}
	}
	return maxi;
}

template<class T>
int countArray(T a[], int size, T n)
{
	int count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] == n)
		{
			count += 1;
		}
	}
	return count;
}

template<class T>
T summArray(T a[], int size)
{
	T summ = a[0];
	for (size_t i = 1; i < size; i++)
	{
		summ += a[i];
	}
	return summ;
}

template<class T1, class T2, class T3>
auto Sum(T1 a, T2 b, T3 c)
{
	return a + b + c;
}

template<class T>
void setArray(T a[], int size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		a[i] = rand() % (max - min + 1) + min;
	}
}

template<class T>
void sortArray(T a[], int size)
{
	T left = a[0];
	T right= a[size-1];
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] < 0)
		{
			left = i;
			break;
		}
	}
	for (size_t i = size-1; i > 0; i--)
	{
		if (a[i] < 0)
		{
			right = i;
			break;
		}
	}
	for (size_t i = left; i < right; i++)
	{
		for (size_t j = 0; j < right - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}


int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

	const int size = 15;
	int a[size], min = -20, max = 20;
	setArray(a, size, min, max);
	printArray(a, size);
	sortArray(a, size);
	printArray(a, size);




	//cout << Sum(3, 5.5, 'a') << endl;
	//auto a = 10 + 3.5;
	//int c = 9;
	//a = 3.5;
	//decltype(a + c) b;
	



	//const int size = 10;
	//int a[size], min = 0, max = 10;
	//setArray(a, size, min, max);
	//printArray(a, size);
	//cout << summArray(a, size);




	//const int size = 20;
	//int a[size], n, min = 0, max = 10;
	//setArray(a, size, min, max);
	//printArray(a, size);
	//cin >> n;
	//cout << countArray(a, size, n);




	//const int size = 10;
	//int a[size], min = 0, max = 90;
	//setArray(a, size, min, max);
	//printArray(a, size);
	//cout << maxArray(a, size);




	//const int size = 10;
	//int a[size], min = 0, max = 10;
	//setArray(a, size, min, max);
	//printArray(a, size);
	//sortArray(a, size);
	//printArray(a, size);




	//const int size = 10;
	//int a[size], min = 0, max = 10;
	//int n;
	//cin >> n;
	//setArray(a, size, min, max);
	//printArray(a, size);
	//cout << findArray(a, size, n);
}