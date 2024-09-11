#include "Layer.h"


InLayer::InLayer(Ten3D A)
{
	InLayer::size = A.getSizeX() * A.getSizeY();
	listNeurones.reserve(size);//доделать
	InLayer::listNeurones = A.matrix_to_vector();
}


void InLayer::printNeurones() 
{

}


std::vector<float> InLayer::getNeurones()
{

}


void InLayer::setNeurones(std::vector<float>) 
{

}



