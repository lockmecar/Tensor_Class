#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

class tensor
{
private:
	std::string name;// ��� ������� ������
	int size_x;
	int size_y;      // ������ �������
	float** matrix;  // ��������� ������������ ������
	size_t& count(); // ������� ��������

public:
	tensor(int size_x, int size_y, std::string name); // ����������� � ��������� �������
	tensor(const tensor& copied_obj);   // ����������� �����������
	~tensor();                          // ����������
	void print();                       // ����� �� �������
	float get_object_of_matrix(int x, int y);             // ������ ��� ����������� �������� � �������
	void set_object_of_matrix(int x, int y, float value); // ������ ��� ����������� �������� � �������

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

	tensor transp();            // ����������������
	tensor abs();               // ������ (�������� �� �����)
	tensor sqrt();              // ������
	void fileout10(std::string b);           //
	void fileout16(std::string b);        //
};