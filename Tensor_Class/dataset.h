#pragma once
#include "tensor.h"

class Dataset
{
public:
	Dataset(std::string name);

	void printData();
	void addData(Ten3D& value);

private:
	std::vector<Ten3D> data;
	std::string name;

};