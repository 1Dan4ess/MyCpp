#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
#include<fstream>
#include <cstring>
using namespace std;
#include"Square.h"

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << Square::triangle(50.5, 2.5) << endl;
	cout << Square::triangle(10, 24, 17) << endl;
	cout << Square::triangle3(43, 11, 90) << endl;
	cout << Square::square(7.25) << endl;
	cout << Square::quadrangle(14, 21) << endl;
	cout << Square::romb(12, 13) << endl;
	cout << "Площ: " << Square::getcount() << endl;
}