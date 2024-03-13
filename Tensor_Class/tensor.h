#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

class Ten2D
{
private:
	std::string name;// Имя объекта класса
	int size_x;
	int size_y;      // Размер массива
	float** matrix;  // Двумерный динамический массив
	size_t& count(); // Счетчик обьектов
	int rand_seed = 1;

public:
	Ten2D(int size_x, int size_y, std::string name, char mode);
	Ten2D(int size_x, int size_y, std::string name);      // Конструктор с указанием размера
	Ten2D(const Ten2D& copied_obj);                       // Конструктор копирования
	~Ten2D();                                             // Деструктор
	void print();                                         // Вывод на консоль
	void set_object_of_matrix(int x, int y, float value); // Сеттер для конкретного значения в матрице
	void clear();

	void ElemFunc(float (*func)(float));       // Элементарная функция над каждым элементом

	float operator() (unsigned x, unsigned y); // Геттер для конкретного значения в матрице

	union ftoul
	{
		float input;
		unsigned output;
	};

	std::vector<float> matrix_to_vector();

	Ten2D operator+ (const Ten2D& b) const;
	Ten2D& operator+= (const Ten2D& b);

	Ten2D& operator = (const Ten2D& b);

	Ten2D operator- (const Ten2D& b)const;
	Ten2D& operator-= (const Ten2D& b) ;

	Ten2D operator* (const Ten2D& b) const;
	Ten2D& operator*= (const Ten2D& b);

	Ten2D operator^ (const float& b) const;
	Ten2D& operator^= (const float& b);

	Ten2D transp();            // Транспонирование
	Ten2D abs();               // Модуль (возможно не нужен)
	Ten2D sqrt();              // Квадратный корень
	void fileout10(std::string b);           
	void fileout16(std::string b);        
};

class Ten3D
{
private:
	std::string name; // Имя объекта класса
	int size_x;
	int size_y;       // Размер массива
	int size_z;
	float*** matrix;  // Трехмерный динамический массив
	size_t& count();  // Счетчик обьектов
	int rand_seed = 1;

public:
	Ten3D(int size_x, int size_y, int size_z, std::string name); // Конструктор с указанием размера
	Ten3D(const Ten3D& copied_obj);                              // Конструктор копирования
	Ten3D(int size_x, int size_y, int size_z, std::string name, char mode);
	void print();                                                // Вывод на консоль
	~Ten3D();
};