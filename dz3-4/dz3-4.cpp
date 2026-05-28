#include<iostream>
#include<Windows.h>
using namespace std;



int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);




    //2

    //int s1, s2, s3, zp1, zp2, zp3;

    //zp1 = 200;
    //zp2 = 200;
    //zp3 = 200;

    //cout << "Продажи 1: ";
    //cin >> s1;
    //cout << "Продажи 2: ";
    //cin >> s2;
    //cout << "Продажи 3: ";
    //cin >> s3;

    //if (s1 < 500) 
    //{
    //    zp1 += +s1 * 0.03;
    //}
    //else if (s1 <= 1000) 
    //{
    //    zp1 += s1 * 0.05;
    //}
    //else {
    //    zp1 += s1 * 0.08;
    //}


    //if (s2 < 500) 
    //{
    //    zp2 += s2 * 0.03;
    //}
    //else if (s2 <= 1000) 
    //{
    //    zp2 += s2 * 0.05;
    //}
    //else {
    //    zp2 += s2 * 0.08;
    //}


    //if (s3 < 500) 
    //{
    //    zp3 += s3 * 0.03;
    //}
    //else if (s3 <= 1000) 
    //{
    //    zp3 += s3 * 0.05;
    //}
    //else {
    //    zp3 += s3 * 0.08;
    //}


    //if (zp1 > zp2 and zp1 > zp3) 
    //{
    //    zp1 += 200;
    //    cout << "Найкращий менеджер: 1" << endl;
    //}
    //else if (zp2 > zp1 and zp2 > zp3) 
    //{
    //    zp2 += 200;
    //    cout << "Найкращий менеджер: 2" << endl;
    //}
    //else 
    //{
    //    zp3 += 200;
    //    cout << "Найкращий менеджер: 3" << endl;
    //}
    //cout << "Зарплата 1: " << zp1 << endl;
    //cout << "Зарплата 2: " << zp2 << endl;
    //cout << "Зарплата 3: " << zp3 << endl;




    //3

    int y;
    cout << "Рік: ";
    cin >> y;
    int diff = y - 1984;
    if (diff < 0) {
        diff = (diff % 60) + 60;
    }
    int color = (diff % 10) / 2;
    cout << "Рік ";
    switch (color) {
    case 0: cout << "зеленого "; break;
    case 1: cout << "червоного "; break;
    case 2: cout << "жовтого "; break;
    case 3: cout << "білого "; break;
    case 4: cout << "чорного "; break;
    }
    int anim = diff % 12;
    switch (anim) {
    case 0: cout << "щура"; break;
    case 1: cout << "корови"; break;
    case 2: cout << "тигра"; break;
    case 3: cout << "зайця"; break;
    case 4: cout << "дракона"; break;
    case 5: cout << "змії"; break;
    case 6: cout << "коня"; break;
    case 7: cout << "вівці"; break;
    case 8: cout << "мавпи"; break;
    case 9: cout << "курки"; break;
    case 10: cout << "собаки"; break;
    case 11: cout << "свині"; break;
    }
}