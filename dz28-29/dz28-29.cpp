#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include"BitString.h"
#include"Animal.h"
using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

    BitString a("110");
	a.show();
    BitString b("101");
	b.show();
    BitString c = a + b;
    c.show();
    a += b;
    a.show();
    BitString d("001011");
    cout << "a == d: " << (a == d) << endl;

	//Cat c(2, "Вася", "Мейнкун");
	//Dog d(5, "Гром", "Сальто", true);
	//Parrot p(1, "Чіжик", "Синій", "Гав гав мяу");
	//cout << c.getAge() <<"\n"<< c.getName() << "\n" << c.getType() << "\n" << c.getParoda() << endl;
	//cout << endl;
	//cout << d.getAge() << "\n" << d.getName() << "\n" << d.getType() << "\n" << d.isFighting() << endl;
	//d.getCommand();
	//cout << endl;
	//cout << p.getAge() << "\n" << p.getName() << "\n" << p.getType() << "\n" << p.getColor() << "\n"<< p.getVoice() << endl;
}