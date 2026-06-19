#include<iostream>
#include<Windows.h>
#include <iomanip>
using namespace std;

void setArray(int a[], int size, int min = 0, int max = 100)
{
	for (size_t i = 0; i < size; i++)
	{
		a[i] = rand() % (max - min + 1) + min;
	}
}

void printArray(int a[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	//1
    //int m, n;
    //cout << "Розмір 1 масиву: ";
    //cin >> m;
    //int* A = new int[m];
    //for (int i = 0; i < m; i++) 
    //{
    //    cin >> A[i];
    //}
    //cout << "Розмір 2 масиву: ";
    //cin >> n;
    //int* B = new int[n];
    //for (int i = 0; i < n; i++)
    //{
    //    cin >> B[i];
    //}
    //int* C = new int[m];
    //int tempsize = 0;

    //bool check, check2;
    //for (int i = 0; i < m; i++) 
    //{
    //    check = false;
    //    for (int j = 0; j < n; j++) 
    //    {
    //        if (A[i] == B[j]) 
    //        {
    //            check = true;
    //            break;
    //        }
    //    }
    //    if (not check) 
    //    {
    //        check2 = false;
    //        for (int h = 0; h < tempsize; h++) 
    //        {
    //            if (C[h] == A[i]) 
    //            {
    //                check2 = true;
    //                break;
    //            }
    //        }
    //        if (not check2) 
    //        {
    //            C[tempsize] = A[i];
    //            tempsize++;
    //        }
    //    }
    //}
    //int* D = new int[tempsize];
    //for (int i = 0; i < tempsize; i++) 
    //{
    //    D[i] = C[i];
    //}
    //printArray(D, tempsize);
    //delete[] D;
    //delete[] C;
    //delete[] A;
    //delete[] B;


    //2
    int m, n;
    cout << "Розмір 1 масиву: ";
    cin >> m;
    int* A = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    cout << "Розмір 2 масиву: ";
    cin >> n;
    int* B = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    int* C = new int[n+m];
    int tempsize = 0;

    bool check, check2;
    for (int i = 0; i < m; i++) 
    {
        check = false;
        for (int j = 0; j < n; j++) 
        {
            if (A[i] == B[j]) 
            {
                check = true;
                break;
            }
        }
        if (not check) 
        {
            check2 = false;
            for (int h = 0; h < tempsize; h++) 
            {
                if (C[h] == A[i]) 
                {
                    check2 = true;
                    break;
                }
            }
            if (not check2) 
            {
                C[tempsize] = A[i];
                tempsize++;
            }
        }
    }


    for (int i = 0; i < n; i++) 
    {
        check = false;
        for (int j = 0; j < m; j++) 
        {
            if (B[i] == A[j]) 
            {
                check = true;
                break;
            }
        }
        if (not check) 
        {
            check2 = false;
            for (int h = 0; h < tempsize; h++) 
            {
                if (C[h] == B[i]) 
                {
                    check2 = true;
                    break;
                }
            }
            if (not check2) 
            {
                C[tempsize] = B[i];
                tempsize++;
            }
        }
    }
    int* D = new int[tempsize];
    for (int i = 0; i < tempsize; i++) 
    {
        D[i] = C[i];
    }
    printArray(D, tempsize);
    delete[] D;
    delete[] C;
    delete[] A;
    delete[] B;
}