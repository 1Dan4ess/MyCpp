#pragma once
#include <cstdlib>
#include <cstring>
#include"String.h"

enum class type { INT, DOUBLE, STRING };

class Var
{
	type type;
	void* val;
	char buff[100];

public:
	Var()
	{
		type = type::INT;
		val = new int(0);
	}
	Var(int val)
	{
		type = type::INT;
		this->val = new int(val);
	}
	Var(double val)
	{
		type = type::DOUBLE;
		this->val = new double(val);
	}
	Var(const char* val)
	{
		type = type::STRING;
		this->val = new String(val);
	}
	Var(String val)
	{
		type = type::STRING;
		this->val = new String(val);
	}
	~Var()
	{
		switch (type)
		{
		case type::INT:
			delete (int*)val;
			break;
		case type::DOUBLE:
			delete (double*)val;
			break;
		case type::STRING:
			delete (String*)val;
			break;
		default:
			break;
		}
	}
	Var(const Var& obj)
	{
		type = obj.type;
		switch (type)
		{
		case type::INT:
			val = new int(*(int*)obj.val);
			break;
		case type::DOUBLE:
			val = new double(*(double*)obj.val);
			break;
		case type::STRING:
			val = new String(*(String*)obj.val);
			break;
		default:
			break;
		}
	}
	Var& operator=(const Var& obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		switch (type)
		{
		case type::INT:
			delete (int*)val;
			break;
		case type::DOUBLE:
			delete (double*)val;
			break;
		case type::STRING:
			delete (String*)val;
			break;
		default:
			break;
		}
		type = obj.type;
		switch (type)
		{
		case type::INT:
			val = new int(*(int*)obj.val);
			break;
		case type::DOUBLE:
			val = new double(*(double*)obj.val);
			break;
		case type::STRING:
			val = new String(*(String*)obj.val);
			break;
		default:
			break;
		}
		return *this;
	}

	operator int() const;
	operator double() const;
	operator char*();
	void show() const;
	Var operator+(const Var& obj) const;
	Var operator-(const Var& obj) const;
	Var operator*(const Var& obj) const;
	Var operator/(const Var& obj) const;
	Var& operator+=(const Var& obj);
	Var& operator-=(const Var& obj);
	Var& operator*=(const Var& obj);
	Var& operator/=(const Var& obj);
	bool operator==(const Var& obj) const;
	bool operator!=(const Var& obj) const;
	bool operator<(const Var& obj) const;
	bool operator>(const Var& obj) const;
	bool operator<=(const Var& obj) const;
	bool operator>=(const Var& obj) const;
};

bool Var::operator<=(const Var& obj) const
{
	return !(*this > obj);
}

bool Var::operator>=(const Var& obj) const
{
	return !(*this < obj);
}

bool Var::operator>(const Var& obj) const
{
	switch (type)
	{
	case type::INT:
		return *(int*)val > (int)obj;

	case type::DOUBLE:
		return *(double*)val > (double)obj;

	case type::STRING:
	{
		Var temp = obj;
		return strcmp(((String*)val)->getStr(), (char*)temp) > 0;
	}
	default:
		break;
	}
}

bool Var::operator<(const Var& obj) const
{
	switch (type)
	{
	case type::INT:
		return *(int*)val < (int)obj;

	case type::DOUBLE:
		return *(double*)val < (double)obj;

	case type::STRING:
	{
		Var temp = obj;
		return strcmp(((String*)val)->getStr(), (char*)temp) < 0;
	}
	default:
		break;
	}
}

bool Var::operator!=(const Var& obj) const
{
	return !(*this == obj);
}

bool Var::operator==(const Var& obj) const
{
	switch (type)
	{
	case type::INT:
		return *(int*)val == (int)obj;

	case type::DOUBLE:
		return *(double*)val == (double)obj;

	case type::STRING:
	{
		Var temp = obj;
		return strcmp(((String*)val)->getStr(), (char*)temp) == 0;
	}
	default:
		break;
	}
}

Var& Var::operator+=(const Var& obj)
{
	*this = *this + obj;
	return *this;
}

