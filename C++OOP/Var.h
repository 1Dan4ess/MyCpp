#pragma once

enum class type {INT, DOUBLE, STRING};

class Var
{
	type type;
	void* val;

public:
	Var(int val)
	{
		
	}
	Var(double val)
	{

	}
	Var(String val)
	{

	}
};