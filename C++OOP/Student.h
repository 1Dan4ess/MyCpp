#pragma once
#include<iostream>
using namespace std;

class Student
{
	char* name;
	int age;
	int* marks;
	int sizeMarks = 0;

public:

	Student()
	{
		cout << "Default constructor called" << endl;
		setName("None");
		setAge(0);
	}
	Student(const char* n, int a)
	{
		cout << "Parameterized constructor called" << endl;
		setName(n);
		setAge(a);
	}

	void setName(const char* n)
	{
		if (n == nullptr)
		{
			cout << "Error" << endl;
		}
		else
		{
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		}
	}

	void setAge(int a)
	{
		if (a < 0 and a > 100)
		{
			age = 0;
		}
		else
		{
			age = a;
		}
	}

	void setMarks()
	{
		int m;
		cin >> m;
		setMarks(m);
	}

	void setMarks(int m)
	{
		int* newMarks = new int[sizeMarks + 1];
		for (size_t i = 0; i < sizeMarks; i++)
		{
			newMarks[i] = marks[i];
		}
		newMarks[sizeMarks] = m;
		delete[] marks;
		marks = newMarks;
		sizeMarks += 1;
	}

	char* getName()
	{
		return name;	
	}
	int getAge()
	{
		return age;
	}
	int* getMarks()
	{
		return marks;
	}

	void displayinfo()
	{
		cout << name << " - " << age << endl;
		cout << endl;
	}
};