Var& Var::operator-=(const Var& obj)
{
	*this = *this - obj;
	return *this;
}

Var& Var::operator*=(const Var& obj)
{
	*this = *this * obj;
	return *this;
}

Var& Var::operator/=(const Var& obj)
{
	*this = *this / obj;
	return *this;
}

Var Var::operator/(const Var& obj) const
{
	switch (type)
	{
	case type::INT:
		return *(int*)val / (int)obj;

	case type::DOUBLE:
		return *(double*)val / (double)obj;

	case type::STRING:
	{
		Var temp = obj;
		char* str1 = ((String*)val)->getStr();
		char* str2 = (char*)temp;
		char* result = new char[strlen(str1) + 1];
		int k = 0;
		for (int i = 0; str1[i] != '\0'; i++)
		{
			bool found = false;
			for (int j = 0; str2[j] != '\0'; j++)
			{
				if (str1[i] == str2[j])
				{
					found = true;
					break;
				}
			}
			if (!found)
			{
				result[k] = str1[i];
				k++;
			}
		}
		result[k] = '\0';
		Var res(result);
		delete[] result;
		return res;
	}
	default:
		break;
	}
}

Var Var::operator*(const Var& obj) const
{
	switch (type)
	{
	case type::INT:
		return *(int*)val * (int)obj;

	case type::DOUBLE:
		return *(double*)val * (double)obj;

	case type::STRING:
	{
		Var temp = obj;
		char* str1 = ((String*)val)->getStr();
		char* str2 = (char*)temp;
		char* result = new char[strlen(str1) + 1];
		int k = 0;
		for (int i = 0; str1[i] != '\0'; i++)
		{
			bool found = false;
			for (int j = 0; str2[j] != '\0'; j++)
			{
				if (str1[i] == str2[j])
				{
					found = true;
					break;
				}
			}
			if (found)
			{
				result[k] = str1[i];
				k++;
			}
		}
		result[k] = '\0';
		Var res(result);
		delete[] result;
		return res;
	}
	default:
		break;
	}
}

Var Var::operator-(const Var& obj) const
{
	switch (type)
	{
	case type::INT:
		return *(int*)val - (int)obj;

	case type::DOUBLE:
		return *(double*)val - (double)obj;

	case type::STRING:
	{
		return Var("");
	}
	default:
		break;
	}
}

Var Var::operator+(const Var& obj) const
{
	switch (type)
	{
	case type::INT:
		return *(int*)val + (int)obj;
	case type::DOUBLE:
		return *(double*)val + (double)obj;
	case type::STRING:
	{
		Var temp = obj;
		char* str1 = ((String*)val)->getStr();
		char* str2 = (char*)temp;
		char* result = new char[strlen(str1) + strlen(str2) + 1];
		strcpy(result, str1);
		strcat(result, str2);
		Var res(result);
		delete[] result;
		return res;
	}
	default:
		break;
	}
}

Var::operator double() const
{
	switch (type)
	{
	case type::INT:
		return *(int*)val;
	case type::DOUBLE:
		return *(double*)val;
	case type::STRING:
		return atof(((String*)val)->getStr());
	default:
		break;
	}
	return 0;
}

Var::operator char*()
{
	switch (type)
	{
	case type::INT:
		_itoa(*(int*)val, buff, 10);
		return buff;
	case type::DOUBLE:
		_gcvt(*(double*)val, 10, buff);
		return buff;
	case type::STRING:
		return ((String*)val)->getStr();
	}
	return buff;
}

Var::operator int() const
{
	switch (type)
	{
	case type::INT:
		return *(int*)val;
	case type::DOUBLE:
		return (int)*(double*)val;
	case type::STRING:
		return atoi(((String*)val)->getStr());
	default:
		break;
	}
	return 0;
}

void Var::show() const
{
	switch (type)
	{
	case type::INT:
		cout << *(int*)val << endl;;
		break;
	case type::DOUBLE:
		cout << *(double*)val << endl;
		break;
	case type::STRING:
		((String*)val)->show();
		break;
	default:
		break;
	}
}