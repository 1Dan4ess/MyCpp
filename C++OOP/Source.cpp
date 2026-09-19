#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
#include<fstream>
#include <cstring>
using namespace std;
#include"Student.h"
#include"Array.h"
#include"Time.h"
#include"String.h"

void printArray(const Array& a)
{
	a.printArray();
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);


	//cout << "Count of students: " << Student::getCount() << endl;
	//Student s1(1, "Vasya", 30);
	//cout << "Count of students: " << s1.getCount() << endl;
	//Student s2(2);
	//cout << "Count of students: " << s2.getCount() << endl;

	//cout << endl;
	//s1.setMarks();
	//s1.displayinfo();
	//cout << endl;
	//s2.setName("John");
	//s2.setAge(20);
	//s2.displayinfo();

	//while (true)
	//{
	//	s1.setMarks();
	//	s1.displayinfo();
	//	s1.displayinfo();
	//	system("pause");
	//}

	//int a = 5;
	//const int b(5);
	//const int c{ (int)5.5};



	//const Array ar;
	//printArray(ar);
	//ar.printArray();
	//rray ar;
	//ar.menu();


	//Time t(1);

	char* buff = new char[100];
	cin.getline(buff, 100);
	String string(buff);
	string.write();
	string.show();

	return 0;
}