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
#include"ForwardList.h"


template<class T>
void printArray(Array<T> a)
{
	a.printArray();
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);


	// Конструктор initializer_list
	ForwardList<int> l1 = { 1, 2, 3 };
	cout << "Initial list: ";
	l1.print();

	// push_front
	l1.push_front(0);
	cout << "push_front(0): ";
	l1.print();

	// push_back
	l1.push_back(4);
	cout << "push_back(4): ";
	l1.print();

	// insert
	l1.insert(10, 2);
	cout << "insert(10, 2): ";
	l1.print();

	// pop_front
	l1.pop_front();
	cout << "pop_front(): ";
	l1.print();

	// pop_back
	l1.pop_back();
	cout << "pop_back(): ";
	l1.print();

	// remove
	l1.remove(1);
	cout << "remove(1): ";
	l1.print();

	// front, back, at, []
	cout << "front(): " << l1.front() << endl;
	cout << "back(): " << l1.back() << endl;
	cout << "at(1): " << l1.at(1) << endl;
	cout << "operator[0]: " << l1[0] << endl;

	// getSize
	cout << "getSize(): " << l1.getSize() << endl;

	// Конструктор копіювання
	ForwardList<int> l2 = l1;
	cout << "Copy constructor: ";
	l2.print();

	// Оператор присвоєння
	ForwardList<int> l3;
	l3 = l1;
	cout << "operator=: ";
	l3.print();

	// Оператор +
	ForwardList<int> l4 = l1 + l2;
	cout << "operator+: ";
	l4.print();

	// Оператор +=
	l1 += l2;
	cout << "operator+=: ";
	l1.print();

	// firstIndex, lastIndex, count
	ForwardList<int> l5 = { 1, 2, 3, 2, 4, 2 };

	cout << "Search list: ";
	l5.print();

	cout << "firstIndex(2): " << l5.firstIndex(2) << endl;
	cout << "lastIndex(2): " << l5.lastIndex(2) << endl;
	cout << "count(2): " << l5.count(2) << endl;

	// count_if
	cout << "count_if(even): "
		<< l5.count_if(ForwardList<int>::predicate) << endl;

	// clear
	l5.clear();
	cout << "After clear(): ";
	l5.print();
	cout << "Size after clear: " << l5.getSize() << endl;

	// Робота з порожнім списком
	ForwardList<int> empty;
	empty.push_back(5);
	cout << "Empty + push_back(5): ";
	empty.print();

	empty.pop_back();
	cout << "After pop_back(): ";
	empty.print();

	// Самододавання
	ForwardList<int> l6 = { 1, 2, 3 };
	l6 += l6;
	cout << "Self +=: ";
	l6.print();









	//PriorityQueue<int, int> pq;
	//pq.enqueue(10, 1);
	//pq.enqueue(20, 3);
	//pq.enqueue(30, 2);
	//pq.enqueue(40, 1);
	//pq.enqueue(60, 3);
	//pq.print();

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