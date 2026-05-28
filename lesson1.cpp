#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout.setf(ios::boolalpha);

	//cout << "Hello \"Wor\\ld!\"\n" << endl;
	//cout << "\tМене звати Даня" << endl;
	//cout << 125 << endl;
	//cout << 125.55 << endl;
	//cout << true << endl;

	// bool - 1b
	// char - 1b

	// short - 2b
	// int - 4b
	// long - 4b
	// long long - 8b

	// float - 4b (7 digits)
	// double - 8b (15 digits)
	// long double - 16b (19 digits)



	//const int a = 5;
	//cout << a << endl;
	//cout << &a << endl;

	//float b = -1.5;
	//cout << b << endl;

	//char t = 'a';
	//cout << (char)(t + 3.5f) << endl;

	//cout << 5.0 / 3 << endl;

	//unsigned int c = 3000000000;
	//cout << c << endl;


	// _


	// + - ++ --
	// + - * / % += -= *= /= %=
	// !
	// < > <= >= == != && ||
	// () [] {} :: ~ ?: -> . , 

	//int a = 5, b = 4, c;
	//c = a++ * (--b + a--/++b);
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;
	//cout << 10 % 5 << endl;
	//a = a + b; //a += b;
	//cout << (int)(15.2 / 4) << endl;
	//c = !a;


	//int a, b;
	//cin >> a;
	//cin >> b;
	//float c = (a + b) / 2.f;
	//cout << c << endl;

	int x;
	cin >> x;
	float y = (float)(3 * pow(x, 6) - 6 * pow(x, 2) - 7);
	cout << y << endl;

	int a, s, s1;
	cin >> a;
	s = (a % 100) / 10 + (a % 100) % 10 + (a / 100);
	s1 = ((a % 100) / 10) * ((a % 100) % 10) * ((a / 100));
	cout << s << endl;
	cout << s1 << endl;

	return 0;
}