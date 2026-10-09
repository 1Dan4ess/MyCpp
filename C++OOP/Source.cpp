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
#include"Fraction.h"
#include"Var.h"
#include"Stack.h"
#include"Calc.h"
#include"Queue.h"
#include"PriorityQueue.h"


template<class T>
void printArray(Array<T> a)
{
	a.printArray();
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);


	PriorityQueue<int, int> pq;
	pq.enqueue(10, 1);
	pq.enqueue(20, 3);
	pq.enqueue(30, 2);
	pq.enqueue(40, 1);
	pq.enqueue(60, 3);
	pq.print();

	//Queue<int> q = { 1, 2, 3, 4 };
	//q.print();
	//q.ring();
	//q.print();

	





	//Calc c("4+3^2+4/2");
	//cout << c.getResult() << endl;

	//Stack<int, 5> s;
	//s.push(10);
	//s.push(15);
	//s.push(5);
	//s.push(20);
	//s.push(25);
	//s.print();







	//Array<Fraction> a;
	//a.resize(10);
	//a.setRandom();
	//printArray(a);







	//Fraction f1(3, 5);
	//Fraction f2(4, 5);
	//Fraction f3 = f1 + f2;
	//cout << f3 << endl;







	//Array a;
	//a.resize(10);
	//a.setRandom();
	//a.printArray();
	//cout << endl;
	//printArray(a);
	//cout << endl;
	//a.printArray();
	//Array b;
	//b.resize(10);

	//Student s1(1, "Vasya", 30);
	//s1.displayinfo();



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

	//char* buff = new char[100];
	//cin.getline(buff, 100);
	//String string(buff);
	//string.write();
	//string.show();

	return 0;
}