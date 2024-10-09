#pragma once
#include "tensor.h"
#include "dataset.h"

class Neuro2
{
public:
	Neuro2(std::vector<unsigned> numNeurones, Dataset &inData);
	void printLayers();
	void print_w();
	void printSoftMax();
	void printLoss();
	void print_dEdH();


private:
	std::vector < std::vector<float >> vector_Layers; //вектор слоев
	std::vector < std::vector<float >> w;	          //матрица весов
	std::vector <float> layerSoftMax;
	std::vector <float> loss;
	std::vector <float> dEdH;

	void Layer();
	int size_in_layer;//потом понадобится вроде
	float func(float x);// ф-ция активации
	void gener_w(float matO, float md);//генератор весов
	void softMax();
	void crossEntropy(std::vector<int> lable,int i_z);
	void backprop(std::vector<int> lable);
	void Layer_softMax();
};

