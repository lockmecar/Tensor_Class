#pragma once
#include "tensor.h"
#include "dataset.h"

class Neuro2
{
public:
	Neuro2(std::vector<unsigned> numNeurones, Dataset &inData);
	Neuro2(std::vector<unsigned> numNeurones, std::vector<float> debug);
	void printLayers();
	void print_w();
	void printError();
	void print_vector_backprop();
	void print_softMax();


private:
	std::vector < std::vector<float >> vector_Layers; //������ �����
	std::vector < std::vector<float >> w;	          //������� �����
	std::vector <double> layerSoftMax;
	std::vector < std::vector<double >> vector_backprop;


	float error;
	void Layer();
	double func(float x);// �-��� ���������
	float relu_derivative(float x);// �����������
	void gener_w(float matO, float md);//��������� �����
	void softMax();
	void crossEntropy(int indx_lable);
	void backprop(int indx_lable);
	void apdate(float alpha);//alpha ��� �������� ��������

};
