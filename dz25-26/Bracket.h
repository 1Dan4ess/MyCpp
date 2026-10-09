#pragma once
#include<iostream>
#include "Stack.h"
using namespace std;

class Bracket
{
	string expression;

public:
	Bracket(const string& exp) : expression(exp) {}
	string getResult();
};

string Bracket::getResult()
{
	Stack<char, 20> brackets;
	int i = 0;
	while (expression[i] != '\0')
	{
		switch (expression[i])
		{
		case ('{'): case ('('): case ('['):
			brackets.push(expression[i]);
			break;
		default:
			break;
		}


		switch (expression[i])
		{
		case '}':
			if (!brackets.isEmpty() && brackets.peek() == '{')
			{
				brackets.pop();
				break;
			}
			else
			{
				string res = "";
				for (int j = 0; j < i; j++)
				{
					res += expression[j];
				}
				cout << "Wrong bracket" << endl;
				return res;
			}
		case ')':
			if (!brackets.isEmpty() && brackets.peek() == '(')
			{
				brackets.pop();
				break;
			}
			else
			{
				string res = "";
				for (int j = 0; j < i; j++)
				{
					res += expression[j];
				}
				cout << "Wrong bracket" << endl;
				return res;
			}
		case ']':
			if (!brackets.isEmpty() && brackets.peek() == '[')
			{
				brackets.pop();
				break;
			}
			else
			{
				string res = "";
				for (int j = 0; j < i; j++)
				{
					res += expression[j];
				}
				cout << "Wrong bracket" << endl;
				return res;
			}
		default:
			break;
		}
		i += 1;
	}
	if (brackets.isEmpty())
	{
		cout << "Correct bracket" << endl;
		return expression;
	}
}