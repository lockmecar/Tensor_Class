#pragma once
#include "tensor.h"
#include "Layer.h"

class Neuro
{
public:
	Neuro(unsigned numLayers, std::vector<unsigned> numNeurones);


private:
	std::vector<Layer> A;


};

