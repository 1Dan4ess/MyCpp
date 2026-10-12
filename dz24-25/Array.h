#pragma once
#include <iostream>
using namespace std;

template<class T>
class Array
{
    T* arr;
    int size;
    int capacity;
    int grow;

public:
    Array();
    explicit Array(int s, int g = 1);
    Array(const Array& obj);
    Array& operator=(const Array& obj);
    ~Array();

    int GetSize() const;
    void SetSize(int newSize, int newGrow = 1);
    int GetUpperBound() const;
    bool IsEmpty() const;
    void FreeExtra();
    void RemoveAll();

    T GetAt(int index) const;
    void SetAt(int index, const T& value);
    T& operator[](int index);
    const T& operator[](int index) const;

    void Add(const T& value);
    void Append(const Array& obj);
    T* GetData();
    void InsertAt(const T& value, int index);
    void RemoveAt(int index);
};

template<class T>
Array<T>::Array()
{
    arr = nullptr;
    size = 0;
    capacity = 0;
    grow = 1;
}

template<class T>
Array<T>::Array(int s, int g)
{
    SetSize(s, g);
}

template<class T>
Array<T>::Array(const Array& obj)
{
    size = obj.size;
    capacity = obj.capacity;
    grow = obj.grow;
    if (capacity > 0)
    {
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
}

template<class T>
Array<T>& Array<T>::operator=(const Array& obj)
{
    if (this == &obj)
    {
        return *this;
    }
    delete[] arr;
    arr = nullptr;
    size = obj.size;
    capacity = obj.capacity;
    grow = obj.grow;
    if (capacity > 0)
    {
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    return *this;
}

template<class T>
Array<T>::~Array()
{
    delete[] arr;
}

template<class T>
int Array<T>::GetSize() const
{
    return size;
}

template<class T>
void Array<T>::SetSize(int newSize, int newGrow)
{
    if (newGrow > 0)
    {
        grow = newGrow;
    }
    else
    {
        grow = 1;
    }
    if (newSize < size)
    {
        T* temp = nullptr;
        if (newSize > 0)
        {
            temp = new T[newSize];
        }
        for (int i = 0; i < newSize; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = newSize;
    }
    else if (newSize > capacity)
    {
        int newCapacity = capacity;
        while (newCapacity < newSize)
        {
            newCapacity += grow;
        }
        T* temp = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }
    for (int i = size; i < newSize; i++)
    {
        arr[i] = T();
    }
    size = newSize;
}

template<class T>
int Array<T>::GetUpperBound() const
{
    return size - 1;
}

template<class T>
bool Array<T>::IsEmpty() const
{
    return size == 0;
}

template<class T>
void Array<T>::FreeExtra()
{
    if (capacity == size)
    {
        return;
    }
    T* temp = nullptr;
    if (size > 0)
    {
        temp = new T[size];
    }
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    capacity = size;
}

template<class T>
void Array<T>::RemoveAll()
{
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}

template<class T>
T Array<T>::GetAt(int index) const
{
    return (*this)[index];
}

template<class T>
void Array<T>::SetAt(int index, const T& value)
{
    (*this)[index] = value;
}

template<class T>
T& Array<T>::operator[](int index)
{
    return arr[index];
}

template<class T>
const T& Array<T>::operator[](int index) const
{
    return arr[index];
}

template<class T>
void Array<T>::Add(const T& value)
{
    T temp = value;
    SetSize(size + 1, grow);
    arr[size - 1] = temp;
}

template<class T>
void Array<T>::Append(const Array& obj)
{
    int oldSize = size;
    int objSize = obj.size;
    SetSize(size + objSize, grow);
    for (int i = 0; i < objSize; i++)
    {
        arr[oldSize + i] = obj.arr[i];
    }
}

template<class T>
T* Array<T>::GetData()
{
    return arr;
}

template<class T>
void Array<T>::InsertAt(const T& value, int index)
{
    T temp = value;
    SetSize(size + 1, grow);
    for (int i = size - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = temp;
}

template<class T>
void Array<T>::RemoveAt(int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    SetSize(size - 1, grow);
}