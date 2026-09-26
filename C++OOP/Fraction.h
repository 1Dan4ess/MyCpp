#pragma once
using namespace std;

class Fraction
{
	int numeration;
	int denominator;
	int nsd()
	{
		return 1;
	}
public:

	Fraction() : Fraction(0, 1) {}
	Fraction(int num, int den) : numeration(num), denominator(den)
	{
		int n = nsd();
		if (n != 1)
		{
			numeration /= n;
			denominator /= n;
		}
	}


	void show() const
	{
		cout << numeration << "/" << denominator << endl;
	}

	Fraction operator + (Fraction f)
	{
		int num = numeration * f.denominator + denominator * f.numeration;
		int den = denominator * f.denominator;
		return Fraction(num, den);
	}

	Fraction operator - ()
	{
		return Fraction(-numeration, denominator);
	}

	Fraction operator ++ () //prefix
	{
		return Fraction(numeration + denominator, denominator);
	}

	Fraction operator ++ (int) //postfix
	{
		Fraction temp = *this;
		numeration = numeration + denominator;
		return temp;
	}

	void operator +=(Fraction f)
	{
		*this = *this + f;
	}

	Fraction operator+(int n)
	{
		return Fraction(numeration + n * denominator, denominator);
	}

	Fraction operator!()
	{
		return Fraction(denominator, numeration);
	}

	bool operator<(Fraction f)
	{
		return (double)numeration / denominator < (double)f.numeration / f.denominator;
	}

	bool operator==(Fraction f)
	{
		return numeration == f.numeration and denominator == f.denominator;
	}

	bool operator!=(Fraction f)
	{
		return numeration != f.numeration or denominator != f.denominator;
	}

	bool operator&&(Fraction f)
	{
		return numeration != 0 and f.numeration != 0;
	}

	void operator()(int a, int b)
	{
		numeration = a;
		denominator = b;
	}

	int operator[](const char* name)
	{
		if (strcmp(name, "num") == 0)
		{
			return numeration;
		}
		if (strcmp(name, "den") == 0)
		{
			return denominator;
		}
	}

	friend ostream& operator<<(ostream& out, const Fraction& f);
	friend istream& operator>>(istream& in, Fraction& f);
};

Fraction operator + (int n, Fraction f2)
{
	return f2 + n;
}

ostream& operator<<(ostream& out, const Fraction& f)
{
	out << f.numeration << "/" << f.denominator << endl;
	return out;
}
istream& operator>>(istream& in, Fraction& f)
{
	cout << "Num: ";
	in >> f.numeration;
	cout << "Den: ";
	in >> f.denominator;
	return in;
}