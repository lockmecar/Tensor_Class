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
	float get_object_of_matrix(int x, int y);             // Геттер для конкретного значения в матрице
	void set_object_of_matrix(int x, int y, float value); // Сеттер для конкретного значения в матрице
	tensor operator+ (const tensor& a);
};