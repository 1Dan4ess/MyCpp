#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include <iomanip>
using namespace std;


int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);




	//1
	//const int size = 3;
	//int a[size];
	//int b[size];
	//int x, task;
	//cout << "Мобільні телефони:" << endl;
	//for (size_t j = 0; j < size; j++)
	//{
	//	cin >> x;
	//	a[j] = x;
	//	x = 0;
	//}
	//cout << "Домашні телефони:" << endl;
	//for (size_t j = 0; j < size; j++)
	//{
	//	cin >> x;
	//	b[j] = x;
	//	x = 0;
	//}

	//cout << "Відсортувати за номерами мобільних - 1" << endl;
	//cout << "Відсортувати за домашніми номерами телефонів - 2" << endl;
	//cout << "Вивести список користувачів - 3" << endl;
	//cout << "Вихід - 4" << endl;
	//do
	//{
	//	cout << endl;
	//	cin >> task;
	//	switch (task)
	//	{
	//	case(1): 
	//		for (size_t i = 0; i < size - 1; i++)
	//		{
	//			for (size_t j = 0; j < size - 1 - i; j++)
	//			{
	//				if (a[j] < a[j+1])
	//				{
	//					swap(a[j], a[j + 1]);
	//				}
	//			}
	//		}; break;
	//	case(2): 
	//		for (size_t i = 0; i < size-1 ; i++)
	//		{
	//			for (size_t j = 0; j < size-1 - i; j++)
	//			{
	//				if (b[j] < b[j + 1])
	//				{
	//					swap(b[j], b[j + 1]);
	//				}
	//			}
	//		}; break;
	//	case(3): 
	//		cout << "Мобільні телефони:" << endl;
	//		for (size_t i = 0; i < size; i++)
	//		{
	//			cout << a[i] << endl;
	//		}
	//		cout << "Домашні телефони:" << endl;
	//		for (size_t i = 0; i < size; i++)
	//		{
	//		cout << b[i] << endl;
	//		}; break;
	//	case(4): cout << "Вихід" << endl; break;
	//	default: cout << "Помилка" << endl; break;
	//	}
	//} while (task != 4);




	//2
	//const int size = 10;
	//int a[size];
	//bool flag = false;
	//int min = 0, max = 10;
	//for (size_t i = 0; i < size; i++)
	//{
	//	a[i] = rand() % (max - min + 1) + min;
	//}
	//for (size_t i = 0; i < size - 1; i++)
	//{
	//	for (size_t j = 0; j < size -i -1; j++)
	//	{
	//		if (a[j] > a[j+1])
	//		{
	//			swap(a[j], a[j + 1]);
	//			flag = true;
	//		}
	//		
	//	}
	//	if (flag == false)
	//	{
	//		break;
	//	}
	//}
	//for (size_t i = 0; i < size; i++)
	//{
	//	cout << a[i] << " ";
	//}




	
}