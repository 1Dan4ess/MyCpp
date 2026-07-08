#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <cstring>
using namespace std;

int mystrcmp(const char* str1, const char* str2) 
{
    int i = 0;
    while (str1[i] == str2[i])
    {
        if (str1[i] == '\0')
        {
            return 0;
        }
        i++;
    }
    if (str1[i] > str2[i])
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

char* Uppercase(char* str) 
{
    int len = strlen(str);
    char* newStr = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            newStr[i] = str[i] - 32;
        }
        else
        {
            newStr[i] = str[i];
        }
    }
    newStr[len] = '\0';
    return newStr;
}

char* Lowercase(char* str) 
{
    int len = strlen(str);
    char* newStr = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            newStr[i] = str[i] + 32;
        }
        else
        {
            newStr[i] = str[i];
        }
    }
    newStr[len] = '\0';
    return newStr;
}

char* mystrrev(char* str) 
{
    int len = strlen(str);
    char* newStr = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        newStr[i] = str[len - 1 - i];
    }
    newStr[len] = '\0';
    return newStr;
}

int StringToNumber(char* str) 
{
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char buffer[1024];
    cin.getline(buffer, 1024);
    char* st = new char[strlen(buffer) + 1];
    strcpy(st, buffer);
    cout << "1 = Uppercase, 2 = Lowercase, 3 = mystrrev, 4 = mystrcmp, 5 = StringToNumber" << endl;
    int choice;
    cin >> choice;
    cin.ignore();
    char* result = nullptr;

    switch (choice)
    {
    case 1: result = Uppercase(st); break;
    case 2: result = Lowercase(st); break;
    case 3: result = mystrrev(st); break;
    case 4:
        char buffer2[1024];
        cout << "Другий рядок: ";
        cin.getline(buffer2, 1024);
        cout << mystrcmp(st, buffer2) << endl;
        break;
    case 5:
        cout << StringToNumber(st) << endl;
        break;
    }
    if (result != nullptr)
    {
        cout << result << endl;
        delete[] result;
    }
}