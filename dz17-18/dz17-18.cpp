#define _CRT_SECURE_NO_WARNINGS
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

template<class T>
void createArray(T**& p, int row, int col)
{
	p = new T * [row];
	for (size_t i = 0; i < row; i++)
	{
		p[i] = new T[col];
	}
}

template<class T>
void printArray(T** a, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T>
void transportArray(T** a, T** b, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			b[i][j] = a[j][i];
		}
	}
}

template<class T>
void addValueArray(T*& arr, int& size, T value)
{
	T* temp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = value;
	delete[] arr;
	size++;
	arr = temp;
}

struct Abonent
{
	char* name;
	char* phoneNumber;

	void input()
	{
		cout << "Enter name   : ";
		char buffer[80];
		cin.getline(buffer, 80);
		name = new char[strlen(buffer) + 1];
		strcpy(name, buffer);
		cout << "Enter number : ";
		cin.getline(buffer, 80);
		phoneNumber = new char[strlen(buffer) + 1];
		strcpy(phoneNumber, buffer);
	}

	void print()
	{
		cout << setw(15) << left << name << setw(15) << left << phoneNumber << endl;
	}
};


struct PhoneBook
{
	Abonent* abonents = nullptr;
	int size = 0;

	void init()
	{
		size = 0;
		abonents = new Abonent[0];
	}

	void menu()
	{
		init();
		while (true)
		{
			system("cls");
			cout << "PHONEBOOK" << endl;
			cout << "----------------------" << endl;
			cout << "1. Add contact\n2. Find contact\n3. Print contacts\n4. Exit" << endl;
			int choice;
			cin >> choice;
			cin.ignore();
			switch (choice)
			{
			case 1:
				addContact();
				break;
			case 2:
				findContact();
				break;
			case 3:
				printAll();
				break;
			case 4:
				exit(0);
			default:
				break;
			}
		}
	}

	void addContact()
	{
		system("cls");
		cout << "Add Contact" << endl;
		cout << "---------------------" << endl;
		Abonent ab;
		ab.input();
		addValueArray(abonents, size, ab);
		cout << "Abonent added" << endl;
		system("pause");
	}

	void printAll()
	{
		system("cls");
		cout << "List" << endl;
		cout << "--------------------------------------------" << endl;
		for (size_t i = 0; i < size; i++)
		{
			abonents[i].print();
		}
		system("pause");
	}

	void findContact()
	{
		system("cls");
		cout << "---------------------" << endl;
		cout << "Enter name or phone to search: ";
		char search[80];
		cin.getline(search, 80);

		cout << "\nResult:" << endl;
		cout << "---------------------" << endl;
		bool found = false;

		for (size_t i = 0; i < size; i++)
		{
			if (strstr(abonents[i].name, search) != nullptr or strstr(abonents[i].phoneNumber, search) != nullptr)
			{
				abonents[i].print();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "No result" << endl;
		}
		system("pause");
	}

};

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	//1

	//int row, col;
	//cin >> row >> col;
	//int** p = nullptr;
	//createArray(p, row, col);
	//setArray(p, row, col);
	//printArray(p, row, col);
	//cout << endl;
	//int** p1 = nullptr;
	//createArray(p1, col, row);
	//transportArray(p, p1, col, row);
	//printArray(p1, col, row);


	//2

	PhoneBook book;
	book.menu();
}