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
	//virtual std::vector<float> getNeurones() = 0;
	virtual void setNeurones(std::vector<float>) = 0;//?

private:
	std::vector<float> listNeurones;
	
};


class InLayer : Layer
{
public:
	InLayer(Ten3D A,char mode);
	void printNeurones() override;
	//std::vector<float> getNeurones() override;
	int getSize();
	void setNeurones(std::vector<float>) override;


private:
	int size;
	std::vector<float> listNeurones;
	void conv();
};


class OutLayer : Layer
{
public:
	void printNeurones() override;
	//std::vector<float> getNeurones() override;
	void setNeurones(std::vector<float>) override;

private:
	std::vector<float> listNeurones;
};


class HideLayer : Layer
{
public:
	void printNeurones() override;
	//std::vector<float> getNeurones() override;
	void setNeurones(std::vector<float>) override;

private:
	std::vector<float> listNeurones;
};