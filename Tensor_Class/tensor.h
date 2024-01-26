#pragma once
#include <iostream>

class tensor
{
private:
	

public:
	tensor(int size); // Конструктор с указанием размера
	void print();

	short size;
	float array[100][100] = { 0 };

	
};