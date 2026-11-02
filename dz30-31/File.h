#pragma once
using namespace std;
#include <iostream>
#include <fstream>


class File
{
public:
    virtual void Display(const char* path)
    {
        ifstream file(path);
        char symbol;
        while (file.get(symbol))
        {
            cout << symbol;
        }
        cout << endl;
    }
};


class AsciiFile : public File
{
public:
    void Display(const char* path) override
    {
        ifstream file(path);
        char symbol;
        while (file.get(symbol))
        {
            int number = (unsigned char)symbol;
            cout << number << " ";
        }
        cout << endl;
    }
};


class BinaryFile : public File
{
public:
    void Display(const char* path) override
    {
        ifstream file(path);
        char symbol;
        while (file.get(symbol))
        {
            int number = (unsigned char)symbol;
            int bits[8];
            for (int i = 0; i < 8; i++)
            {
                bits[i] = number % 2;
                number /= 2;
            }
            for (int i = 7; i >= 0; i--)
            {
                cout << bits[i];
            }
            cout << " ";
        }
        cout << endl;
    }
};