#pragma once
#include "tensor.h"

class Dataset
{
public:
	Dataset(std::string name);

	void printData(char mode);
	void addData(Ten3D& value);
	void importMnist(std::string img,std::string label);
	
private:
	std::vector<Ten3D> img;
	std::vector<int> label;
	std::string name;

};