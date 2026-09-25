#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
#include<fstream>
#include <cstring>
using namespace std;
#include"String.h"
#include"Worker.h"

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	
    Worker work;
    work.addWork(Worker("Стас", "Прибиральник", 2025, 7120));
    work.addWork(Worker("Максим", "Програміст", 2018, 31000));
    work.addWork(Worker("Дмитро", "Дизайнер", 2023, 25400));
    Worker menu();
}