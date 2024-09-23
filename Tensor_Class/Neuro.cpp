#include "Neuro.h"

Neuro::Neuro(std::vector<unsigned> numNeurones, Ten3D ten)
{
	/*if (numNeurones.size() != numLayers) 
		throw std::invalid_argument("кол-во слоев != размеру вектора");*/

	//возможно сделать проверку на первый элемент вектора numNeurones 
	// и размер первого слоя в Ten3D ten

	
	A.reserve(numNeurones.size());//вектор обьектов класса Layer
	
	for (int i = 0; i < numNeurones.size(); i++)
	{
		if(i==0)
			A.emplace_back(ten, 1);//хард исправить
		else
			A.emplace_back(numNeurones[i]);//хард исправить
	}
}

void Neuro::step(std::vector<float> weights, float func(float e))
{
	
	for (int i = 0; i < A.size() - 1; i++)
	{
		straight(i, i + 1, A, weights, func);
	}
}

float Neuro::func(float e)
{
	return e;//позже изменить на норм функцию
}

void Neuro::printA()
{
	for(int i=0;i<A.size();i++)
	{
		std::cout << A[i].getSize() << std::endl;
	}
}

void Neuro::straight(int index_1, int index_2, std::vector<Layer> A, std::vector<float> weights, float func(float e))
{
	for (int i = 0; i < A[index_2].getSize(); i++) {
		float sum = 0;
		for (int j = 0; j < A[index_1].getSize(); j++)
			sum += A[index_1].getNeurones(j) * weights[i * A[index_1].getSize() + j];
		A[index_2].setNeurones(i, func(sum));
	}
}

