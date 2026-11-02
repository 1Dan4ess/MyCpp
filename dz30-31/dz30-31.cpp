#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
#include<fstream>
#include <cstring>
using namespace std;
#include <ctime>
#include"File.h"


int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

    File a;
    AsciiFile b;
    BinaryFile c;
    File* ptr;
    ptr = &a;
    ptr->Display("test.txt");
    ptr = &b;
    ptr->Display("test.txt");
    ptr = &c;
    ptr->Display("test.txt");
}