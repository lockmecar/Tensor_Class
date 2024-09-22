#include "Neuro.h"

Neuro::Neuro(unsigned numLayers, std::vector<unsigned> numNeurones, Ten3D ten)
{
	if (numNeurones.size() != numLayers) 
		throw std::invalid_argument("���-�� ����� != ������� �������");

	A.reserve(numLayers);//������ �������� ������ Layer
	
	for (int i = 0; i < numLayers; i++) 
	{
		if(i==0)
			straight1 = new Layer(ten, 1);//��������, ����� ���������
		else if (i == 1)
			straight1 = new Layer(numLayers);//��������, ����� ���������
		else if (i == 2)
			straight1 = new Layer(numLayers);//��������, ����� ���������
		else if (i == 3)
			straight1 = new Layer(numLayers);//��������, ����� ���������

		A.push_back(straight1);
	}
}

void Neuro::step(std::vector<float> weights, float func)
{
	/*for (int i=0; i < A.size(); i++) 
	{
		for (int j = 0; j < A[0].getSize()) {}
	}*/
}

float Neuro::func(float e)
{
	return e;//����� �������� �� ���� �������
}


