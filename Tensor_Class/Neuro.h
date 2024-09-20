#pragma once
#include "tensor.h"
#include "Layer.h"

class Neuro
{
public:
	Neuro(unsigned numLayers, std::vector<unsigned> numNeurones, Ten3D ten);


private:
	std::vector<Layer*> A;


};

