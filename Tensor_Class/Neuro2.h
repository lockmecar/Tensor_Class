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
	void init(Dataset& inData);

	//void print_vector_backprop();
	//void print_softMax();


private:
	std::vector < std::vector<float >> layers_t;		        // до ф-ции активации t = w (*) x
	std::vector < std::vector<double >> layers_h;		        // после ф-ции активации h = F(t)
	std::vector < std::vector<float >> weights;			        // матрица весов
	std::vector < std::vector<double >> back_layers_t;	        // хранит dE/dt
	std::vector < std::vector<double >> back_layers_h;	        // хранит dE/dh
	std::vector<std::vector<std::vector<float>>> back_layers_w; // хранит dE/dW

	float error;
	double func(float x);// ф-ция активации
	float relu(float x);
	double leaky_Relu(float x);
	float relu_derivative(float x);// производная
	void gener_w(float matO, float md); // генератор весов
	void softMax();
	void crossEntropy(int indx_lable);

	std::vector<std::vector<float>> transp(std::vector<std::vector<float>>&matrixA);
	std::vector<std::vector<float>> multi(const std::vector<std::vector<float>>& matrixA, const std::vector<std::vector<float>>& matrixB);

	void backprop(int indx_lable);
	//void apdate(float alpha);//alpha это скорость обучения

};
