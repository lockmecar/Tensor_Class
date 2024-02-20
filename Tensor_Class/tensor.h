#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

class tensor
{
private:
	std::string name;// Имя объекта класса
	int size_x;
	int size_y;      // Размер массива
	float** matrix;  // Двумерный динамический массив
	size_t& count(); // Счетчик обьектов
	int rand_seed = 1;

public:
	tensor(int size_x, int size_y, std::string name, char mode);
	tensor(int size_x, int size_y, std::string name); // Конструктор с указанием размера
	tensor(const tensor& copied_obj);   // Конструктор копирования
	~tensor();                          // Деструктор
	void print();                       // Вывод на консоль
	float get_object_of_matrix(int x, int y);             // Геттер для конкретного значения в матрице
	void set_object_of_matrix(int x, int y, float value); // Сеттер для конкретного значения в матрице
	void clear();

	tensor operator+ (const tensor& b) const;
	tensor& operator+= (const tensor& b);

	tensor& operator = (const tensor& b);

	tensor operator- (const tensor& b)const;
	tensor& operator-= (const tensor& b) ;

	tensor operator* (const tensor& b) const;
	tensor& operator*= (const tensor& b);

	tensor operator^ (const float& b) const;

	tensor transp(); // Транспонирование
	tensor abs();    // Модуль (возможно не нужен)
	tensor sqrt();//
};