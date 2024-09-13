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
*/
/*
Нужно
	реализовать слои 
	при перемещении между слоями нужно реализовать функции 
	результат функции в новый входной слой и тд до тех пор пока не будет последний слой 

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