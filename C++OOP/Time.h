#pragma once
class Time
{
	int hour;
	int minute;
	int second;

public:
	Time() : Time(0)
	{
		//hour = 0;
		//minute = 0;
		//second = 0;
		cout << "Constructor 0" << endl;
	}
	Time(int s) : Time(0, s)
	{
		//hour = 0;
		//minute = 0;
		//second = s;
		cout << "Constructor 1" << endl;
	}
	Time(int m, int s) : Time(0, m, s)
	{
		//hour = 0;
		//minute = m;
		//second = s;
		cout << "Constructor 2" << endl;
	}
	Time(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
		cout << "Constructor 3" << endl;
	}
};

