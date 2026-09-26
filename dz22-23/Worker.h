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

	void showAll()
	{
		for (size_t i = 0; i < size; i++)
		{
			workers[i].show();
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



Worker* Worker::dateCheck(int date)
{
	int size2 = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (workers[i].date > date)
		{
			size2 += 1;
		}
	}
	Worker* workers2 = new Worker[size];
	int ind = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (workers[i].date > date)
		{
			workers2[ind] = workers[i];
			ind += 1;
		}
	}
	for (size_t i = 0; i < size2; i++)
	{
		workers2[i].show();
	}
	return workers2;
}



Worker* Worker::salaryCheck(double salary)
{
	int size2 = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (workers[i].salary > salary)
		{
			size2 += 1;
		}
	}
	Worker* workers2 = new Worker[size];
	int ind = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (workers[i].salary > salary)
		{
			workers2[ind] = workers[i];
			ind += 1;
		}
	}
	for (size_t i = 0; i < size2; i++)
	{
		workers2[i].show();
	}
	return workers2;
}



Worker* Worker::ratingCheck(String rating)
{
	int size2 = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (workers[i].rating == rating)
		{
			size2 += 1;
		}
	}
	Worker* workers2 = new Worker[size];
	int ind = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (workers[i].rating == rating)
		{
			workers2[ind] = workers[i];
			ind += 1;
		}
	}
	for (size_t i = 0; i < size2; i++)
	{
		workers2[i].show();
	}
	return workers2;
}