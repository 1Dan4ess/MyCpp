#pragma once
class String
{
	int size;
	char* string;
	char* str;
	

public:
	static int count;
	static int getcount()
	{
		return count;
	}

	//String(const char* str)
	//{

	//	size = strlen(str);
	//	this->str = new char[size + 1];
	//	strcpy(this->str, str);
	//}
	String resize()
	{
		size = 50;
		str = new char[size];
		return *this;
	}

	String() : String(80) {}
	String(int s)
	{
		size = s;
		string = new char[s+1];
		string[0] = '\0';
		count += 1;
	}
	String(char* buff)
	{
		size = strlen(buff);
		string = new char[size+1];
		strcpy(string, buff);
		cout << string << endl;
		count += 1;
	}
	~String()
	{
		delete[] string;
		count -= 1;
	}



	void write();
	void show();
};

void String::write()
{
	char buff[1000];
	cout << "Write string: ";
	cin.getline(buff, 1000);
	if (strlen(buff) > size)
	{
		delete[] string;
		string = new char[strlen(buff) + 1];
		size = strlen(buff);
	}
	strcpy(string, buff);
}
void String::show()
{
	cout << string << endl;
}

int String::count = 0;