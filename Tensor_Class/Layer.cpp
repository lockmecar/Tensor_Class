#include "Layer.h"


InLayer::InLayer(Ten3D A, char mode)
{
	if (mode=='n')
	{
		InLayer::size = A.getSizeX() * A.getSizeY();
		listNeurones.resize(size);
		InLayer::listNeurones = A.matrix_to_vector();
	}
	else if (mode=='c')
	{
		InLayer::size = A.getSizeX() * A.getSizeY();
		listNeurones.resize(size);
		InLayer::listNeurones = A.matrix_to_vector();
		//+ добавить функцию свертки
	}
}


void InLayer::printNeurones() 
{
	for (int i = 0; i < size; i++)
	{
		std::cout << listNeurones[i] << std::endl;
	}
}


//std::vector<float> InLayer::getNeurones()
//{
//	return listNeurones;//?
//}

int InLayer::getSize()
{
	return size;
}


void InLayer::setNeurones(std::vector<float>) 
{

}



