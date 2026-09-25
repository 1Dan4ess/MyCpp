#pragma once
#include "String.h"

class Worker
{
	String name;
	String rating;
	int date;
	double salary;
	Worker* workers = nullptr;
	int size = 0;
public:

	Worker(const Worker& obj)
	{
		date = obj.date;
		salary = obj.salary;
		size = obj.size;
		name = obj.name;
		rating = obj.rating;

		workers = new Worker[size];
		for (size_t i = 0; i < size; i++)
		{
			workers[i] = obj.workers[i];
		}
	}

	Worker()
	{
		name = "None";
		rating = "None";
		date = 0;
		salary = 0;
		size = 0;
		workers = nullptr;
	}

	Worker(String name, String rating, int date, double salary)
	{
		this->name = name;
		this->rating = rating;
		this->date = date;
		this->salary = salary;
	}

	void show() 
	{
		name.print();
		rating.print();
		cout << date << endl;
		cout << salary << endl;
		cout << "----------------------------" << endl;
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

	void addWork(const Worker& obj)
	{
		Worker* newwork = new Worker[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			newwork[i] = workers[i];
		}
		newwork[size] = obj;
		delete[] workers;
		workers = newwork;
		size += 1;
	}

	Worker* dateCheck(int date);
	Worker* salaryCheck(double salary);
	Worker* ratingCheck(String rating);
};
