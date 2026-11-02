#pragma once
#include<iostream>
#include <cstdlib>
#include"List.h"
#include"BTree.h"
#include <fstream>
using namespace std;

class Protocol
{
	string number;
	string date;
	int sum;
	bool isPay = false;

public:
	void pay()
	{
		isPay = true;
	}

	string getNumber()
	{
		return number;
	}

	void input()
	{
		cout << "Номер: ";
		cin >> number;
		cout << "Дата: ";
		cin >> date;
		cout << "Сума: ";
		cin >> sum;
	}

	void print()
	{
		cout << "Номер: " << number << endl;
		cout << "Дата: " << date << endl;
		cout << "Сума: " << sum << endl;
		if (isPay)
		{
			cout << "Сплачено" << endl;
		}
		else
		{
			cout << "Не сплачено" << endl;
		}
		cout << endl;
	}

	//friend ostream& operator<<(ostream& out, const Protocol& p);
	//friend istream& operator>>(istream& in, Protocol& f);
	friend class BasePolice;
};


class BasePolice
{
	BTree<string, List<Protocol*>> base;

	static void printList(List<Protocol*>& list)
	{
		for (size_t i = 0; i < list.getSize(); i++)
		{
			list[i]->print();
		}
	}

	static void saveList(List<Protocol*>& list, ofstream& out)
	{
		for (size_t i = 0; i < list.getSize(); i++)
		{
			Protocol* p = list[i];
			out << p->number << endl;
			out << p->date << endl;
			out << p->sum << endl;
			out << p->isPay << endl;
			out << endl;
		}
	}

public:

	void addProtocol();
	void print();
	void print(string number);
	void print(string number1, string number2);
	void save();
	void load();
	void pay();
};

void BasePolice::addProtocol()
{
	system("cls");
	Protocol* p = new Protocol;
	cout << "Новий протокол: " << endl;
	p->input();
	List<Protocol*>* l = base.getValue(p->getNumber());
	if (l)
	{
		l->push_back(p);
	}
	else
	{
		List<Protocol*> newList;
		newList.push_back(p);
		base.push_r(p->getNumber(), newList);
	}
}

void BasePolice::print(string number)
{
	system("cls");
	List<Protocol*>* list = base.getValue(number);
	if (list == nullptr)
	{
		cout << "Немає номеру" << endl;
		return;
	}
	for (size_t i = 0; i < list->getSize(); i++)
	{
		(*list)[i]->print();
	}
}

void BasePolice::print()
{
	system("cls");
	base.for_each(printList);
}

void BasePolice::print(string number1, string number2)
{
	system("cls");
	if (number1 > number2)
	{
		string temp = number1;
		number1 = number2;
		number2 = temp;
	}
	base.for_each(number1, number2, printList);
}

void BasePolice::save()
{
	ofstream out("police.txt");
	if (!out.is_open())
	{
		cout << "Не вдалося відкрити файл" << endl;
		return;
	}
	base.for_each(saveList, out);
	out.close();
}

void BasePolice::load()
{
	ifstream in("police.txt");

	if (!in.is_open())
	{
		cout << "Не вдалося відкрити файл" << endl;
		return;
	}
	Protocol p;
	while (in >> p.number >> p.date >> p.sum >> p.isPay)
	{
		p.print();
	}
	in.close();
}

void BasePolice::pay()
{
	system("cls");
	string num;
	cout << "Номер для оплати: ";
	cin >> num;
	List<Protocol*>* list = base.getValue(num);
	if (list == nullptr)
	{
		cout << "Немає номера" << endl;
		return;
	}
	for (size_t i = 0; i < list->getSize(); i++)
	{
		cout << "#" << i + 1 << endl;
		(*list)[i]->print();
	}
	int choice;
	cout << "Виберіть протокол: ";
	cin >> choice;
	(*list)[choice - 1]->pay();
}