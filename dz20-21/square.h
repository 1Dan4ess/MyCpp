#pragma once
#include <cmath>
class Square
{
public:
	static int count;

	template<class T>
	static T quadrangle(T a,T b)
	{
		count += 1;
		return a*b;
	}



	template<class T>
	static T square(T a)
	{
		count += 1;
		return a*a;
	}
	


	template<class T>
	static T romb(T a,T h)
	{
		count += 1;
		return a*h;
	}



	template<class T>
	static T triangle(T a, T h)
	{
		count += 1;
		return (a*h)/2;
	}

	template<class T>
	static T triangle(T a, T b, T c)
	{
		T x = (a + b + c)/2;
		count += 1;
		return sqrt(x*(x-b)*(x-a)*(x-c));
	}

	template<class T>
	static T triangle3(T a, T b, T ang)
	{
		T angle = ang* 3.14/180;
		count += 1;
		return a * b * sin(angle)/2;
	}



	static int getcount()
	{
		return count;
	}
};
int Square::count = 0;