#pragma once
#include "tensor.h"
#include "Layer.h"

class Neuro
{
public:
	Neuro(std::vector<unsigned> numNeurones, Ten3D ten);
	float func(float e);
	void step(std::vector<float> weights, float func(float e));//��� �� ���� � ����
	void printA();

private:
	std::vector<Layer> A;
	std::vector<float> weights;
	void straight( int index_1, int index_2, std::vector<Layer> A, std::vector<float> weights, float func(float e));





};

