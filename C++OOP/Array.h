#pragma once
#include<iostream>
using namespace std;

class Array
{
	int* arr = nullptr;
	int size = 1;

public:
	void menu()
	{
		arr = new int[size] {};
		while (true)
		{
			cout << "1 - Print\n2 - AddValue\n3 - RandomSet\n4 - Remove\n5 - Insert\n6 - Sort\n7 - Reverse\n8 - Clear\n9 - Resize\n10 - Fill\n11 - PrintInd" << endl;
			int choice;
			cin >> choice;
			cout << endl;
			switch (choice)
			{
			case(1): 
				printArray();
				cout << endl;
				break;
			case(2):
				int val;
				cout << "Value: ";
				cin >> val;
				addValueArray(arr, size, val);
				cout << endl;
				break;
			case(3): 
				setRandom(); 
				cout << endl;
				break;
			case(4):
				int rind;
				cout << "Index: ";
				cin >> rind;
				remove(rind);
				cout << endl;
				break;
			case(5):
				int insind, insval;
				cout << "Index: ";
				cin >> insind;
				cout << "Value: ";
				cin >> insval;
				insert(insind, insval);
				cout << endl;
				break;
			case(6):
				sort();
				cout << endl;
				break;
			case(7):
				reverse();
				cout << endl;
				break;
			case(8):
				clear();
				cout << endl;
				break;
			case(9):
				int newsize;
				cout << "NewSize: ";
				cin >> newsize;
				resize(newsize);
				cout << endl;
				break;
			case(10):
				int fillval;
				cout << "Fill: ";
				cin >> fillval;
				fill(fillval);
				cout << endl;
				break;
			case(11):
				int pind;
				cout << "Index: ";
				cin >> pind;
				printArrayInd(pind);
				cout << endl;
				break;
			default:
				break;
			}
		}
	}

	void setRandom();
	void printArray();
	template<class T>
	void addValueArray(T*& arr, int& size, T value);
	void remove(int rind);
	void insert(int insind, int insval);
	void sort();
	void reverse();
	void clear();
	void resize(int newsize);
	void fill(int fillval);
	void printArrayInd(int pind);
};

void Array::printArrayInd(int pind)
{
	cout << arr[pind] << endl;
}

void Array::reverse()
{
	for (size_t i = 0; i < size/2; i++)
	{
		swap(arr[i], arr[size - 1 - i]);
	}
}

void Array::resize(int newsize)
{
	int* temp = new int[newsize] {};
	int count = size;

	for (int i = 0; i < newsize; i++)
	{
		if (i >= size)
		{
			temp[i] = 0;
		}
		else
		{
			temp[i] = arr[i];
		}
	}
	delete[] arr;
	arr = temp;
	size = newsize;
}

void Array::sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void Array::remove(int rind)
{
	int* arr2 = new int[size - 1];
	int ind2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != rind)
		{
			arr2[ind2] = arr[i];
			ind2 += 1;
		}
	}
	delete[] arr;
	arr = arr2;
	size -= 1;
}

void Array::insert(int insind, int insval)
{
	int* arr2 = new int[size + 1];
	int ind2 = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (i == insind)
		{
			arr2[i] = insval;
			ind2 += 1;
		}
		arr2[ind2] = arr[i];
		ind2 += 1;
	}
	delete[] arr;
	arr = arr2;
	size += 1;
}

void Array::clear()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}

void Array::fill(int fillval)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = fillval;
	}
}

void Array::printArray()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

template<class T>
void Array::addValueArray(T*& arr, int& size, T value)
{
	T* temp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = value;
	delete[] arr;
	size++;
	arr = temp;
}

void Array::setRandom()
{
	int min = 0;
	int max = 100;
	delete[] arr;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = min + rand() % (max - min + 1);
	}
}