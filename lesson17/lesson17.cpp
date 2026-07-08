#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

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

struct engine
{
	int cilinder = 4;
	void start()
	{
		cout << "Engine started" << endl;
	}
	void stop()
	{
		cout << "Engine stopped" << endl;
	}
};

struct car
{
	engine engine;
	void move()
	{
		engine.start();
		cout << "Car moved" << endl;
		engine.stop();
	}
	void sound()
	{
		cout << "Car sound" << endl;
	}
};

struct Abonent
{
	char* name;
	char* phone;
	void input()
	{
		cout << "Enter name  : ";
		char buffer[80];
		cin.getline(buffer, 80);
		name = new char[strlen(buffer) + 1];
		strcpy(name, buffer);
		cout << "Enter number: ";
		cin.getline(buffer, 80);
		phone = new char[strlen(buffer) + 1];
		strcpy(phone, buffer);
	}
	void print()
	{
		cout << setw(15)
	}
};

struct PhoneBook
{
	Abonent* abonents = nullptr;
	int size = 0;
	void menu()
	{
		while (true)
		{
			system("cls");
			cout << "PhoneBook" << endl;
			cout << "---------------------" << endl;
			cout << "1. Add contact\n2. Remove contact\n3. Print contacts\n4. Find contact\n5. Exit"<<endl;
			int choice;
			cin >> choice;
			cin.ignore();
			switch (choice)
			{
			case 1: addContact(); break;
			case 2: removeContact(); break;
			case 3: printContacts(); break;
			case 4: findContact(); break;
			case 5: exit(0);
			default: break;
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
	void removeContact()
	{

	}
	void printContacts()
	{
		system("cls");
		cout << "PhoneBook List" << endl;
		cout << "---------------------" << endl;
		cout << "   №  Name           Phone Number" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << setw(4) << right << i + 1 << ". ";
			abonents[i].print();
		}
		system("pause");
	}
	void findContact()
	{

	}
};

//struct person
//{
//	char* name;
//	int* phone;
//};
//
//struct book
//{
//	int contacts = 3;
//	person* abonent = new person[contacts];
//	void innit()
//	{
//		for (size_t i = 0; i < contacts; i++)
//		{
//			cout << "Ім'я: ";
//			char buffer[80];
//			cin.getline(buffer, 80);
//			int len = strlen(buffer);
//			char* st = new char [len];
//			strncpy_s(buffer, 80, st,len);
//			abonent[0].name = new char[] {*st};
//			cout << "Номер: ";
//			int n;
//			cin >> n;
//			abonent[0].phone = new int[] {n};
//		}
//	}
//};

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);


	PhoneBook book;
	book.menu();


	//car car;
	//car.move();
	//car.sound();
}