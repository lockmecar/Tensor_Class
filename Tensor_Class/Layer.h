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
*/
/*
�����
	����������� ���� 
	��� ����������� ����� ������ ����� ����������� ������� 
	��������� ������� � ����� ������� ���� � �� �� ��� ��� ���� �� ����� ��������� ���� 

*/
class Layer
{
public:
	virtual void printNeurones() = 0;
	virtual std::vector<float> getNeurones() = 0;
	//virtual void setNeurones(std::vector<float>) = 0;//?

private:
	std::vector<float> listNeurones;
};


class InLayer : Layer
{
public:
	InLayer(Ten3D A,char mode);
	void printNeurones() override;
	void printWei();
	std::vector<float> getNeurones() override;
	int getSize();
	void genWeights(float matO,float md);

private:
	int size;
	std::vector<float> listNeurones;
	std::vector<float> weights;//z
	//void conv()//??????????
};


//class OutLayer : Layer
//{
//public:
//	void printNeurones() override;
//	std::vector<float> getNeurones() override;
//		std::vector<float> weights;
//	
//
//private:
//	std::vector<float> listNeurones;
//	std::vector<float> weights;
//	int size;
//};
//
//
//class HideLayer : Layer
//{
//public:
//	void printNeurones() override;
//	std::vector<float> getNeurones() override;
//
//
//private:
//	std::vector<float> listNeurones;
//	std::vector<float> weights;
//	int size;
//};