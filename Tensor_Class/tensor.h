#pragma once
#include <iostream>

class tensor
{
private:
	int size;        // ������ �������
	float** matrix;  // ��������� ������������ ������
	size_t& count(); // ������� ��������

public:
	tensor(int size); // ����������� � ��������� �������
	~tensor();        // ����������
	void print();     // ����� �� �������
	float get_object_of_matrix(int x, int y);             // ������ ��� ����������� �������� � �������
	void set_object_of_matrix(int x, int y, float value); // ������ ��� ����������� �������� � �������
	tensor operator+ (const tensor& a);
};