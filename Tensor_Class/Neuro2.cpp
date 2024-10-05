#include "Neuro2.h"

Neuro2::Neuro2(std::vector<unsigned> numNeurones, Ten3D ten, std::vector<int> lable)
{

	layerSoftMax.resize(numNeurones[numNeurones.size() - 1]);//????????????
	loss.resize(ten.getSizeZ());//????????????
	w.resize(numNeurones.size() - 1);
	size_in_layer = numNeurones[0];//???????????


	for (size_t i = 1; i <= /*ten.getSizeZ()*/1; i++)
	{
		if (numNeurones[0] != (ten.getSizeX()* ten.getSizeY()))
			std::cout << "АЛЯРМ, ВЫ ДОПУСТИЛИ КАСЯХ!!!!" << std::endl;//подправить на error
		  
		vector_Layers.resize(numNeurones.size());

		for (size_t j = 0; j < numNeurones.size(); j++)
			vector_Layers[j].resize(numNeurones[j]);

		vector_Layers[i-1] = ten.matrix_to_vector(i);

		for (size_t i = 1; i < vector_Layers.size(); i++)
			w[i - 1].resize(vector_Layers[i - 1].size() * vector_Layers[i].size());

		gener_w(0, 1);

		Layer();

		softMax();

		crossEntropy(lable,i-1);//????
	}
}

void Neuro2::printLayers()
{
	for (size_t i = 0; i < vector_Layers.size(); i++)
	{
		std::cout << std::endl<< "Слой " << i << ": ";
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
			
			if (i == vector_Layers.size() - 1) //на последнем слое обычно ф-ция активации не применяется
				vector_Layers[i][j] =sum;
			else
				vector_Layers[i][j] = func(sum); 
		}
}

float Neuro2::func(float x)
{
	return 1/(1+std::exp(-x));//позже изменить RELU=1/(1+std::exp(-x)) |
}

void Neuro2::gener_w(float matO, float md)
{
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(matO, md);
	for (int i = 0; i < w.size(); i++) //iter????
		for(int j=0;j<w[i].size();j++)
			w[i][j]=(distribution(generator));
}

void Neuro2::softMax() {

	float sumExp = 0;

	// Вычисляем экспоненту для каждого нейрона в последнем слое и находим их сумму
	for (size_t i = 0; i < vector_Layers.back().size(); i++)
		sumExp += std::exp(vector_Layers.back()[i]);

	// Нормализуем каждый элемент слоя
	for (size_t i = 0; i < layerSoftMax.size(); i++)
		layerSoftMax[i] = (std::exp(vector_Layers.back()[i]) / sumExp) /**100*/;//можно без 100 будет точнее
}

void Neuro2::crossEntropy(std::vector<int> lable,int i_z)
{
	float error=0;
	for (size_t i = 0; i < layerSoftMax.size(); i++)
		if(layerSoftMax[i]!=0)// Избегаем log(0), так как это неопределенность
			error += lable[i] * std::log(layerSoftMax[i]);
	
	loss[i_z] = -error;

}

void Neuro2::print_w()
{
	std::cout << std::endl << "Веса" << std::endl;
	for (size_t i = 0; i < w.size(); i++)
	{
		for (size_t j = 0; j < w[i].size(); j++)
			std::cout << w[i][j]<<" ";
		std::cout << std::endl;
	}
}

void Neuro2::printSoftMax()
{
	std::cout << std::endl << "softMax: ";
	for (size_t i = 0; i < layerSoftMax.size(); i++)
		std::cout << layerSoftMax[i] << " ";
	std::cout << std::endl;
}

void Neuro2::printLoss()
{
	std::cout << std::endl << "Error: ";
	for (size_t i = 0; i < loss.size(); i++)
	{
		std::cout << loss[i] << " ";
	}
	std::cout << std::endl;
}


