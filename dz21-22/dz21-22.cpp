#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstdlib>
#include<fstream>
#include <cstring>
#include "Reservoir.h"
#include "String.h"
using namespace std;

void addReservoir(Reservoir*& arr, int& size, const Reservoir& newRes)
{
    Reservoir* arr0 = new Reservoir[size + 1];
    for (int i = 0; i < size; i++)
    {
        arr0[i] = arr[i];
    }
    arr0[size] = newRes;
    delete[] arr;
    arr = arr0;
    size++;
}

void printReservoirs(Reservoir* reservoirs, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        reservoirs[i].printAll();
    }
}

void menu(Reservoir*& reservoirs, int& size)
{
    while (true)
    {
        system("cls");
        cout << "1 - printReservoirs\n2 - addReservoir\n3 - getObiem\n4 - getPloshad\n5 - deleteReservoir\n6 - copyReservoir" << endl;
        cout << "Number: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case(1): 
            system("cls");
            printReservoirs(reservoirs, size); 
            system("pause");
            break;
        case(2): 
        {
            system("cls");
            String name;
            int type;
            double width;
            double length;
            double depth;
            name.write();
            cout << "Write number: 1 - Ocean, 2 - Sea, 3 - Lake, 4 - River, 5 - Pond, 6 - Swamp, 7 - Puddle" << endl;
            cin >> type;
            cout << "Enter width/length/depth:" << endl;
            cin >> width;
            cin >> length;
            cin >> depth;
            addReservoir(reservoirs, size, Reservoir(ReservoirType(type), name, width, length, depth));
            system("pause");
            break;
        }
        case(3):
            system("cls");
            printReservoirs(reservoirs, size);
            cout << endl;
            int i;
            cout << "Enter number to get obiem:" << endl;
            cin >> i;
            cout << fixed << setprecision(2) << reservoirs[i-1].getObiem() << endl;
            system("pause");
            break;
        case(4):
            system("cls");
            printReservoirs(reservoirs, size);
            cout << endl;
            int i2;
            cout << "Enter number to get ploshad:" << endl;
            cin >> i2;
            cout << fixed << setprecision(2) << reservoirs[i2-1].getPloshad() << endl;
            system("pause");
            break;
        case(5):
            system("cls");
            printReservoirs(reservoirs, size);
            cout << endl;
            int i3;
            cout << "Enter number to delete:" << endl;
            cin >> i3;
            Reservoir::deleteReservoir(reservoirs, size, i3-1);
            system("pause");
            break;
        case(6):
            system("cls");
            printReservoirs(reservoirs, size);
            cout << endl;
            int i4;
            cout << "Enter number to copy and paste at the end:" << endl;
            cin >> i4;
            Reservoir::copyReservoir(reservoirs, size, i4 - 1);
            system("pause");
            break;
        default:
            break;
        }
    }
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

    Reservoir* reservoirs = nullptr;
    int size = 0;

	addReservoir(reservoirs, size, Reservoir(ReservoirType::River, String("Dnipro"), 100, 400.2, 50));
	addReservoir(reservoirs, size, Reservoir(ReservoirType::Lake, String("Baikal"), 450.5, 500.5, 10));
    menu(reservoirs, size);
}