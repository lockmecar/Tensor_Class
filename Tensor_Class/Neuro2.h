#pragma once
#include "tensor.h"

class Neuro2
{
public:
	Neuro2(std::vector<unsigned> numNeurones, Ten3D ten, std::vector<int> lable);
	void printLayers();
	void print_w();
	void printSoftMax();
	void printLoss();

private:
	std::vector < std::vector<float >> vector_Layers; //вектор слоев
	std::vector < std::vector<float >> w;	          //матрица весов
	std::vector <float> layerSoftMax;
	std::vector <float> loss;

	void Layer();
	int size_in_layer;//потом понадобится вроде
	float func(float x);// ф-ция активации
	void gener_w(float matO, float md);//генератор весов
	void softMax();
	void crossEntropy(std::vector<int> lable,int i_z);

};

