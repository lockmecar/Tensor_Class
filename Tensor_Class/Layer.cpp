#include "Layer.h"


InLayer::InLayer(Ten3D A, char mode)
{
	if (mode=='n')//без свертки
	{
		InLayer::size = A.getSizeX() * A.getSizeY();
		listNeurones.resize(size);
		InLayer::listNeurones = A.matrix_to_vector();
		weights.resize(100);
	}
	else if (mode=='c')//свертка
	{
		InLayer::size = A.getSizeX() * A.getSizeY();
		listNeurones.resize(size);
		InLayer::listNeurones = A.matrix_to_vector();
		//+ добавить функцию свертки
	}
}


void InLayer::printNeurones() 
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->listNeurones[i] << std::endl;
	}
}

void InLayer::printWei()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->weights[i] << std::endl;
	}
}

std::vector<float> InLayer::getNeurones()
{
	return this->listNeurones;
}


int InLayer::getSize()
{
	return size;
}

void InLayer::genWeights(float matO, float md)
{
	
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(matO, md);
	for (int i = 0; i < weights.size(); i++) //iter????
	{
		weights[i] = distribution(generator);
	}
}
//
//void OutLayer::printNeurones()
//{
//	for (int i = 0; i < this->size; i++)
//	{
//		std::cout << this->listNeurones[i] << std::endl;
//	}
//}
//
//std::vector<float> OutLayer::getNeurones()
//{
//	return this->listNeurones;
//}
//
//void HideLayer::printNeurones()
//{
//	for (int i = 0; i < this->size; i++)
//	{
//		std::cout << this->listNeurones[i] << std::endl;
//	}
//}
//
//std::vector<float> HideLayer::getNeurones()
//{
//	return this->listNeurones;
//}
