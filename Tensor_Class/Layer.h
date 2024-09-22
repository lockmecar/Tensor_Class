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
	Layer(Ten3D A,int z);
	Layer(int num);
	void printNeurones();
	//void printWei();
	std::vector<float> getNeurones();
	int getSize();
	//void genWeights(float matO,float md);
	void setSize(unsigned num);
	
private:
	int size;
	std::vector<float> listNeurones;
	//std::vector<float> weights;//z
	//void conv()//??????????
};


//class InLayer : Layer
//{
//public:
//	InLayer(Ten3D A,char mode);
//	void printNeurones() override;
//	void printWei();
//	std::vector<float> getNeurones() override;
//	int getSize();
//	void genWeights(float matO,float md);
//	void setSize(unsigned num) override;
//
//private:
//	int size;
//	std::vector<float> listNeurones;
//	std::vector<float> weights;//z
//	//void conv()//??????????
//};
//

//class OutLayer : Layer
//{
//public:
//	OutLayer(Ten3D A, char mode);
//	void printNeurones() override;
//	void printWei();
//	std::vector<float> getNeurones() override;
//	int getSize();
//	void genWeights(float matO, float md);
//	void setSize(unsigned num) override;
//
//private:
//	int size;
//	std::vector<float> listNeurones;
//	std::vector<float> weights;
//	//conv
//};
//
//
//class hideLayer : Layer
//{
//public:
//	hideLayer(Ten3D A, char mode);
//	void printNeurones() override;
//	void printWei();
//	std::vector<float> getNeurones() override;
//	int getSize();
//	void genWeights(float matO, float md);
//	void setSize(unsigned num) override;
//
//private:
//	int size;
//	std::vector<float> listNeurones;
//	std::vector<float> weights;
//	//conv
//};