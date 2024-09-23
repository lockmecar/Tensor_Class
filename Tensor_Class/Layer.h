#pragma once
#include "tensor.h"
/*
���� 
	1) string  ���������� ��� �������� ���� ���� 
	2) ����������� �� ������ � ��� �.??
	3) 1 ������ �������, �� ������� �������
	4) (in(��������)->out(��������)->out(��������)....) 
	5) Flat ? 
	6) ������� ������ (������ ���������)
	7) ��������� ��� � ������� ������������ ���������
	8) �������� ���  

�����
	����������� ���� 
	��� ����������� ����� ������ ����� ����������� ������� 
	��������� ������� � ����� ������� ���� � �� �� ��� ��� ���� �� ����� ��������� ���� 
*/
class Layer
{

public:
	Layer(Ten3D A,int z);//��������� �����
	Layer(int num);

	void printNeurones();
	std::vector<float> getNeurones();
	float getNeurones(int index);
	void setNeurones(int index, float b);//��������� �����
	int getSize();
	//void genWeights(float matO,float md);
	void setSize(unsigned num);
	
private:
	int size;
	std::vector<float> listNeurones;

	//void conv()//??????????
};
