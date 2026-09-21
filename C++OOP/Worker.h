#pragma once
#include "String.h"

class Worker
{
	String name;
	String rating;
	int date;
	double salary;

public:

	Worker(String name, String rating, int date, double salary)
	{
		this->name = name;
		this->rating = rating;
		this->date = date;
		this->salary = salary;
	}

	void menu()
	{
		cout << "1 - dateCheck\n2 - salaryCheck\n3 - ratingCheck" << endl;
		int choice;
		cout << "Дія: ";
		cin >> choice;

		switch (choice)
		{
			case(1): Worker* datecheck(); break;
			case(2): Worker* salarycheck(); break;
			case(3): Worker* ratingcheck(); break;
		}
	}

	Worker* dateCheck(int date);
	Worker* salaryCheck(double salary);
	Worker* ratingCheck(String rating);
	void display(Worker*, int size);
};

Worker* Worker::dateCheck(int obj)
{
	int date;
	cin >> date;

	cout << "Copy constructor" << endl;
	name = new char[strlen(obj.name) + 1];
	strcpy(name, obj.name);
	marks = new int[sizeMarks];
	for (size_t i = 0; i < sizeMarks; i++)
	{
		marks[i] = obj.marks[i];
	}
}
