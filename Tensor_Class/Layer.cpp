#include "Layer.h"


Layer::Layer(Ten3D A, int z)
{
	Layer::size = A.getSizeX() * A.getSizeY();
	listNeurones.resize(size);
	Layer::listNeurones = A.matrix_to_vector(z);

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
	return this->listNeurones;
}


int Layer::getSize()
{
	return this->size;
}

void Layer::setSize(unsigned num)
{
	size = num;
}