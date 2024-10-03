#pragma once
#include "tensor.h"

class Neuro2
{
public:
	Neuro2(std::vector<unsigned> numNeurones, Ten3D ten);
	void printLayers();
	void print_w();

private:
	std::vector < std::vector<float >> vector_Layers;
	std::vector < std::vector<float >> w;	//матрица весов
	void Layer();
	int size_in_layer;
	float func(float x);
	void gener_w(float matO, float md);
	

};

