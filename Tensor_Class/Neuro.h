#pragma once
#include "tensor.h"
#include "Layer.h"

class Neuro
{
public:
	Neuro(unsigned numLayers, std::vector<unsigned> numNeurones, Ten3D ten);
	void step(std::vector<float> weights, float func);
	float func(float e);
	//void printA();

private:
	std::vector<Layer*> A;
	std::vector<float> weights;
	Layer* straight1;	//прямой ход
};

