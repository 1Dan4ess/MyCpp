#include<iostream>
#include<Windows.h>
#include <iomanip>
using namespace std;


int doubleNum(int n) 
{
    int x = 0;
    int x0 = 1;
    do
    {
        int last = n % 10;
        n /= 10;
        if (last == 1) {
            x += x0;
        }
        x0 *= 2;
    } while (n>0);
    return x;
}


int biFind(int a[], int n, int size) {
    int start = a[0];
    int end = a[size - 1];
    do
    {
        int mid = (start + end) / 2;

        if (a[mid] == n)
        {
            return mid;
        }
        else if (a[mid] > n)
        {
            end = mid - 1;
        }
        else if (a[mid] < n)
        {
            start = mid + 1;
        }
    } while (start <= end);
}
int main() 
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);


    //2
    const int size = 31;
    int a[size], n;
    for (size_t i = 0; i < size; i++) {
        a[i] = i;
    }
    for (size_t i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Ключ: ";
    cin >> n;
    cout << "Індекс: ";
    cout << biFind(a, n, size) << endl;
    return 0;
  




    //3
    //int n;
    //cin >> n;
    //cout << doubleNum(n) << endl;
    //return 0;
}