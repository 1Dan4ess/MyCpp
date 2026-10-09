#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
#include<fstream>
#include <cstring>
using namespace std;
#include"Stack.h"
#include"Bracket.h"


int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);


	Bracket a("(b+a)*(h-4){f-3}");
	cout << a.getResult() << endl;
	cout << endl;
	Bracket b("(b+a)*(h-4]{f-3}");
	cout << b.getResult() << endl;
}