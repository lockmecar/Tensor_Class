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
	Layer(Ten3D A,int z);//исправить имена
	Layer(int num);

	void printNeurones();
	std::vector<float> getNeurones();
	float getNeurones(int index);
	void setNeurones(int index, float b);//исправить имена
	int getSize();
	//void genWeights(float matO,float md);
	void setSize(unsigned num);
	
private:
	int size;
	std::vector<float> listNeurones;

	//void conv()//??????????
};
