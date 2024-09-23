#include "Layer.h"


Layer::Layer(Ten3D A, int z)//исправить имена
{
	Layer::size = A.getSizeX() * A.getSizeY();
	listNeurones.resize(size);
	Layer::listNeurones = A.matrix_to_vector(z);

}

Layer::Layer(int numLayers)
{
	Layer::size = numLayers;
	listNeurones.resize(numLayers);
}


void Layer::printNeurones()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->listNeurones[i] << std::endl;
	}
}


std::vector<float> Layer::getNeurones()
{
	return listNeurones;
}

float Layer::getNeurones(int index)
{
	return listNeurones[index];// здесь вылетает ошибка 
}

void Layer::setNeurones(int index,float b)//исправить имена
{
	listNeurones[index] = b;
}


int Layer::getSize()
{
	return this->size;
}

void Layer::setSize(unsigned num)
{
	size = num;
}