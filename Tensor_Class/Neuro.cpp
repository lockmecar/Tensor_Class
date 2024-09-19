#include "Neuro.h"

Neuro::Neuro(unsigned numLayers, std::vector<unsigned> numNeurones)
{
	if (numNeurones.size() != numLayers) 
		throw std::invalid_argument("кол-во слоев != размеру вектора");
	A.reserve(numLayers);
	for (int i = 0; i < numLayers; i++) 
	{
		
		if (i == 0) { A[i].setSize(numNeurones[i]); }
		this->A[i].setSize(numNeurones[i]);
	}
}
 