#include "Layer.h"


Layer::Layer(Ten3D A, char mode)
{
	if (mode=='n')//без свертки
	{
		Layer::size = A.getSizeX() * A.getSizeY();
		listNeurones.resize(size);
		Layer::listNeurones = A.matrix_to_vector();
		
		weights.resize(this->size);//параметризация????
	}
	else if (mode=='c')//свертка
	{
		Layer::size = A.getSizeX() * A.getSizeY();
		listNeurones.resize(size);
		Layer::listNeurones = A.matrix_to_vector();

		weights.resize(this->size);//параметризация????
		//+ добавить функцию свертки
	}
}

//
//void InLayer::printNeurones() 
//{
//	for (int i = 0; i < this->size; i++)
//	{
//		std::cout << this->listNeurones[i] << std::endl;
//	}
//}
//
//void InLayer::printWei()
//{
//	for (int i = 0; i < this->size; i++)
//		std::cout << this->weights[i] << std::endl;
//}
//
//std::vector<float> InLayer::getNeurones()
//{
//	return this->listNeurones;
//}
//
//
//int InLayer::getSize()
//{
//	return this->size;
//}
//
//void InLayer::genWeights(float matO, float md)
//{
//	
//	std::default_random_engine generator;
//	std::normal_distribution<double> distribution(matO, md);
//	for (int i = 0; i < weights.size(); i++) //iter????
//		weights[i] = distribution(generator);
//}
//
//void InLayer::setSize(unsigned num)
//{
//	size = num;
//}
//
//OutLayer::OutLayer(Ten3D A, char mode)
//{
//	if (mode == 'n')//без свертки
//	{
//		OutLayer::size = A.getSizeX() * A.getSizeY();
//		listNeurones.resize(size);
//		OutLayer::listNeurones = A.matrix_to_vector();
//		weights.resize(100);//параметризация????????????
//	}
//	else if (mode == 'c')//свертка
//	{
//		OutLayer::size = A.getSizeX() * A.getSizeY();
//		listNeurones.resize(size);
//		OutLayer::listNeurones = A.matrix_to_vector();
//		//+ добавить функцию свертки
//	}
//}
//
//void OutLayer::printNeurones()
//{
//	for (int i = 0; i < this->size; i++)
//		std::cout << this->listNeurones[i] << std::endl;
//}
//
//void OutLayer::printWei()
//{
//	for (int i = 0; i < this->size; i++)
//		std::cout << this->weights[i] << std::endl;
//}
//
//std::vector<float> OutLayer::getNeurones()
//{
//	return this->listNeurones;
//}
//
//int OutLayer::getSize()
//{
//	return size;
//}
//
//void OutLayer::genWeights(float matO, float md)
//{
//	std::default_random_engine generator;
//	std::normal_distribution<double> distribution(matO, md);
//	for (int i = 0; i < weights.size(); i++) //iter????
//		weights[i] = distribution(generator);
//}
//
//void OutLayer::setSize(unsigned num)
//{
//	size = num;
//}
//
//hideLayer::hideLayer(Ten3D A, char mode)
//{
//	if (mode == 'n')//без свертки
//	{
//		hideLayer::size = A.getSizeX() * A.getSizeY();
//		listNeurones.resize(size);
//		hideLayer::listNeurones = A.matrix_to_vector();
//		weights.resize(100);//параметризация???????????????
//	}
//	else if (mode == 'c')//свертка
//	{
//		hideLayer::size = A.getSizeX() * A.getSizeY();
//		listNeurones.resize(size);
//		hideLayer::listNeurones = A.matrix_to_vector();
//		//+ добавить функцию свертки
//	}
//}
//
//void hideLayer::printNeurones()
//{
//	for (int i = 0; i < this->size; i++)
//		std::cout << this->listNeurones[i] << std::endl;
//}
//
//void hideLayer::printWei()
//{
//	for (int i = 0; i < this->size; i++)
//		std::cout << this->weights[i] << std::endl;
//}
//
//std::vector<float> hideLayer::getNeurones()
//{
//	return this->listNeurones;
//}
//
//int hideLayer::getSize()
//{
//	return this->size;
//}
//
//void hideLayer::genWeights(float matO, float md)
//{
//	std::default_random_engine generator;
//	std::normal_distribution<double> distribution(matO, md);
//	for (int i = 0; i < weights.size(); i++) //iter????
//		weights[i] = distribution(generator);
//}
//
//void hideLayer::setSize(unsigned num)
//{
//	size = num;
//}
//
//void OutLayer::printNeurones()
//{
//	for (int i = 0; i < this->size; i++)
//		std::cout << this->listNeurones[i] << std::endl;
//}
