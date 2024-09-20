#include "Neuro.h"

Neuro::Neuro(unsigned numLayers, std::vector<unsigned> numNeurones, Ten3D ten)
{
	if (numNeurones.size() != numLayers) 
		throw std::invalid_argument("���-�� ����� != ������� �������");

	A.reserve(numLayers);//������ �������� ������ Layer

	Layer* straight1;//������ ���

	for (int i = 0; i < numLayers; i++) 
	{
		if(i==0)
		{
			straight1 = new Layer(ten, 1);//��������, ����� ���������
		}
		else 
		{
			straight1 = new Layer(ten, 1);//��������, ����� ���������
		}

		A.push_back(straight1);
	}
}
 