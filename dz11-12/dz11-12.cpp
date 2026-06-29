#include<iostream>
#include<Windows.h>
#include <iomanip>
using namespace std;

int* sizeArray(int size) 
{
    return new int[size];
}

void setArray(int* a, int size, int min = 1, int max = 100) 
{
    for (size_t i = 0; i < size; i++)
    {
        a[i] = rand() % (max - min + 1) + min;
    }
}

void printArray(int* a, int size) 
{
    for (size_t i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void deleteArray(int*& a) 
{
    delete[] a;
    a = nullptr;
}

void addArrayEnd(int*& a, int& size, int val) 
{
    int* newa = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        newa[i] = a[i];
    }
    newa[size] = val;
    delete[] a;
    a = newa;
    size++;
}

void addArrayInd(int*& a, int& size, int ind, int val) 
{
    int* newa = new int[size + 1];
    for (int i = 0; i < ind; i++)
    {
        newa[i] = a[i];
    }
    newa[ind] = val;
    for (int i = ind; i < size; i++)
    {
        newa[i + 1] = a[i];
    }
    delete[] a;
    a = newa;
    size++;
}

void deleteArrayInd(int*& a, int& size, int ind) 
{
    if (size == 1) 
    {
        deleteArray(a);
        size = 0;
        return;
    }
    int* newa = new int[size - 1];
    for (int i = 0; i < ind; i++) 
    {
        newa[i] = a[i];
    }
    for (int i = ind + 1; i < size; i++) 
    {
        newa[i - 1] = a[i];
    }
    delete[] a;
    a = newa;
    size--;
}



bool check(int n) 
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int* remove(int* a, int& size) 
{
    int newSize = 0;
    for (int i = 0; i < size; i++) 
    {
        if (!check(a[i])) 
        {
            newSize++;
        }
    }
    int* newa = new int[newSize];
    int index = 0;
    for (int i = 0; i < size; i++) 
    {
        if (!check(a[i])) 
        {
            newa[index] = a[i];
            index++;
        }
    }
    delete[] a;
    size = newSize;
    return newa;
}

void split(int* staticArr, int size, int*& posArr, int& posSize, int*& negArr, int& negSize, int*& zeroArr, int& zeroSize) {
    posSize = 0;
    negSize = 0;
    zeroSize = 0;
    for (int i = 0; i < size; i++) 
    {
        if (staticArr[i] > 0) posSize++;
        else if (staticArr[i] < 0) negSize++;
        else zeroSize++;
    }
    posArr = new int[posSize];
    negArr = new int[negSize];
    zeroArr = new int[zeroSize];
    int p = 0, n = 0, z = 0;
    for (int i = 0; i < size; i++) 
    {
        if (staticArr[i] > 0) 
        {
            posArr[p] = staticArr[i];
            p++;
        }
        else if (staticArr[i] < 0) 
        {
            negArr[n] = staticArr[i];
            n++;
        }
        else 
        {
            zeroArr[z] = staticArr[i];
            z++;
        }
    }
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

    //1

    //int size;
    //cin >> size;
    //int* arr = sizeArray(size);
    //setArray(arr, size);

    //while (true)
    //{
    //    int choice;
    //    cout << "Введіть 1-7: ";
    //    cin >> choice;

    //    switch (choice)
    //    {
    //    case 1:
    //        arr = sizeArray(size);
    //        cout << arr << endl;
    //        break;
    //    case 2:
    //        setArray(arr, size);
    //        break;
    //    case 3:
    //        printArray(arr, size);
    //        break;
    //    case 4:
    //        deleteArray(arr);
    //        break;
    //    case 5:
    //    {
    //        int value;
    //        cin >> value;
    //        addArrayEnd(arr, size, value);
    //        break;
    //    }
    //    case 6:
    //    {
    //        int index, value;
    //        cin >> index >> value;
    //        addArrayInd(arr, size, index, value);
    //        break;
    //    }
    //    case 7:
    //    {
    //        int index;
    //        cin >> index;
    //        if (index >= 0 and index < size)
    //        {
    //            deleteArrayInd(arr, size, index);
    //        }
    //        break;
    //    }
    //    }
    //}


    //2

    //int size;
    //cin >> size;
    //int* arr = sizeArray(size);
    //setArray(arr, size);
    //printArray(arr, size);
    //arr = remove(arr, size);
    //printArray(arr, size);


    //3

    int staticArr[11] = {0, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    int size = 11;

    int* pos = nullptr;
    int *neg = nullptr;
    int *zero = nullptr;
    int pSize, nSize, zSize;
    split(staticArr, size, pos, pSize, neg, nSize, zero, zSize);
    printArray(pos, pSize);
    printArray(neg, nSize);
    printArray(zero, zSize);
}