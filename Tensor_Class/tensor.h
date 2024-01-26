#pragma once
#include <iostream>

class tensor
{
private:
	int size;        // Размер массива
	float** matrix;  // Двумерный динамический массив
	size_t& count(); // Счетчик обьектов

public:
	tensor(int size); // Конструктор с указанием размера
	~tensor();        // Деструктор
	void print();     // Вывод на консоль

};