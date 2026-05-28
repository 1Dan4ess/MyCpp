#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

//enum Color
//{
//	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
//	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
//};
//
//void SetColor(int text, int background)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
//}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//SetColor(White, Black);
	//system("cls");




	/*int a, x;
	x = 0;*/
	//do
	//{
	//	cin >> a;
	//	x += a;
	//} while (a != 0);
	//cout << "Сума = " << x << endl;
	//cin >> a;
	//x += a;
	//while (a != 0)
	//{
	//	cin >> a;
	//	x += a;
	//}
	//cout << "Сума = " << x << endl;




	/*int a, n = 0;
	do
	{
		cin >> a;
		n += 1;
	} while (n < 10 and a != 0);
	cout << "10 чисел або 0" << endl;*/




	//int a, s1 = 0, x1, dob1 = 1, sq2 = 0, sq3 = 0, s1n = 0;
	//float ser, n = 0;
	//cin >> a;
	//while (a > 0)
	//{
	//	x1 = a % 10;
	//	if (s1n == 0)
	//	{
	//		s1n += x1;
	//	}
	//	a /= 10;
	//	n += 1;
	//	s1 += x1;
	//	dob1 *= x1;
	//	sq2 += pow(x1, 2);
	//	sq3 += pow(x1, 3);
	//}

	//ser = s1 / n;
	//s1n += x1;

	//cout << "Сума цифр - " << s1 << endl;
	//cout << "Кількість цифр - " << n << endl;
	//cout << "Добуток цифр - "<< dob1 << endl;
	//cout << "Середнє арифметичне - "<< ser << endl;
	//cout << "Сума квадратів - "<< sq2 << endl;
	//cout << "Сума кубів - " << sq3 << endl;
	//cout << "Перша цифра - "<< x1 << endl;
	//cout << "Сума першої і останньої - "<< s1n << endl;

	int min, max, s5 = 0, s3_1 = 0, s3_2 = 0, s3_3 = 0;
	min = 1;
	max = 5;
	for (int i = 1; i <= 18; i++)
	{
		int s3 = 0;
		for (int k1 = 1; k1 <= 3; k1++)
		{
			int k = min + rand() % (max - min + 1);
			if (k1 == 3)
			{
				cout << " " << k << endl;
			}
			else
			{
				cout << " " << k;
			}
			if (k == 5)
			{
				s5 += 1;
			}
			else if (k == 3)
			{
				s3 += 1;
			}

		}
		cout << "У учня " << i << " - " << s3 << " тройки" << endl;
		cout << endl;
		s3 = 0;
	}
	//cout << "П'ятірок: " << s5 << endl;
}