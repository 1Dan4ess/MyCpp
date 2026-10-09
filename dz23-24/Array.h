#pragma once
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <compare>

using namespace std;

class Array
{
    int* arr = nullptr;
    int size = 0;

public:

    Array();

    explicit Array(int s);

    Array(const Array& obj);

    Array& operator=(const Array& obj);

    ~Array();

    void create(int s);
    void setRand();
    void show() const;
    void add(const int& value);
    void remove(int index);
    void insert(const int& value, int index);
    void sort();
    void reverse();
    void clear();
    void resize(int newSize);
    void fill(const int& value);
    int getSize() const;
    int countValue(const int& value) const;
    int findValue(const int& value) const;
    int get(int index) const;
    void set(int index, const int& value);
    bool contains(const int& value) const;

    int& operator[](int index);
    Array operator+();
    Array operator-();
    Array& operator++();
    Array& operator--();
    Array operator+(const Array& obj);
    Array operator-(const Array& obj);
    Array& operator+=(const Array& obj);
    Array& operator-=(const Array& obj);
    Array operator*(const Array& obj);
    Array operator/(const Array& obj);
    Array& operator*=(const Array& obj);
    Array& operator/=(const Array& obj);
    Array operator!();
    bool operator>(const Array& obj);
    bool operator<(const Array& obj);
    bool operator>=(const Array& obj);
    bool operator<=(const Array& obj);
    bool operator==(const Array& obj);
    bool operator!=(const Array& obj);
    bool operator&&(const Array& obj);
    int& operator()(int index);

    friend ostream& operator<<(ostream& out, const Array& obj);
    friend istream& operator>>(istream& in, Array& obj);
};

Array::Array() : arr(nullptr), size(0)
{
}

Array::Array(int s)
{
    create(s);
}

Array::Array(const Array& obj)
{
    size = obj.size;

    arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
}

Array& Array::operator=(const Array& obj)
{
    if (this == &obj)
    {
        return *this;
    }

    delete[] arr;

    size = obj.size;
    arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }

    return *this;
}

Array::~Array()
{
    delete[] arr;
}

void Array::create(int s)
{
    if (s < 0)
    {
        return;
    }

    size = s;
    arr = new int[size];
}

void Array::setRand()
{
    int minValue = 0;
    int maxValue = 100;

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (maxValue - minValue + 1) + minValue;
    }
}

void Array::show() const
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void Array::add(const int& value)
{
    int* temp = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }

    temp[size] = value;

    delete[] arr;

    size++;
    arr = temp;
}

void Array::remove(int index)
{
    if (index < 0 || index >= size)
    {
        return;
    }

    int* temp = new int[size - 1];

    for (int i = 0; i < index; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = index; i < size - 1; i++)
    {
        temp[i] = arr[i + 1];
    }

    delete[] arr;

    size--;
    arr = temp;
}

void Array::insert(const int& value, int index)
{
    if (index < 0 || index > size)
    {
        return;
    }

    int* temp = new int[size + 1];

    for (int i = 0; i < index; i++)
    {
        temp[i] = arr[i];
    }

    temp[index] = value;

    for (int i = index + 1; i <= size; i++)
    {
        temp[i] = arr[i - 1];
    }

    delete[] arr;

    size++;
    arr = temp;
}

void Array::sort()
{
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

void Array::reverse()
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);
    }
}

void Array::clear()
{
    delete[] arr;

    arr = nullptr;
    size = 0;
}

void Array::resize(int newSize)
{
    if (newSize < 0)
    {
        return;
    }

    int limit;

    if (newSize < size)
    {
        limit = newSize;
    }
    else
    {
        limit = size;
    }

    int* temp = new int[newSize];

    for (int i = 0; i < limit; i++)
    {
        temp[i] = arr[i];
    }

    delete[] arr;

    size = newSize;
    arr = temp;
}

void Array::fill(const int& value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = value;
    }
}

int Array::getSize() const
{
    return size;
}

