#pragma once
#include<iostream>
#include "Fraction.h"
#define assert
using namespace std;

template<class T>

class Array
{
	T* arr = nullptr;
	int size = 10;

public:

	Array(const Array& obj)
	{
    size = obj.size;
    arr = new T[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
	}

	Array()
	{
		arr = new T[size]{};
	}

	Array<T>& operator=(const Array& obj)
	{
		if (this == &obj)
		{
			return *this;
		}

		delete[] arr;

		size = obj.size;
		arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
		return *this;
	}

	~Array()
	{
		delete[] arr;
	}

	void menu()
	{
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
				add(val);
				cout << endl;
				break;
			case(3): 
				setRandom(0, 100); 
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

	void setRandom() const;
	void printArray() const;
	void add(const T& value);
	void remove(int rind);
	void insert(int insind, const T& insval);
	void sort();
	void reverse();
	void clear();
	void resize(int newsize);
	void fill(const T& fillval);
	void printArrayInd(int pind);
};

template<class T>
void Array<T>::printArrayInd(int pind)
{
	cout << arr[pind] << endl;
}

template<class T>
void Array<T>::reverse()
{
	for (size_t i = 0; i < size/2; i++)
	{
		swap(arr[i], arr[size - 1 - i]);
	}
}

template<class T>
void Array<T>::resize(int newsize)
{
	if (newsize < 0) return;

	if (newsize == 0)
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
		return;
	}

	T* temp = new T[newsize] {};

	if (arr != nullptr)
	{
		int minSize = (size < newsize) ? size : newsize;
		for (int i = 0; i < minSize; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
	}

	arr = temp;
	size = newsize;
}

template<class T>
void Array<T>::sort()
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

template<class T>
void Array<T>::remove(int rind)
{
	if (rind < 0 || rind >= size)
		return;

	T* arr2 = new T[size - 1];

	int ind2 = 0;

	for (int i = 0; i < size; i++)
	{
		if (i != rind)
		{
			arr2[ind2] = arr[i];
			ind2++;
		}
	}

	delete[] arr;

	arr = arr2;
	size--;
}

template<class T>
void Array<T>::insert(int insind, const T& insval)
{
	T* arr2 = new T[size + 1];
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

template<class T>
void Array<T>::clear()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}

template<class T>
void Array<T>::fill(const T& fillval)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = fillval;
	}
}

template<class T>
void Array<T>::printArray() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

template<class T>
void Array<T>::add(const T& value)
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

template<class T>
void Array<T>::setRandom() const
{
	cout << "No implamantation for " << typeid(T).name() << endl;
}

template <>
void Array<int>::setRandom() const
{
	cout << "Int realization" << endl;
	int min = -100;
	int max = 100;
	for (int i = 0; i < size; i++)
	{
		arr[i] = min + rand() % (max - min + 1);
	}
}