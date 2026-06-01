#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
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
	SetColor(White, Black);


	//int min = 0, max = 9;
	//const int row = 3, col = 3;
	//int a[3][3];
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		a[i][j] = rand() % (max - min + 1) + min;
	//	}
	//}
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;
	//}



	//SetColor(White, Black);
	//int min = 10, max = 99;
	//const int row = 5, col = 5;
	//int a[row][col];
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		a[i][j] = rand() % (max - min + 1) + min;
	//	}
	//}
	//int bigg = a[0][0], smll = a[0][0];
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		if (a[i][j] > bigg)
	//		{
	//			bigg = a[i][j];
	//		}
	//		else if (a[i][j] < smll)
	//		{
	//			smll = a[i][j];
	//		}
	//	}
	//}
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		SetColor(White, Black);
	//		if (a[i][j] == bigg)
	//		{
	//			SetColor(LightRed, Black);
	//			cout << a[i][j] << " ";
	//		}
	//		else if (a[i][j] == smll)
	//		{
	//			SetColor(LightGreen, Black);
	//			cout << a[i][j] << " ";
	//		}
	//		else
	//		{
	//			cout << a[i][j] << " ";
	//		}
	//	}
	//	cout << endl;
	//}




	//SetColor(White, Black);
	//int min = 10, max = 99, summ = 0, start = 0, end = 0;
	//const int row = 5, col = 5;
	//int a[row][col];
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		a[i][j] = rand() % (max - min + 1) + min;
	//	}
	//}
	//int bigg = a[0][0], smll = a[0][0];
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		if (a[i][j] > bigg)
	//		{
	//			bigg = a[i][j];
	//		}
	//		else if (a[i][j] < smll)
	//		{
	//			smll = a[i][j];
	//		}
	//	}
	//}
	//int imax, jmax, imin, jmin;
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		
	//		SetColor(White, Black);
	//		if (a[i][j] == bigg and start == 0)
	//		{
	//			SetColor(Black, White);
	//			cout << a[i][j] << " ";
	//			start = 1;
	//			imax = i;
	//			jmax = j;
	//		}
	//		else if (a[i][j] == smll and end == 0)
	//		{
	//			SetColor(Black, White);
	//			cout << a[i][j] << " ";
	//			end = 1;
	//			imin = i;
	//			jmin = j;
	//		}
	//		else
	//		{
	//			cout << a[i][j] << " ";
	//		}
	//	}
	//	cout << endl;
	//}
	//for (size_t i = imin; i <= imax; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		if (i == imin and j > jmin or i == imax and j < jmax or i > imin and i < imax)
	//		{
	//			cout << a[i][j] << endl;
	//			summ += a[i][j];
	//		}
	//	}
	//}
	//cout << summ << endl;
	
	


int min = 0, max = 9; const int row = 3, col = 3; int a[row][col];
for (size_t i = 0; i < row; i++)
{
	for (size_t j = 0; j < col; j++)
	{
		bool flag = false;
		while (!flag)
		{
			int r = rand() % (max - min + 1) + min;
			flag = true;
			for (size_t k = 0; k < row; k++)
			{
				for (size_t m = 0; m < col; m++)
				{
					if (k == i && m == j) break;
					if (a[k][m] == r)
					{
						flag = false;
					}
				}
				if (!flag) break;
			}
			if (flag)
			{
				a[i][j] = r;
				break;
			}
		}
	}
} for (size_t i = 0; i < row; i++) {
	for (size_t j = 0; j < col; j++)
	{
		cout << a[i][j] << " ";
	}
	cout << endl;
}
}