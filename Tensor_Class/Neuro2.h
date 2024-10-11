#pragma once
#include "tensor.h"
#include "dataset.h"

class Neuro2
{
public:
	Neuro2(std::vector<unsigned> numNeurones, Dataset &inData);
	void printLayers();
	void print_w();
	void printError();

	void print_vector_backprop();


private:
	std::vector < std::vector<float >> vector_Layers; //вектор слоев
	std::vector < std::vector<float >> w;	          //матрица весов
	std::vector <float> layerSoftMax;
	std::vector < std::vector<float >> vector_backprop;


	float error;
	//void Layer();
	float func(float x);// ф-ция активации
	float funcPrime(float x);
	void gener_w(float matO, float md);//генератор весов
	//void softMax();
	void crossEntropy(std::vector<int> lable);
	void backprop(std::vector<int> lable);
	void Layer_softMax();

};


/*for (size_t i = 0; i < dE_dH.size(); i++)
		dE_dH[i] = -(lable[i] / vector_Layers[vector_Layers.size() - 1][i]);*/

