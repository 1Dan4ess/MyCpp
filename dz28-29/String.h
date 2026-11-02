#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class String
{
    int size;
    char* str;

public:
    String() : String(80) {}

    String(int s)
    {
        size = s < 0 ? 0 : s;
        str = new char[size + 1];
        str[0] = '\0';
    }

    String(const char* buff)
    {
        if (buff != nullptr)
        {
            size = strlen(buff);
            str = new char[size + 1];
            strcpy(str, buff);
        }
        else
        {
            size = 0;
            str = new char[1];
            str[0] = '\0';
        }
    }

    String(const String& str)
    {
        size = str.size;
        this->str = new char[size + 1];
        strcpy(this->str, str.str);
    }

    virtual ~String()
    {
        delete[] str;
    }

    String& operator=(const String& str)
    {
        if (this == &str)
        {
            return *this;
        }
        char* temp = new char[str.size + 1];
        strcpy(temp, str.str);
        delete[] this->str;
        this->str = temp;
        size = str.size;
        return *this;
    }

    int getLength() const
    {
        return strlen(str);
    }

    const char* getStr() const
    {
        return str;
    }

    void clear()
    {
        str[0] = '\0';
    }

    void resize(int newSize)
    {
        if (newSize < 0) return;
        char* temp = new char[newSize + 1];
        strncpy(temp, str, newSize);
        temp[newSize] = '\0';
        delete[] str;
        str = temp;
        size = newSize;
    }

    String operator+(const String& str) const
    {
        String result(getLength() + str.getLength());
        strcpy(result.str, this->str);
        strcat(result.str, str.str);
        return result;
    }

    String& operator+=(const String& str)
    {
        *this = *this + str;
        return *this;
    }

    bool operator==(const String& str) const
    {
        return strcmp(this->str, str.str) == 0;
    }

    bool operator!=(const String& str) const
    {
        return !(*this == str);
    }

    void write();
    void show() const;
};

inline void String::write()
{
    char buff[1000] = "";
    cout << "Write string: ";
    cin.getline(buff, 1000);
    int len = strlen(buff);
    if (len > size)
    {
        resize(len);
    }
    strcpy(str, buff);
}

inline void String::show() const
{
    cout << str << endl;
}