#include "Neuro.h"

Neuro::Neuro(std::vector<unsigned> numNeurones, Ten3D ten)
{
	/*if (numNeurones.size() != numLayers) 
		throw std::invalid_argument("���-�� ����� != ������� �������");*/

	//�������� ������� �������� �� ������ ������� ������� numNeurones 
	// � ������ ������� ���� � Ten3D ten

	
	A.reserve(numNeurones.size());//������ �������� ������ Layer
	
	for (int i = 0; i < numNeurones.size(); i++)
	{
		if(i==0)
			A.emplace_back(ten, 1);//���� ���������
		else
			A.emplace_back(numNeurones[i]);//���� ���������
	}
}

void Neuro::step(std::vector<float> weights)
{
	
	for (int i = 0; i < A.size() - 1; i++)
	{
		straight(i, i + 1, A, weights);
	}
}

float Neuro::func(float e)
{
	return e;//����� �������� �� ���� �������
}

void Neuro::printA()
{
	for(int i=0;i<A.size();i++)
	{
		std::cout << A[i].getSize() << std::endl;
	}
}

void Neuro::straight(int index_1, int index_2, std::vector<Layer> A, std::vector<float> weights)
{
	for (int i = 0; i < A[index_2].getSize(); i++) {
		float sum = 0;
		for (int j = 0; j < A[index_1].getSize(); j++)
			sum += A[index_1].getNeurones(j) * weights[i * A[index_1].getSize() + j];
		A[index_2].setNeurones(i, func(sum));
	}
}

//void Neuro::genWeights(float matO, float md)
//{
//	
//	std::default_random_engine generator;
//	std::normal_distribution<double> distribution(matO, md);
//	for (int i = 0; i < weights.size(); i++) //iter????
//		weights[i] = distribution(generator);
//}
//
//void Neuro::printWei()
//{
//	for (int i = 0; i < weights.size(); i++)
//		std::cout << weights[i] << std::endl;
//}
