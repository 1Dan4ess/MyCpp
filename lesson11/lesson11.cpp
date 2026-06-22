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

int* find(int* a, int size)
{
	int* res = new int[2] {0, 1};
	for (size_t i = 0; i < size; i++)
	{
		res[0] += a[i];
		res[1] *= a[i];
	}

	return res;
}

int* findCopy(int* a, int* b, int m, int n) 
{
	for (int i = 0; i <= m - n; i++) 
	{
		int count = 0;
		for (int j = 0; j < n; j++) 
		{
			if (a[i + j] == b[j])
			{
				count++;
			}
		}
		if (count == n)
		{
			return &a[i];
		}
	}
	return nullptr;
}


int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int m, n;
	cout << "Розмір:" << endl;
	cin >> m;
	int* a = new int[m];
	cout<<"Масив:" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	cout << endl;
	cout << "Розмір:" << endl;
	cin >> n;
	int* b = new int[n];
	cout << "Масив:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	




	//int b = 5;
	//const int& rb = b;
	//rb = 99;
	//int a = 5;
	//const int* pa = &a;
	//*pa = 99;



	//int m, n;
	//cout << "Розмір:" << endl;
	//cin >> m;
	//int* a = new int[m];
	//cout<<"Масив:" << endl;
	//for (int i = 0; i < m; i++)
	//{
	//	cin >> a[i];
	//}
	//cout << endl;
	//cout << "Розмір:" << endl;
	//cin >> n;
	//int* b = new int[n];
	//cout << "Масив:" << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> b[i];
	//}
	//cout << endl;
	//int* res = findCopy(a, b, m ,n);
	//cout << res << endl;
	//cout << *res << endl;

	//int size;
	//cin >> size;
	//int* a = new int[size];
	//setArray(a, size);
	//printArray(a, size);
	//int* res = find(a, size);
	//cout << res[0];
}