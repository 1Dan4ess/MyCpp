#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include<cstring>
using namespace std;
#include "BasePolice.h"

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    BasePolice police;

    police.addProtocol();
    police.addProtocol();

    police.save();

    cout << "\nДані з файлу:\n";
    police.load();

    return 0;
}