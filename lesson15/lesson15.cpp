#include<iostream>
#include<Windows.h>
#include <iomanip>
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

void printArray(int a[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void printArray2(int** arr, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
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

void print(int*** arr)
{
	int count = _msize(arr) / sizeof(int**);
	for (size_t k = 0; k < count; k++)
	{
		int row = _msize(arr[k]) / sizeof(int*);
		int col = _msize(arr[k][0]) / sizeof(int);
		printArray2(arr[k], row, col);
		cout << endl;
	}
}

int lenStr(const char st[])
{
	int count = 0;
	int i = 0;
	while (st[count] != '\0')
	{
		count += 1;
	}
	return count;
}

//char* delElement(const char buffer[], char n)
//{
//	int len = strlen(buffer);
//	int len2 = len;
//	for (size_t i = 0; i < len; i++)
//	{
//		if (buffer[i] == n)
//		{
//			len2--;
//		}
//	}
//	char* str= new char[len2];
//	for (size_t i = 0; i < len2; i++)
//	{
//		if (buffer[i] != n)
//		{
//			str[i] = buffer[i];
//		}
//	}
//	return str;
//}

bool isPalindrome(const char* st)
{
	int size = strlen(st);
	for (size_t i = 0; i < size; i++)
	{
		if (st[i] != st[size - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int word(char* st1)
{
	int len = strlen(st1);
	int count = 1;
	for (size_t i = 0; i < len; i++)
	{
		if (!isspace(st1[i]) and isspace(st1[i+1] == '\0' or !isspace(st1[i+1])))
		{
			count += 1;
		}
	}
	return count;
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	char st1[80], st2[80];
	cout << "1:"; cin.getline(st1, 80);
	//cout << "2:"; cin.getline(st2, 80);
	cout << "1:" << st1 << endl;
	//cout << "2:" << st2 << endl;
	cout << word(st1) << endl;






	//strcpy(st1, st2);
	//strncpy_s(st1, 80, st2, 3);
	//strcat(st1, st2);
	//strncat(st1, st2, 2);
	
	//cout << strcmp(st1, st2) << endl;
	//cout << strncmp(st1, st2, 3) << endl;
	//cout << _stricmp(st1, st2) << endl;
	//cout << _strincmp(st1, st2, n) << endl;
	
	//char* t = strchr(st1, 'r');
	//char* t = strrchr(st1, 'r');
	//char* t = strstr(st1, "we");
	//if (t != nullptr)
	//{
	//	cout << t << endl;
	//}

	//_strset(st1, '*');
	
	//int a = atoi(st1);
	//long a = atol(st1);
	//double d = atof(st1);
	//cout << d << endl;
	
	//_itoa(255, st1, 2);

	//cout << strupr(st1) << endl;;
	//cout << strlwr(st1) << endl;

	//cout << isalnum('!') << endl;
	//cout << isalpha('!') << endl;
	//cout << isdigit('!') << endl;
	//cout << isspace('!') << endl;
	//cout << ispunct('!') << endl;
	//cout << isprint('!') << endl;
	//cout << isupper('!') << endl;
	//cout << islower('!') << endl;
	//cout << "1:" << st1 << endl;
	//cout << "2:" << st2 << endl;





	//char buffer[1024];
	//cin.getline(buffer, 1024);
	//char n;
	//cin >> n;
	//cout << delElement(buffer, n) << endl;



	//char st[] = "Goodbye";
	//cout << st << endl;
	//cout << lenStr(st) << endl;
	//cout << strlen(st) << endl;



	//char st[] = "Hello"; //{ 'H', 'e', 'l', 'l', 'o' };
	//int a[5];
	//cout << a << endl;
	//cout << st << endl;

}