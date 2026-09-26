#pragma once
#include "String.h"

enum class ReservoirType
{
	Unknown, Ocean, Sea, Lake, River, Pond, Swamp, Puddle
};

class Reservoir
{
	ReservoirType type;
	double width;
	double length;
	double depth;
	String name;

public:

	Reservoir()
	{
		type = ReservoirType::Unknown;
		name = "None";
		width = 0;
		length = 0;
		depth = 0;
	}

	Reservoir(ReservoirType type, const String& name, double width, double length, double depth)
	{
		this->type = type;
		this->name = name;
		this->width = width;
		this->length = length;
		this->depth = depth;
	}

	Reservoir(const Reservoir& obj)
	{
		type = obj.type;
		width = obj.width;
		length = obj.length;
		depth = obj.depth;
		name = obj.name;
	}

	double getObiem();
	double getPloshad();
	void printAll();
	String getType()
	{
		switch (type)
		{
		case ReservoirType::Unknown:return "Unknown";
			break;
		case ReservoirType::Ocean:return "Ocean";
			break;
		case ReservoirType::Sea:return "Sea";
			break;
		case ReservoirType::Lake:return "Lake";
			break;
		case ReservoirType::River:return "River";
			break;
		case ReservoirType::Pond:return "Pond";
			break;
		case ReservoirType::Swamp:return "Swamp";
			break;
		case ReservoirType::Puddle:return "Puddle";
			break;
		default:
			return "Unknown"; break;
		}
	}
	static void deleteReservoir(Reservoir*& reservoirs, int& size, int ind);
	static void copyReservoir(Reservoir*& reservoirs, int& size, int ind);
};

void Reservoir::copyReservoir(Reservoir*& reservoirs, int& size, int ind)
{
	if (ind < 0 or ind > size)
	{
		ind = size-1;
	}
	Reservoir* arr0 = new Reservoir[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		arr0[i] = reservoirs[i];
	}
	arr0[size] = reservoirs[ind];
	delete[] reservoirs;
	reservoirs = arr0;
	size += 1;
}

void Reservoir::deleteReservoir(Reservoir*& reservoirs, int& size, int ind)
{
	if (size == 1)
	{
		size = 0;
		delete[] reservoirs;
		reservoirs = nullptr;
		return;
	}
	else if (ind < 0 or ind > size)
	{
		ind = size;
	}
	Reservoir* arr0 = new Reservoir[size - 1];
	int i2 = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (i != ind)
		{
			arr0[i2] = reservoirs[i];
			i2 += 1;
		}
	}
	delete[] reservoirs;
	reservoirs = arr0;
	size -= 1;
}

double Reservoir::getObiem()
{
	return width * length * depth;
}

double Reservoir::getPloshad()
{
	return width * length;
}

void Reservoir::printAll()
{
	cout << name << " - " << getType() << "\nWidth: " << width << "\nLength: " << length << "\nDepth: " << depth << endl;
	cout << endl;
	cout << "============================" << endl;
	cout << endl;
}
