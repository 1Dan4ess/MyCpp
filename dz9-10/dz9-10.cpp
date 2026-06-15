#include<iostream>
#include<Windows.h>
#include <iomanip>
using namespace std;

//--------------------3----------------------------------------------------------------------------
template<class T>
void setArray(T a[], int size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		a[i] = rand() % (max - min + 1) + min;
	}
}

template<class T>
void printArray(T a[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

template<class T>
void sortArray(T a[], int size)
{
	T left = a[0];
	T right = a[size - 1];
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] < 0)
		{
			left = i;
			break;
		}
	}
	for (size_t i = size - 1; i > 0; i--)
	{
		if (a[i] < 0)
		{
			right = i;
			break;
		}
	}
	for (size_t i = left; i < right; i++)
	{
		for (size_t j = 0; j < right - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}
//-------------------------------------------------------------------------------------------------
void createField(char a[][5], int row, int col)
{
	int btns = 97;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (i == 0 || i == row - 1)
			{
				if (j == 0 || j == col - 1)
				{
					a[i][j] = '#';
				}
				else
				{
					a[i][j] = '-';
				}
			}
			else
			{
				if (j == 0 || j == col - 1)
				{
					a[i][j] = '|';
				}
				else
				{
					a[i][j] = btns;
					btns += 1;
				}
			}
		}
	}
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << setw(3) << a[i][j];
		}
		cout << endl;
	}
}

void setField(char a[][5], int row, int col, char symb, char altsymb, char step, char step2, int moves) 
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (a[i][j] == step)
			{
				a[i][j] = symb;
			}
			else if (a[i][j] == step2)
			{
				a[i][j] = altsymb;
			}
		}
	}
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << setw(3) << a[i][j];
		}
		cout << endl;
	}
}

char move() 
{
	char step;
	cout << "Напишіть букву, щоб походити(гравець 1): ";
	cin >> step;
	if (step < 'a' or step > 'i')
	{
		cout << "Немає такої клітинки" << endl;
		move();
	}
	else
	{
		return step;
	}
}
char move2()
{
	char step2;
	cout << "Напишіть букву, щоб походити(гравець 2): ";
	cin >> step2;
	if (step2 < 'a' or step2 > 'i')
	{
		cout << "Немає такої клітинки" << endl;
		move2();
	}
	else
	{
		return step2;
	}
}

char symbol() 
{
	char symb;
	cout << "Виберіть символ гравця 1(X, O): ";
	cin >> symb;
	if (symb != 'x' && symb != 'o' && symb != 'X' && symb != 'O')
	{
		symbol();
	}
	else 
	{
		return symb;
	}
}




bool check(char a[][5], int row, int col, char symb, char altsymb, char step, int moves)
{
	for (size_t i = 1; i <= 3; i++)
	{
		if (a[i][1] == a[i][2] and a[i][2] == a[i][3] and a[i][1] == symb)
		{
			return true;
		}
		else if (a[1][i] == a[2][i] and a[2][i] == a[3][i] and a[1][i] == symb)
		{
			return true;
		}
	}
	if (a[1][1] == a[2][2] and a[2][2] == a[3][3] and a[1][1] == symb)
	{
		return true;
	}
	else if (a[1][3] == a[2][2] and a[2][2] == a[3][1] and a[1][3] == symb)
	{
		return true;
	}
	return false;
}

bool check2(char a[][5], int row, int col, char symb, char altsymb, char step, int moves)
{
	for (size_t i = 1; i <= 3; i++)
	{
		if (a[i][1] == a[i][2] and a[i][2] == a[i][3] and a[i][1] == altsymb)
		{
			return true;
		}
		else if (a[1][i] == a[2][i] and a[2][i] == a[3][i] and a[1][i] == altsymb)
		{
			return true;
		}
	}
	if (a[1][1] == a[2][2] and a[2][2] == a[3][3] and a[1][1] == altsymb)
	{
		return true;
	}
	else if (a[1][3] == a[2][2] and a[2][2] == a[3][1] and a[1][3] == altsymb)
	{
		return true;
	}
	return false;
}





void game() 
{
	const int col = 5, row = 5;
	char a[row][col], symb = 'a', altsymb = 'a', step = 'n', step2 = 'n';
	int moves = 0;
	createField(a, row, col);

	symb = symbol();
	if (symb == 'X' or symb == 'x')
	{
		symb = 'X';
		altsymb = 'O';
	}
	else if (symb == 'O' or symb == 'o')
	{
		symb = 'O';
		altsymb = 'X';
	}

	while (moves < 9) {
		step = move();
		setField(a, row, col, symb, altsymb, step, step2, moves);
		if (check(a, row, col, symb, altsymb, step, moves) == true)
		{
			cout << "Переміг 1 гравець" << endl;
			break;
		}

		if (moves == 8)
		{
			cout << "Закінчились ходи" << endl;
			break;
		}
		moves += 1;

		step2 = move2();
		setField(a, row, col, symb, altsymb, step, step2, moves);
		if (check2(a, row, col, symb, altsymb, step2, moves) == true)
		{
			cout << "Переміг 2 гравець" << endl;
			break;
		}
		moves += 1;
	}
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	game();

	//3
	//const int size = 10;
	//int a[size], min = -20, max = 20;
	//setArray(a, size, min, max);
	//printArray(a, size);
	//sortArray(a, size);
	//printArray(a, size);
}