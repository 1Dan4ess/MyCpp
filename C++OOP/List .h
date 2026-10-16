#pragma once
#include<initializer_list>
#include "Node.h"
using namespace std;


template<class T>
class List
{
	Node<T>* first;
	Node<T>* last;
	size_t size;
	Node<T>* getNode(size_t index) const;

public:
	List();
	List(initializer_list<T> list);
	List(const List& obj);
	List<T>& operator=(const List& obj);
	~List();

	void push_front(const T& value);
	void push_back(const T& value);
	void insert(const T& value, size_t index);

	void pop_front();
	void pop_back();
	void remove(size_t index);
	void erase(const T& value);
	void erase_if(bool(*predicate)(const T&));

	T& front() const;
	T& back() const;
	T at(size_t index) const;
	T& operator[](size_t index) const;

	void clear();
	void print() const;
	size_t getSize() const;

	size_t firstIndex(const T& value);
	size_t lastIndex(const T& value);

	List splice(size_t index1, size_t index2);
	List operator+(const List& list);
	void operator+=(const List& list);
};

template<class T>
Node<T>* List<T>::getNode(size_t index) const
{
	Node<T>* pos = nullptr;
	if (index < size / 2)
	{
		pos = first;
		for (size_t i = 0; i < index; i++)
		{
			pos = pos->next;
		}
	}
	else
	{
		pos = last;
		for (size_t i = 0; i < size - index - 1; i++)
		{
			pos = pos->prev;
		}
	}
	return pos;
}

template<class T>
List<T>::List() : first(nullptr), last(nullptr), size(0) {}

template<class T>
List<T>::List(initializer_list<T> list)
{
	for (T elem : list)
	{
		push_back(elem);
	}
}

template<class T>
List<T>::List(const List& obj)
{
	Node<T>* temp = obj.first;
	while (temp)
	{
		push_back(temp->value);
		temp = temp->next;
	}
}

template<class T>
List<T>& List<T>::operator=(const List& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	clear();
	Node<T>* temp = obj.first;
	while (temp)
	{
		push_back(temp->value);
		temp = temp->next;
	}
	return *this;
}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
void List<T>::push_front(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first->prev = newNode;
		first = newNode;
	}
	size++;
}

template<class T>
void List<T>::push_back(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last->next->prev = last;
		last = last->next;
	}
	size++;
}

template<class T>
void List<T>::insert(const T& value, size_t index)
{
	if (index > size)
	{
		return;
	}
	if (index == 0)
	{
		push_front(value);
	}
	else if (index == size)
	{
		push_back(value);
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* newNode = new Node<T>(value);
		newNode->next = pos->next;
		pos->next->prev = newNode;
		pos->next = newNode;
		newNode->prev = pos;
		size++;
	}
}

template<class T>
void List<T>::pop_front()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
		if (first != nullptr)
		{
			first->prev = nullptr;
		}
	}
}

template<class T>
void List<T>::pop_back()
{
	if (size > 0)
	{
		if (size == 1)
		{
			delete first;
			first = last = nullptr;
		}
		else
		{
			last = last->prev;
			delete last->next;
			last->next = nullptr;
		}
		size--;
	}
}

template<class T>
void List<T>::remove(size_t index)
{
	if (index == 0)
	{
		pop_front();
	}
	else if (index = size-1)
	{
		pop_back();
	}
	else
	{
		Node<T>* pos = getNode(index-1);
		Node<T>* temp = pos->next;
		pos->next = pos->next->next;
		pos->next->prev = pos;
		delete temp;
		size--;
	}
}

template<class T>
void List<T>::erase(const T& value)
{
	Node<T>* temp = first;
	int index = 0;
	while (temp)
	{
		if (temp->value == value)
		{
			remove(index);
		}
		temp = temp->next;
		index++;
	}
}

template<class T>
void List<T>::erase_if(bool(*predicate)(const T&))
{
	Node<T>* temp = first;
	int index = 0;
	while (temp)
	{
		if (predicate(temp->value))
		{
			remove(index);
		}
		temp = temp->next;
		index++;
	}
}

template<class T>
T& List<T>::front() const
{
	return first->value;
}

template<class T>
T& List<T>::back() const
{
	return last->value;
}

template<class T>
T List<T>::at(size_t index) const
{
	return getNode(index)->value;
}

template<class T>
T& List<T>::operator[](size_t index) const
{
	return getNode(index)->value;
}

template<class T>
void List<T>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
	last = nullptr;
}

template<class T>
void List<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
size_t List<T>::getSize() const
{
	return size;
}

template<class T>
size_t List<T>::firstIndex(const T& value)
{
	Node<T>* temp = first;
	size_t ind = 0;
	while (temp)
	{
		if (temp->value == value)
		{
			return ind;
		}
		else
		{
			temp = temp->next;
			ind++;
		}
	}
	return size;
}

template<class T>
size_t List<T>::lastIndex(const T& value)
{
	Node<T>* temp = first;
	size_t ind = 0;
	size_t lastind = ind;
	while (temp)
	{
		if (temp->value == value)
		{
			lastind = ind;
		}
		temp = temp->next;
		ind++;
	}
	return lastind;
}

template<class T>
List<T> List<T>::splice(size_t index1, size_t index2)
{
	List<T> res;
	Node<T>* a = getNode(index1);
	Node<T>* b = getNode(index2);
	if (a->prev)
	{
		a->prev->next = b->next;
	}
	else
	{
		first = b->next;
	}
	if (b->next)
	{
		b->next->prev = a->prev;
	}
	else
	{
		last = a->prev;
	}
	a->prev = nullptr;
	b->next = nullptr;
	res.first = a;
	res.last = b;
	res.size = index2 - index1 + 1;
	size -= res.size;
	return res;
}

template<class T>
List<T> List<T>::operator+(const List<T>& list)
{
	List<T> res = *this;
	res += list;
	return res;
}

template<class T>
void List<T>::operator+=(const List<T>& list)
{
	Node<T>* temp = list.first;
	for (size_t i = 0; i < list.size; i++)
	{
		push_back(temp->value);
		temp = temp->next;
	}
}