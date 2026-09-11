#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
#include<fstream>
#include <cstring>
using namespace std;
#include"Student.h"

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	Student s1("Vasya", 30);
	//Student s2;

	/*s1.setName("John");
	s1.setAge(20);*/
	/*s1.displayinfo();
	s2.displayinfo();*/

	while (true)
	{
		int buf;
		cin >> buf;
		s1.displayinfo();
		system("pause");
	}

	return 0;
}