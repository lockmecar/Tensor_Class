#include "Neuro.h"

Neuro::Neuro(unsigned numLayers, std::vector<unsigned> numNeurones, Ten3D ten)
{
	if (numNeurones.size() != numLayers) 
		throw std::invalid_argument("кол-во слоев != размеру вектора");

	A.reserve(numLayers);//вектор обьектов класса Layer

	Layer* straight1;//прямой ход

	for (int i = 0; i < numLayers; i++) 
	{
		if(i==0)
		{
			straight1 = new Layer(ten, 1);//захардил, позже исправить
		}
		else 
		{
			straight1 = new Layer(ten, 1);//захардил, позже исправить
		}

		A.push_back(straight1);
	}
}
 