#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);


	//#1
	int time, h, s, m;
	cin >> time;
	h = time / 3600;
	m = (time - h * 3600) / 60;
	s = time % 60;
	cout << h << " годин(a), " << m << " хвилин(a), " << s << " секунд(a)" << endl;

	////#2
	//float x;
	//cin >> x;
	//int grn = x / 1;
	//int kop = (x - grn) * 100;
	//cout << grn << " грн. "<< kop << " коп. " << endl;

	////3
	//int s;
	//float t;
	//cout << "Обчислення швидкості бігу" << endl;
	//cout << "Введіть довжину дистанції(м): "; 
	//cin >> s;
	//cout << "Введіть час(хв.сек): ";
	//cin >> t;
	//int min = t / 1;
	//int sec = (t - min) * 100 +0.1;
	//cout << "Дистанція: " << endl;
	//int t1 = min * 60 + sec;
	//cout << "Час: "<< min<< " хв "<< sec<< " сек = "<< t1<< " сек" << endl;
	//float v = (s/1000.0) / (t1/3600.0);
	//cout << "Ви бігли зі швидкістю: "<< v << " км/год" << endl;

	////4
	//int d;
	//cout << "Введіть кількість днів: "; 
	//cin >> d;
	//int week, day;
	//week = d / 7;
	//day = d - week*7;
	//cout << week << " тижні(в), " << day << " дні(в)"<< endl;
	//return 0;
}