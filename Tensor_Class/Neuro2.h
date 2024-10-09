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
	std::vector < std::vector<float >> vector_Layers; //������ �����
	std::vector < std::vector<float >> w;	          //������� �����
	std::vector <float> layerSoftMax;
	std::vector <float> loss;
	std::vector <float> dEdH;

	void Layer();
	int size_in_layer;//����� ����������� �����
	float func(float x);// �-��� ���������
	void gener_w(float matO, float md);//��������� �����
	void softMax();
	void crossEntropy(std::vector<int> lable,int i_z);
	void backprop(std::vector<int> lable);
	void Layer_softMax();
};

