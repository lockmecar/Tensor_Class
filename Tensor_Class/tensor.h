#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

class tensor
{
private:
	std::string name;// Имя объекта класса
	int size_x;
	int size_y;      // Размер массива
	float** matrix;  // Двумерный динамический массив
	size_t& count(); // Счетчик обьектов

public:
	tensor(int size_x, int size_y, std::string name); // Конструктор с указанием размера
	tensor(const tensor& copied_obj);   // Конструктор копирования
	~tensor();                          // Деструктор
	void print();                       // Вывод на консоль
	float get_object_of_matrix(int x, int y);             // Геттер для конкретного значения в матрице
	void set_object_of_matrix(int x, int y, float value); // Сеттер для конкретного значения в матрице

	union ftoul
	{
		float input;
		unsigned output;
	};

	tensor operator+ (const tensor& b) const;
	tensor& operator+= (const tensor& b);

	tensor& operator = (const tensor& b);

	tensor operator- (const tensor& b)const;
	tensor& operator-= (const tensor& b) ;

	tensor operator* (const tensor& b) const;
	tensor& operator*= (const tensor& b);

	tensor operator^ (const float& b) const;

	tensor transp();            // Транспонирование
	tensor abs();               // Модуль (возможно не нужен)
	tensor sqrt();              // Корень
	void fileout10(std::string b);           //
	void fileout16(std::string b);        //
};