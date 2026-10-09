#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class String
{
	int size;
	char* str;

public:
	static int count;

	static int getcount()
	{
		return count;
	}

	String() : String(80) {}

	explicit String(int s)
	{
		size = s < 0 ? 0 : s;
		str = new char[size + 1];
		str[0] = '\0';
		count++;
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
		count++;
	}

	String(const String& st)
	{
		size = st.size;
		if (st.str != nullptr)
		{
			str = new char[size + 1];
			strcpy(str, st.str);
		}
		else
		{
			str = new char[1];
			str[0] = '\0';
		}
		count++;
	}

	~String()
	{
		delete[] str;
		count--;
	}

	String& operator=(const String& st)
	{
		if (this == &st)
		{
			return *this;
		}

		delete[] str;

		size = st.size;
		if (st.str != nullptr)
		{
			str = new char[size + 1];
			strcpy(str, st.str);
		}
		else
		{
			str = new char[1];
			str[0] = '\0';
		}

		return *this;
	}

	void resize(int newSize)
	{
		if (newSize < 0) return;

		char* temp = new char[newSize + 1];
		temp[0] = '\0';

		if (str != nullptr)
		{
			strncpy(temp, str, newSize);
			temp[newSize] = '\0';
			delete[] str;
		}

		str = temp;
		size = newSize;
	}

	void write();
	void show() const;
	String operator-();
	String& operator++();
	String& operator--();
	String operator+(const String& obj);
	String operator-(const String& obj);
	String operator*(int n);
	String operator/(int n);
	String& operator+=(const String& obj);
	String& operator-=(const String& obj);
	String& operator*=(int n);
	String& operator/=(int n);
	String operator!();
	bool operator>(const String& obj);
	bool operator<(const String& obj);
	bool operator>=(const String& obj);
	bool operator<=(const String& obj);
	bool operator==(const String& obj);
	bool operator!=(const String& obj);
	bool operator&&(const String& obj);
	char& operator()(int index);
	char& operator[](int index);

	friend ostream& operator<<(ostream& out, const String& obj);
	friend istream& operator>>(istream& in, String& obj);
};

void String::write()
{
	char buff[1000];
	cout << "Write string: ";
	cin.getline(buff, 1000);

	int len = strlen(buff);
	if (len > size)
	{
		delete[] str;
		str = new char[len + 1];
		size = len;
	}

	strcpy(str, buff);
}

void String::show() const
{
	if (str != nullptr)
	{
		cout << str << endl;
	}
}

int String::count = 0;

String String::operator-()
{
	String str2(*this);
	for (int i = 0; str2.str[i] != '\0'; i++)
	{
		str2.str[i] = -str2.str[i];
	}
	return str2;
}

String& String::operator++()
{
	int len = strlen(str);
	if (len == 0)
	{
		return *this;
	}
	char* str2 = new char[len + 2];
	strcpy(str2, str);
	str2[len] = str[len - 1];
	str2[len + 1] = '\0';
	delete[] str;
	str = str2;
	size = len + 1;
	return *this;
}

String& String::operator--()
{
	int len = strlen(str);
	str[len - 1] = '\0';
	size = len - 1;
	return *this;
}

String String::operator+(const String& obj)
{
	char* str2 = new char[strlen(str)+strlen(obj.str)+1];
	strcpy(str2, str);
	strcat(str2, obj.str);
	String strf(str2);
	delete[] str2;
	return strf;
}

String String::operator-(const String& obj)
{
	char* str2 = new char[strlen(str) + 1];
	int size2 = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		bool found = false;
		for (int k = 0; obj.str[k] != '\0'; k++)
		{
			if (str[i] == obj.str[k])
			{
				found = true;
				break;
			}
		}
		if (found == false)
		{
			str2[size2] = str[i];
			size2++;
		}
	}
	str2[size2] = '\0';
	String result(str2);
	delete[] str2;
	return result;
}

String String::operator*(int n)
{
	int len = strlen(str);
	char* str2 = new char[len * n + 1];
	str2[0] = '\0';
	for (int i = 0; i < n; i++)
	{
		strcat(str2, str);
	}
	String result(str2);
	delete[] str2;
	return result;
}

String String::operator/(int n)
{
	String str2(*this);
	int len = strlen(str)/n;
	str2.str[len] = '\0';
	str2.size = len;
	return str2;
}

String& String::operator+=(const String& obj)
{
	*this = *this + obj;
	return *this;
}

String& String::operator-=(const String& obj)
{
	*this = *this - obj;
	return *this;
}

String& String::operator*=(int n)
{
	*this = *this * n;
	return *this;
}

String& String::operator/=(int n)
{
	*this = *this / n;
	return *this;
}

String String::operator!()
{
	return -(*this);
}

bool String::operator>(const String& obj)
{
	return strcmp(str, obj.str) > 0;
}

bool String::operator<(const String& obj)
{
	return strcmp(str, obj.str) < 0;
}

bool String::operator>=(const String& obj)
{
	return strcmp(str, obj.str) >= 0;
}

bool String::operator<=(const String& obj)
{
	return strcmp(str, obj.str) <= 0;
}

bool String::operator==(const String& obj)
{
	return strcmp(str, obj.str) == 0;
}

bool String::operator!=(const String& obj)
{
	return !(*this == obj);
}

bool String::operator&&(const String& obj)
{
	return strlen(str) > 0 and strlen(obj.str) > 0;
}

char& String::operator()(int index)
{
	return str[index];
}

char& String::operator[](int index)
{
	return str[index];
}

ostream& operator<<(ostream& out, const String& obj)
{
	out << obj.str;
	return out;
}

istream& operator>>(istream& in, String& obj)
{
	char buff[500];
	in.getline(buff, 500);
	obj = String(buff);
	return in;
}