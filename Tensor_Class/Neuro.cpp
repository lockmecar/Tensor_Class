#include "Neuro.h"

Neuro::Neuro(std::vector<unsigned> numNeurones, Ten3D ten)
{
	/*if (numNeurones.size() != numLayers) 
		throw std::invalid_argument("кол-во слоев != размеру вектора");*/

	//возможно сделать проверку на первый элемент вектора numNeurones 
	// и размер первого слоя в Ten3D ten

	
	A.reserve(numNeurones.size());//вектор обьектов класса Layer
	int mult=1;
	for (int i = 0; i < numNeurones.size(); i++)
	{
		if(i==0)
			A.emplace_back(ten, 1);//хард исправить
		else
			A.emplace_back(numNeurones[i]);//хард исправить
		mult *= numNeurones[i];
	}

	weights.reserve(mult);

}

void Neuro::step()
{
	
	for (int i = 0; i < A.size() - 1; i++)
	{
		straight(i, i + 1, A, weights);// возможно сюда добавить conv ход
	}
}

float Neuro::func(float e)
{
	return e;//позже изменить на норм функцию
}

void Neuro::printA()
{
	for (int i = 0; i < A.size()/3; i++)
	{
		for (int j = 0; j < A[i].getSize(); j++)
			std::cout << A[i].getNeurones(j) << '\t' << A[i+1].getNeurones(j) << '\t' << A[i+2].getNeurones(j) << std::endl;
	}
}

void Neuro::generWeights( int size, float matO, float md)
{
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(matO, md);
	for (int i = 0; i < size; i++) //iter????
		weights.push_back(distribution(generator));
}

void Neuro::printWei(std::vector<float> weights)
{
	for (int i = 0; i < weights.size(); i++)
		std::cout << weights[i] << std::endl;
}

std::vector<float> Neuro::getWeights()
{
	return  weights;
}

void Neuro::straight(int index_1, int index_2, std::vector<Layer> A, std::vector<float> weights)
{
	for (int i = 0; i < A[index_2].getSize(); i++) {
		float sum = 0;
		for (int j = 0; j < A[index_1].getSize(); j++)
			sum += A[index_1].getNeurones(j) * weights[i * A[index_1].getSize() + j];
		A[index_2].setNeurones(i, func(sum));
	}
}

