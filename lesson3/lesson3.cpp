#include<iostream>
#include<Windows.h>
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
	//	SetConsoleCP(1251);
	//	SetConsoleOutputCP(1251);
	//	//SetColor(White, Black);
	//	//system("cls");
	//	//SetColor(LightRed, Black);
	//	//cout << "Hello" << endl;
	//
	//	char text, back;
	//	cout << "Шрифт - " << endl;
	//	cin >> text;
	//	cout << "Бек - " << endl;
	//	cin >> back;
	//	switch (text)
	//	{
	//	case Black: SetColor(Black, Black);
	//		break;	
	//	case Blue: SetColor(Blue, back);
	//		break;
	//	case Green: SetColor(Green, back);
	//		break;
	//	case Cyan: SetColor(text, back);
	//		break;
	//	case Red: SetColor(text, back);
	//		break;
	//	case Magenta: SetColor(text, back);
	//		break;
	//	case Brown: SetColor(text, back);
	//		break;
	//	case LightGray: SetColor(text, back);
	//		break;
	//	case DarkGray: SetColor(text, back);
	//		break;
	//	case LightBlue: SetColor(text, back);
	//		break;
	//	case LightGreen:
	//		break;
	//	case LightCyan:
	//		break;
	//	case LightRed:
	//		break;
	//	case LightMagenta:
	//		break;
	//	case Yellow:
	//		break;
	//	case White:
	//		break;
	//	default:
	//		break;
	//	}
	//	switch (back)
	//	{
	//	case Black: SetColor(text, Black); system("cls");
	//		break;
	//	case Blue: SetColor(Blue, back);
	//		break;
	//	case Green: SetColor(Green, back);
	//		break;
	//	case Cyan: SetColor(text, back);
	//		break;
	//	case Red: SetColor(text, back);
	//		break;
	//	case Magenta: SetColor(text, back);
	//		break;
	//	case Brown: SetColor(text, back);
	//		break;
	//	case LightGray: SetColor(text, back);
	//		break;
	//	case DarkGray: SetColor(text, back);
	//		break;
	//	case LightBlue: SetColor(text, back);
	//		break;
	//	case LightGreen:
	//		break;
	//	case LightCyan:
	//		break;
	//	case LightRed:
	//		break;
	//	case LightMagenta:
	//		break;
	//	case Yellow:
	//		break;
	//	case White:
	//		break;
	//	default:
	//		break;
	//	}



		//float a, b, c;
		//cin >> a;
		//cin >> b;
		//cin >> c;

		//if (a > b){
		//	if (a > c) 
		//	{
		//		cout << a << endl;
		//	}
		//	else 
		//	{
		//		cout << c << endl;
		//	}
		//}
		//else if (a < b) 
		//{
		//	if (b > c) 
		//	{
		//		cout << b << endl;
		//	}
		//	else 
		//	{
		//		cout << c << endl;
		//	}
		//}







		/*float n1, n2, res;
		char op;
		cout << "n1 = ";
		cin >> n1;
		cout << "Operator = ";
		cin >> op;
		cout << "n2 = ";
		cin >> n2;*/
		/*if (op == '+') {
			res = n1 + n2;
			cout << "Результат = " << res << endl;
		}
		else if (op == '-') {
			res = n1 - n2;
			cout << "Результат = "<< res << endl;
		}
		else if (op == '*') {
			res = n1 * n2;
			cout << "Результат = " << res << endl;
		}
		else if (op == '/') {
			res = n1 / n2;
			cout << "Результат = " << res << endl;
		}
		else {
			cout << "Помилка" << endl;*/
			//}
			//switch (op) 
			//{
			//	case '+': 
			//		cout << n1 + n2 << endl;
			//		break;
			//	case '-': 
			//		cout << n1 - n2 << endl; 
			//		break;
			//	case '*': 
			//		cout << n1 * n2 << endl; 
			//		break;
			//	case '/': 
			//		cout << n1 / n2 << endl;
			//		break;
			//	default:  cout << "Error" << endl;
			//}

			/*int m;
			cin >> m;
			switch (m) {
			case 1: case 2: case 12: cout << "Winter"; break;
			case 3: case 4: case 5: cout << "Spring"; break;
			case 6: case 7: case 8: cout << "Summer"; break;
			case 9: case 10: case 11: cout << "Autumn"; break;
			default: cout << "Error" << endl;
			}*/







	int a, des, od;
	cin >> a;

	des = a / 10;
	od = a % 10;
	if (a % 10 == 0)
	{
		switch (a)
		{
		case 10: cout << "десять"; break;
		case 20: cout << "двадцять"; break;
		case 30: cout << "тридцять"; break;
		case 40: cout << "сорок"; break;
		case 50: cout << "п'ятдесят"; break;
		case 60: cout << "шістдесят"; break;
		case 70: cout << "сімдесят"; break;
		case 80: cout << "вісімдесят"; break;
		case 90: cout << "дев'яносто"; break;
		}
		cout << " копійок";
	}

	else if (a < 20 and a > 10 and a != 0)
	{
		switch (od) {
		case 1: cout << "оди"; break;
		case 2: cout << "два"; break;
		case 3: cout << "три"; break;
		case 4: cout << "чотир"; break;
		case 5: cout << "п'ят"; break;
		case 6: cout << "шіст"; break;
		case 7: cout << "сім"; break;
		case 8: cout << "вісім"; break;
		case 9: cout << "дев'ят"; break;
		}
		switch (des)
		{
		default: cout << "надцять";
		}
		switch (od)
		{
		default: cout << " копійок"; break;
		}
	}


	else if (a < 11 and a != 0)
	{
		switch (od)
		{
		case 1: cout << "одна"; break;
		case 2: cout << "дві"; break;
		case 3: cout << "три"; break;
		case 4: cout << "чотири"; break;
		case 5: cout << "п'ять"; break;
		case 6: cout << "шість"; break;
		case 7: cout << "сім"; break;
		case 8: cout << "вісім"; break;
		case 9: cout << "дев'ять"; break;
		default: cout << "нуль";
		}
		switch (od)
		{
		case 1: cout << " копійка"; break;
		case 2: case 3: case 4: cout << " копійки"; break;
		case 5: case 6: case 7: case 8: case 9: case 0: cout << " копійок"; break;
		}
	}


	else if (a > 20 and a < 100 and a != 0)
	{
		switch (des)
		{
		case 2: cout << "двадцять"; break;
		case 3: cout << "тридцять"; break;
		case 4: cout << "сорок"; break;
		case 5: cout << "п'ятдесят"; break;
		case 6: cout << "шістдесят"; break;
		case 7: cout << "сімдесят"; break;
		case 8: cout << "вісімдесят"; break;
		case 9: cout << "дев'яносто"; break;
		}
		switch (od)
		{
		case 1: cout << "одна"; break;
		case 2: cout << "дві"; break;
		case 3: cout << "три"; break;
		case 4: cout << "чотири"; break;
		case 5: cout << "п'ять"; break;
		case 6: cout << "шість"; break;
		case 7: cout << "сім"; break;
		case 8: cout << "вісім"; break;
		case 9: cout << "дев'ять"; break;
		}
		switch (od)
		{
		case 1: cout << " копійка"; break;
		case 2: case 3: case 4: cout << " копійки"; break;
		case 5: case 6: case 7: case 8: case 9: case 0: cout << " копійок"; break;
		}
	}
	else if (a > 99)
	{
		cout << "Error" << endl;
	}
	else if (a == 0)
	{
		cout << "нуль копійок" << endl;
	}

	return 0;
}