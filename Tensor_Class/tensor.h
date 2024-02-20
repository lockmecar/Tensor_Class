#pragma once
#include <iostream>
#include <string>
#include <cmath>
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

	tensor operator+ (const tensor& b) const;
	tensor& operator+= (const tensor& b);

	tensor& operator = (const tensor& b);

	tensor operator- (const tensor& b)const;
	tensor& operator-= (const tensor& b) ;

	tensor operator* (const tensor& b) const;
	tensor& operator*= (const tensor& b);

	tensor operator^ (const float& b) const;

	tensor transp(); // ����������������
	tensor abs();    // ������ (�������� �� �����)
	tensor sqrt();//
};