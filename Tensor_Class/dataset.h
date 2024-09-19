#pragma once
#include "tensor.h"

class Dataset
{
public:
	Dataset(std::string name);

	void printData(char mode);
	void addData(Ten3D& value);
	void importMnist(std::string img,std::string label);
	void divideIntoBatches(int numberOfBatches);
	std::vector<Ten3D> getBatch(int batchId);

private:
	std::vector<Ten3D> img;
	std::vector<int> label;
	std::string name;
	int	numOfBatches;
	int numElemInBatch;

};