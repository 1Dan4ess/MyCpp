#include<iostream>
#include<Windows.h>
using namespace std;
#include<iomanip>

enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);


	SetColor(Black, White);
	system("cls");

	int k = 3;

	for (int month = 1; month <= 12; month++)
	{
		SetColor(White, Black);
		cout << "0" << month << ".2026" << endl;

		SetColor(White, Black);
		cout << " Пн" << " Вт" << " Ср" << " Чт" << " Пт";
		SetColor(White, LightRed);
		cout << " Cб" << " Вс";
		cout << endl;

		int days = 31;
		if (month == 4 or month == 6 or month == 9 or month == 11)
		{
			days = 30;
		}
		else if (month == 2)
		{
			days = 28;
		}

		for (int i = 1 - k; i <= days; i++)
		{
			if (i <= 0)
			{
				SetColor(Black, White);
				cout << "   ";
			}
			else
			{
				SetColor(((i + k) % 7 == 6 || (i + k) % 7 == 0) ? LightRed : Black, White);
				cout << setw(3) << i;

				if ((i + k) % 7 == 0)
				{
					SetColor(Black, White);
					cout << endl;
				}
			}
		}
		if ((days + k) % 7 != 0)
		{
			SetColor(Black, White);
			cout << endl;
		}

		k = (k + days) % 7;
	}
}