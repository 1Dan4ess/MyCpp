#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Pet
{
	int age;
	string name;
	string type;
public:
	Pet(int age, string name, string type) : age(age), name(name), type(type) {}
	virtual int getAge()
	{
		return age;
	}
	virtual string getName()
	{
		return name;
	}
	virtual string getType()
	{
		return type;
	}
};


class Cat : public Pet
{
	string paroda;
	int catAge;
public:
	Cat(int age, string name, string paroda) : Pet(age, name, "Кіт"), paroda(paroda), catAge(age*5) {}
	string getParoda()
	{
		return paroda;
	}
	int getCatAge()
	{
		return catAge;
	}
};

class Dog : public Pet
{
	string command;
	bool fighting;
public:
	Dog(int age, string name, string command, bool fighting) : Pet(age, name, "Собака"), command(command), fighting(fighting) {}
	void getCommand()
	{
		cout << "Знає команду: " << command << endl;
	}
	string isFighting()
	{
		if (fighting)
		{
			return "Бойова";
		}
		else
		{
			return "Небойова";
		}
	}
};

class Parrot : public Pet
{
	string color;
	string phrase;
public:
	Parrot(int age, string name, string color, string phrase) : Pet(age, name, "Папуга"), color(color), phrase(phrase) {}
	string getVoice()
	{
		return phrase;
	}
	string getColor()
	{
		return color;
	}
};