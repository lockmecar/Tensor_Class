#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <random>

union ftoul
{
	float input;
	unsigned output;
};

template <typename T>
struct counter
{
	counter()
	{
		objects_created++;
		objects_alive++;
	}

	counter(const counter&)
	{
		objects_created++;
		objects_alive++;
	}

protected:
	virtual ~counter()
	{
		--objects_alive;
	}
	static int objects_created;
	static int objects_alive;
};
template <typename T> int counter<T>::objects_created(0);
template <typename T> int counter<T>::objects_alive(0);

class Ten2D : counter<Ten2D>
{
private:
	std::string name;// Имя объекта класса
	int size_x;
	int size_y;      // Размер массива
	float** matrix;  // Двумерный динамический массив
	int rand_seed = 1;

public:
	Ten2D(int size_x, int size_y, std::string name, char mode); // Конструктор с двумя режимами ('0' - заполнит нулями, 'r' - заполнит рандомами)
	Ten2D(int size_x, int size_y, std::string name);            // Конструктор с указанием размера
	Ten2D(const Ten2D& copied_obj);                             // Конструктор копирования
	~Ten2D();                                                   // Деструктор
	void print();                                               // Вывод на консоль
	void set_object_of_matrix(int x, int y, float value);       // Сеттер для конкретного значения в матрице
	void clear();

	void ElemFunc(float (*func)(float));       // Элементарная функция над каждым элементом

	float operator() (int x, int y); // Геттер для конкретного значения в матрице

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
	void fileout10(std::string NameOfFile);           
	void fileout16(std::string NameOfFile);
};

class Ten3D : counter<Ten3D>
{
	friend class Dataset;
private:
	std::string name; // Имя объекта класса
	int size_x;
	int size_y;       // Размер массива
	int size_z;
	float*** matrix;  // Трехмерный динамический массив
	int rand_seed = 1;

public:
	Ten3D();
	Ten3D(int size_x, int size_y, int size_z, std::string name);            // Конструктор с указанием размера
	Ten3D(const Ten3D& copied_obj);                                         // Конструктор копирования
	Ten3D(int size_x, int size_y, int size_z, std::string name, char mode); // Конструктор с двумя режимами ('0' - заполнит нулями, 'r' - заполнит рандомами)
	Ten3D(int size_x, int size_y, int size_z, std::string name, std::vector<std::vector<float>> D);
	~Ten3D();

	void print(char mode);
	void set_object_of_matrix(int x, int y, int z, float value);
	void clear();
	int getSizeX();
	int getSizeY();
	int getSizeZ();
	void imgToMatrix(std::ifstream& file);

	std::vector<float> matrix_to_vector();

	std::vector<float> matrix_to_vector(int z);

	float operator() (int x, int y, int z);

	Ten3D operator+ (const Ten3D& b) const;
	Ten3D& operator+= (const Ten3D& b);

	Ten3D& operator = (const Ten3D& b);

	Ten3D operator- (const Ten3D& b)const;
	Ten3D& operator-= (const Ten3D& b);

	Ten3D operator* (const Ten3D& b) const;
	Ten3D& operator*= (const Ten3D& b);

	Ten3D operator^ (const float& b) const;
	Ten3D& operator^= (const float& b);

	void convolutionHard(Ten3D &filter, Ten3D &result, int step);
	void convolution(Ten3D& filter, Ten3D& result, int step);
	void padd();

	void fileout10(std::string NameOfFile);
	void fileout16(std::string NameOfFile);


};