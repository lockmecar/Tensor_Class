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
	void print_softMax();


private:
	std::vector < std::vector<float >> vector_Layers; //������ �����
	std::vector < std::vector<float >> w;	          //������� �����
	std::vector <float> layerSoftMax;
	std::vector < std::vector<float >> vector_backprop;


	float error;
	void Layer();
	float func(float x);// �-��� ���������
	float relu_derivative(float x);// �����������
	void gener_w(float matO, float md);//��������� �����
	void softMax();
	void crossEntropy(int indx_lable);
	void backprop(int indx_lable);
	void apdate(float alpha);//alpha ��� �������� ��������

};



