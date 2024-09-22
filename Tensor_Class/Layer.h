#pragma once
#include "tensor.h"
/*
Идеи 
	1) string  переменная для названия типа слоя 
	2) размерность вх данных и вых д.??
	3) 1 вектор быстрее, но сложнее свертка
	4) (in(действие)->out(действие)->out(действие)....) 
	5) Flat ? 
	6) функция потерь (узнать подробнее)
	7) придумать как в колбасе использовать конвалюшн
	8) обратный ход  

Нужно
	реализовать слои 
	при перемещении между слоями нужно реализовать функции 
	результат функции в новый входной слой и тд до тех пор пока не будет последний слой 
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