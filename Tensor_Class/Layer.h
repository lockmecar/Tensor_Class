#pragma once
#include "tensor.h"

class Layer
{

public:
	Layer(Ten3D A,int z);//исправить имена
	Layer(int num);

	void printNeurones();
	std::vector<float> getNeurones();
	float getNeurones(int index);
	void setNeurones(int index, float b);//исправить имена
	int getSize();
	void setSize(unsigned num);
	
private:
	int size;
	std::vector<float> listNeurones;

	//void conv()//??????????
};
