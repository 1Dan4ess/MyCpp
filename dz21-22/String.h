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
	friend ostream& operator<<(ostream& out, const String& f);
	friend istream& operator>>(istream& in, String& f);
};

ostream& operator<<(ostream& out, const String& f)
{
	out << f.str;
	return out;
}

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