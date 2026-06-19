#include<iostream>
#include<Windows.h>
#include <iomanip>
using namespace std;

void setArray(int a[], int size, int min = 0, int max = 100)
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

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	//int a = 5;
	//int* p = &a;
	//cout << p << endl;
	//cout << *p << endl;
	//*p = 999;
	//cout << a << endl;
	//float f = 3.53;
	//float* p1 = &f;

	//int arr[4] = { 1, 2, 3, 4 };
	//for (int* i = arr; i != arr+4; i++)
	//{
	//	cout << *i;
	//}

	int size;
	cin >> size;
	int* p = new int[size];
	setArray(p, size);
	printArray(p, size);
	delete[] p;

	//int* temp = new int[size + 1];
	//for (size_t i = 0; i < size; i++)
	//{
	//	temp[i] = p[i];
	//}
	//temp[size] = 999;
	//delete[] p;
	//size++;
	//printArray(p, size + 1);
	//delete[] p;


}