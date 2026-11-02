#pragma once

template<class T>
class SharedPointer
{
	T* ptr;
	int* count = new int(0);

public:
	SharedPointer(T* p) : ptr(p) 
	{
		*count++;
	}
	~SharedPointer() 
	{
		if (count > 1)
		{
			count--;
			delete ptr;
		}
		else
		{
			delete *ptr;
			delete ptr;
		}
	}
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }
	SharedPointer(const SmartPointer& obj);
	SharedPointer& operator=(const SharedPointer& obj);
	SharedPointer(SharedPointer&& obj)
	{
		*count++;
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}
	SharedPointer& operator=(SharedPointer&& obj)
	{
		if (&obj == this)
		{
			return *this;
		}
		delete ptr;
		ptr = obj.ptr;
		obj.ptr = nullptr;
		return *this;
	}
};
