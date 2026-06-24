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

void starLine(int size = 10, char symbol = '*')
{
	for (size_t i = 0; i < size; i++)
	{
		cout << symbol;
	}
	cout << endl;
}

void hello()
{
	cout << "Hello" << endl;
}

void bye()
{
	cout << "Bye" << endl;
}


template<class T>
bool asc(const T& a, const T& b)
{
	return a > b;
}
template<class T>
bool desc(const T& a, const T& b)
{
	return a < b;
}

void transform(int& a)
{
	a *= 10;
}

template<class T>
void forEach(T* p, int size, void(*transform)(T&))
{
	for (size_t i = 0; i < size; i++)
	{
		transform(p[i]);
	}
}

template<class T>
void sortArray(T a[], int size, bool(*method)(const T&, const T&) = asc)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (method(a[j], a[j + 1]))
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void kopatel1()
{
	cout << "Копає один робітник з лопатою" << endl;
}
void kopatel3()
{
	cout << "Копають три робітника з лопатою" << endl;
}
void exkavator()
{
	cout << "Копає екскаватор, робітники відпочивають" << endl;
}

void(*prorab(int len))()
{
	if (len <= 100)
	{
		return kopatel1;
	}
	else if (len <= 500)
	{
		return kopatel3;
	}
	else if (len > 500)
	{
		return exkavator;
	}
}

//void (*selectWeapon(int* bullets))(int*)
//{
//	void(*weapons[])(int*) = { pistol, gun, snipe };
//}
//
//void pistol(int* bullets)
//{
//	cout << "->" << endl;
//	bullets[0]--;
//}
//void gun(int* bullets)
//{
//	cout << "-> -> ->" << endl;
//	bullets[1] -= 5;
//}
//void snipe(int* bullets)
//{
//	cout << "---->" << endl;
//	bullets[2]--;
//}


int summ(int a, int b)
{
	return a + b;
}
int riz(int a, int b)
{
	return a - b;
}
int mnoj(int a, int b)
{
	return a * b;
}
int del(int a, int b)
{
	return a / b;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		int a, b, n;
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
		cout << "1 = +, 2 = -, 3 = *, 4 = /" << endl;
		cout << "Action(1-4): ";
		cin >> n;
		int(*actions[])(int, int) = { summ, riz, mnoj, del };
		cout << "Res: ";
		cout << actions[n - 1](a, b) << endl;
		cout << endl;
	}



	/*int bullets[] = {50, 50, 50};
	void(*shoot)(int*) = selectWeapon(bullets);
	shoot(bullets);*/


	/*int len = 500;
	void(*director)() = prorab(len);
	director();*/




	/*int size = 10;
	int* p = new int[size];
	setArray(p, size);
	printArray(p, size);
	sortArray(p, size, desc);
	printArray(p, size);*/

	/*int size = 10;
	int* p = new int[size];
	setArray(p, size);
	printArray(p, size);
	forEach(p, size, transform);
	printArray(p, size);*/

	/*void(*message[])() = { hello, bye };
	for (size_t i = 0; i < 2; i++)
	{
		message[i]();
	}*/



	//void(*star)(int, char) = starLine;



	/*void(*message)() = hello;
	message();
	message = bye;
	message();*/
	//type (*starLine) (size, symbol)
}