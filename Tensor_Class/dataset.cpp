#include "dataset.h"

Dataset::Dataset(std::string name)
{
	this->name = name;
}

void Dataset::printData()
{
	for (int i = 0; i < data.size(); i++)
	{
		this->data[i].print();
	}
}

void Dataset::addData(Ten3D& value)
{
	this->data.push_back(value);
}
