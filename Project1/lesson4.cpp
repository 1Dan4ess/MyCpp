#include<iostream>
#include<Windows.h>
using namespace std;
#include<iomanip>

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
//
//int main()
//{
//	SetConsoleCP(65001);
//	SetConsoleOutputCP(65001);
//	cout.setf(ios::boolalpha);




	//(condition) ? oper1 : oper2
	//int a = 5, b = 4, c = 3, max;
	//if (a > b)
	//{
	//	max = a;
	//}
	//else
	//{
	//	max = b;
	//}
	//(a > b) ? max = a : max = b;




	//for (size_t i = 1; i <= 10; i++)
	//{
	//	cout << i << endl;
	//}
	//int i = 1;
	//while (i <= 10)
	//{
	//	cout << i << endl;
	//	i++;
	//}
	//do
	//{

	//} while (true);
	//cout << "" << endl;




	//float x;
	//cin >> x;

	//for (float i = 0.1; i < 1.1; i += 0.1)
	//{
	//	cout << i << " кг = " << x * i << endl;
	//}



	//float a, res;
	//int n;
	//cout << "a = ";
	//cin >> a;
	//res = a;
	//cout << "n = ";
	//cin >> n;

	//for (size_t i = 1; i <= n; i++)
	//{
	//	cout << res << endl;
	//	res *= a;
	//}


	//SetColor(Black, White);
	//system("cls");

	//SetColor(White, Black);
	//cout << " Пн" << " Вт" << " Ср" << " Чт" << " Пт";
	//SetColor(White, LightRed);
	//cout << " Cб" << " Вс" << endl;
	//SetColor(Black, White);
	//for (size_t i = 1; i <= 31; i++)
	//{
	//	if (i % 7 == 6 || i % 7 == 0)
	//	{
	//		SetColor(LightRed, White);
	//	}
	//	cout << setw(3) << i;
	//	SetColor(Black, White);
	//	if (i % 7 == 0)
	//	{
	//		cout << "" << endl;
	//	}
	//}



//
//	SetColor(Black, White);
//	system("cls");
//
//	SetColor(White, Black);
//	cout << " Пн" << " Вт" << " Ср" << " Чт" << " Пт";
//	SetColor(White, LightRed);
//	cout << " Cб" << " Вс" << endl;
//	SetColor(Black, White);
//	int k = 0;
//	for (int i = 1 - k; i <= 31; i++)
//	{
//		if (i <= 0)
//		{
//			cout << "   ";
//		}
//		else
//		{
//			SetColor((i % 7 == 6 || i % 7 == 0) ? LightRed : Black, White);
//			cout << setw(3) << i;
//			if ((i + k) % 7 == 0)
//			{
//				cout << endl;
//			}
//		}
//	}
//}