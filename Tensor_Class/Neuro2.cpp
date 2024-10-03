#include "Neuro2.h"

Neuro2::Neuro2(std::vector<unsigned> numNeurones, Ten3D ten)
{

	for (size_t i = 1; i <= /*ten.getSizeZ()*/1; i++)
	{
		if (numNeurones[0] != (ten.getSizeX()* ten.getSizeY()))
			std::cout << "ÀËßÐÌ, ÂÛ ÄÎÏÓÑÒÈËÈ ÊÀÑßÕ!!!!" << std::endl;//ïîäïðàâèòü íà error

		vector_Layers.resize(numNeurones.size());

		for (size_t j = 0; j < numNeurones.size(); j++)
			vector_Layers[j].resize(numNeurones[j]);

		vector_Layers[i-1] = ten.matrix_to_vector(i);
	}
	size_in_layer = numNeurones[0];

	w.resize(vector_Layers.size()-1);
	for (size_t i = 1; i < vector_Layers.size(); i++)
	{
		w[i-1].resize(vector_Layers[i-1].size() * vector_Layers[i].size());
	}
	gener_w(0,1);

	Layer();
}

void Neuro2::printLayers()
{
	for (size_t i = 0; i < vector_Layers.size(); i++)
	{
		std::cout << std::endl<< "Ñëîé " << i << ": ";
		for (size_t j = 0; j < vector_Layers[i].size(); j++)
			std::cout << vector_Layers[i][j]<<" ";
		std::cout << std::endl;
	}
}


void Neuro2::Layer() 
{
	for (size_t i = 1; i < vector_Layers.size(); i++) 
		for (size_t j = 0; j < vector_Layers[i].size(); j++) 
		{
			float sum = 0; 
			for (size_t k = 0; k < vector_Layers[i - 1].size(); k++)
				sum += vector_Layers[i - 1][k] * w[i - 1][j];
			vector_Layers[i][j] = func(sum);
		}
}



float Neuro2::func(float x)
{
	return 1/(1+std::exp(-x));//ïîçæå èçìåíèòü
}

void Neuro2::gener_w(float matO, float md)
{
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(matO, md);
	for (int i = 0; i < w.size(); i++) //iter????
		for(int j=0;j<w[i].size();j++)
			w[i][j]=(distribution(generator));
}

void Neuro2::print_w()
{
	std::cout << std::endl << "Âåñà" << std::endl;
	for (size_t i = 0; i < w.size(); i++)
	{
		for (size_t j = 0; j < w[i].size(); j++)
			std::cout << w[i][j]<<" ";
		std::cout << std::endl;
	}
}


