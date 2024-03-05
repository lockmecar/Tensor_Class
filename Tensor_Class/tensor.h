#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

class tensor
{
private:
	std::string name;// ��� ������� ������
	int size_x;
	int size_y;      // ������ �������
	float** matrix;  // ��������� ������������ ������
	size_t& count(); // ������� ��������
	int rand_seed = 1;

public:
	tensor(int size_x, int size_y, std::string name, char mode);
	tensor(int size_x, int size_y, std::string name); // ����������� � ��������� �������
	tensor(const tensor& copied_obj);                 // ����������� �����������
	~tensor();                                        // ����������
	void print();                                     // ����� �� �������
	void set_object_of_matrix(int x, int y, float value); // ������ ��� ����������� �������� � �������
	void clear();

	void ElemFunc(float (*func)(float));       // ������������ ������� ��� ������ ���������

	float operator() (unsigned x, unsigned y); // ������ ��� ����������� �������� � �������

	union ftoul
	{
		float input;
		unsigned output;
	};

	std::vector<float> matrix_to_vector();

	tensor operator+ (const tensor& b) const;
	tensor& operator+= (const tensor& b);

	tensor& operator = (const tensor& b);

	tensor operator- (const tensor& b)const;
	tensor& operator-= (const tensor& b) ;

	tensor operator* (const tensor& b) const;
	tensor& operator*= (const tensor& b);

	tensor operator^ (const float& b) const;
	tensor& operator^= (const float& b);

	tensor transp();            // ����������������
	tensor abs();               // ������ (�������� �� �����)
	tensor sqrt();              // ���������� ������
	void fileout10(std::string b);           
	void fileout16(std::string b);        
};