int Array::countValue(const int& value) const
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            count++;
        }
    }

    return count;
}

int Array::findValue(const int& value) const
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }

    return -1;
}

int Array::get(int index) const
{
    if (index < 0 || index >= size)
    {
        return 0;
    }

    return arr[index];
}

void Array::set(int index, const int& value)
{
    if (index < 0 || index >= size)
    {
        return;
    }

    arr[index] = value;
}

bool Array::contains(const int& value) const
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return true;
        }
    }

    return false;
}

int& Array::operator[](int index)
{
    assert(index >= 0 && index < size);
    return arr[index];
}

Array Array::operator-()
{
    Array arr2(*this);
    for (size_t i = 0; i < size; i++)
    {
        arr2.arr[i] = -arr2.arr[i];
    }
    return arr2;
}

Array& Array::operator++()
{
    resize(size + 1);
    return *this;
}
Array& Array ::operator--()
{
    resize(size - 1);
    return *this;
}
Array Array::operator+(const Array& obj)
{
    Array arr2(size + obj.size);
    for (int i = 0; i < size; i++)
    {
        arr2.arr[i] = arr[i];
    }
    for (int i = 0; i < obj.size; i++)
    {
        arr2.arr[size + i] = obj.arr[i];
    }
    return arr2;
}
Array& Array::operator+=(const Array& obj)
{
    *this = *this + obj;
    return *this;
}
Array Array::operator-(const Array& obj)
{
    Array arr2(*this);
    if (obj.size >= arr2.size)
    {
        arr2.clear();
    }
    else
    {
        arr2.resize(arr2.size - obj.size);
    }
    return arr2;
}
Array& Array::operator-=(const Array& obj)
{
    if (obj.size >= size)
    {
        clear();
    }
    else
    {
        resize(size - obj.size);
    }
    return *this;
}
Array Array::operator*(const Array& obj)
{
    if (size >= obj.size)
    {
        Array arr2(*this);
        for (size_t i = 0; i < obj.size; i++)
        {
            arr2[i] = arr[i] * obj.arr[i];
        }
        return arr2;
    }
    else if (size < obj.size)
    {
        Array arr2(obj);
        for (size_t i = 0; i < size; i++)
        {
            arr2.arr[i] = arr[i] * obj.arr[i];
        }
        return arr2;
    }
}
Array Array::operator/(const Array& obj)
{
    if (size >= obj.size)
    {
        Array arr2(*this);
        for (size_t i = 0; i < obj.size; i++)
        {
            arr2[i] = arr[i] / obj.arr[i];
        }
        return arr2;
    }
    else if (size < obj.size)
    {
        Array arr2(obj);
        for (size_t i = 0; i < size; i++)
        {
            arr2.arr[i] = arr[i] / obj.arr[i];
        }
        return arr2;
    }
}
Array& Array::operator*=(const Array& obj)
{
    *this = *this*obj;
    return *this;
}
Array& Array::operator/=(const Array& obj)
{
    *this = *this/obj;
    return *this;
}
Array Array::operator!()
{
    return -(*this);
}
bool Array::operator>(const Array& obj)
{
    return size > obj.size;
}
bool Array::operator<(const Array& obj)
{
    return size < obj.size;
}
bool Array::operator>=(const Array& obj)
{
    return size >= obj.size;
}
bool Array::operator<=(const Array& obj)
{
    return size <= obj.size;
}
bool Array::operator==(const Array& obj)
{
    return size == obj.size;
}
bool Array::operator!=(const Array& obj)
{
    return !(*this == obj);
}
bool Array::operator&&(const Array& obj)
{
    return size != 0 && obj.size != 0;
}
int& Array::operator()(int index)
{
    assert(index >= 0 && index < size);
    return arr[index];
}
ostream& operator<<(ostream& out, const Array& obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        out << obj.arr[i] << " ";
    }
    return out;
}
istream& operator>>(istream& in, Array& obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        in >> obj.arr[i];
    }
    return in;
}