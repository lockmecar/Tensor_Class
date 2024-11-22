#pragma once
#include "tensor.h"

class Dataset
{
	friend class Neuro2;
public:
	Dataset(std::string name, int numButches, std::string img, std::string label);

	void printData(char mode);

//private:
	int numButches;
	std::vector<std::vector<Ten3D>> img;
	std::vector<std::vector<int>> label;
	std::string name;

};