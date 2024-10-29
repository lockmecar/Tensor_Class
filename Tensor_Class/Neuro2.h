#pragma once
#include "tensor.h"
#include "dataset.h"

class Neuro2
{
public:
	Neuro2(std::vector<unsigned> numNeurones, Dataset &inData);
	//Neuro2(std::vector<unsigned> numNeurones, std::vector<float> debug);
	void printLayersT();
	void printLayersH();
	void print_w();
	void printError();
	//void print_vector_backprop();
	//void print_softMax();


private:
	std::vector < std::vector<float >> layers_t;		// �� �-��� ��������� t = w (*) x
	std::vector < std::vector<double >> layers_h;		// ����� �-��� ��������� h = F(t)
	std::vector < std::vector<float >> weights;			// ������� �����
	std::vector < std::vector<double >> back_layers_t;	// �������� ��� t
	std::vector < std::vector<double >> back_layers_h;	// �������� ��� h

	float error;
	void init();
	double func(float x);// �-��� ���������
	float relu(float x);
	double leaky_Relu(float x);
	//float relu_derivative(float x);// �����������
	void gener_w(float matO, float md);//��������� �����
	void softMax();
	void crossEntropy(int indx_lable);
	//void backprop(int indx_lable);
	//void apdate(float alpha);//alpha ��� �������� ��������

};
