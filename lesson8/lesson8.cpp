#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include <iomanip>


#include"myFunc.h"


using namespace std;

//type name(param)
//{
//	body;
//}




int main()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	//int first, second, third;
	//cin >> first >> second >> third;
	////starLine();
	//cout << ser(first, second, third) << endl;




	const int size = 10;
	int arr[size], min, max;
	cout << "Min:" << endl;
	cin >> min;
	cout << "Max:" << endl;
	cin >> max;

	setArray(arr, min, max);
	printArray(arr, size);
}