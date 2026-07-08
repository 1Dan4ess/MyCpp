#include<iostream>
#include<Windows.h>
#include <iomanip>
using namespace std;

void printArray(char** a, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

bool compareString(char* const& s1, char* const& s2)
{
	return strcmp(s1, s2) > 0;
}

template<class T>
bool asc(const char& a, const char& b)
{
	return a > b;
}

template<class T>
bool desc(const T& a, const T& b)
{
	return a < b;
}

template<class T>
void sortArray(T* a, int size, bool(*method)(const T&, const T&) = desc)
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

//char* deleteWord(const char* st, const char* word)
//{
//	const char* p;
//	int lenWord = strlen(word);
//	char* newStr = new char[strlen(st) + 1];
//	newStr[0] = '\0';
//	while ((p = strstr(st, word)) != nullptr)
//	{
//		strncat(newStr, st, p - st);
//		st = p + lenWord;
//	}
//	strcat(newStr, st);
//	return newStr;
//}
//
//char* replaceWord(const char* st, const char* _old, const char* _new)
//{
//	const char* p;
//	int lenWord = strlen(_old);
//	char* newStr = new char[strlen(st) + 1];
//	newStr[0] = '\0';
//	while ((p = strstr(st, _old)) != nullptr)
//	{
//		strncat(newStr, st, p - st);
//		strcat(newStr, _new);
//		st = p + lenWord;
//	}
//	strcat(newStr, st);
//	char* temp = new char[strlen(newStr) + 1];
//	strcpy(temp, newStr);
//	delete newStr;
//	return newStr;
//}





struct Point
{
	char name;
	int x;
	int y;
};

void printPoint(Point p)
{
	cout << p.name << "(" << p.x << ", " << p.y << ")" << endl;
}

struct Date
{
	int day;
	int month;
	int year;
};

void printDate(Date d)
{
	if (d.day < 10)
	{
		cout << "0";
		cout << d.day << ".";
	}
	if (d.month < 10)
	{
		cout << "0";
		cout << d.month << ".";
	}
	cout << d.year << endl;
}

struct Human
{
	char* name;
	Date bd;
};



int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	
	Human h = { new char[] {"Danya"}, {10, 2, 2000} };
	h.bd.day = 10;




	//Date d;
	//cin >> d.day;
	//cin >> d.month;
	//cin >> d.year;
	//printDate(d);


	//Point p;
	//p.name = 'A';
	//p.x = 10;
	//p.y = 5;

	//Point p1 = { 'B', 13, 5 };
	//printPoint(p);




	//cout << "Python, C++, C, C++, Java, C" << endl;
	//cout << deleteWord("Python, C++, C, C++, Java, C", "C++") << endl;
	//cout << replaceWord("Python, C++, C, C++, Java, C", "C++", "---") << endl;



	//int size = 5;
	//char** names = new char* [size];
	//char buffer[1024];
	//for (size_t i = 0; i < size; i++)
	//{
	//	cin.getline(buffer, 1024);
	//	int len = strlen(buffer);
	//	names[i] = new char[len + 1];
	//	strcpy_s(names[i], len+1, buffer);
	//}
	//cout << endl;
	//printArray(names, size);
	//sortArray(names, size, compareString);
	//printArray(names, size);
}