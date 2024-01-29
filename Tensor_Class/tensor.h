#pragma once
#include <iostream>

class tensor
{
private:
	int size;        // ������ �������
	float** matrix;  // ��������� ������������ ������
	//size_t& count(); // ������� ��������

public:
	tensor(int size); // ����������� � ��������� �������
	~tensor();        // ����������
	void print();     // ����� �� �������
	float get_object_of_matrix(int x, int y);             // ������ ��� ����������� �������� � �������
	void set_object_of_matrix(int x, int y, float value); // ������ ��� ����������� �������� � �������

	tensor transp(tensor a);

	tensor operator- (const tensor& a);
	tensor operator-= (const tensor& a);

	tensor operator+ (const tensor& a);
	tensor& operator+= (const tensor& a);

	tensor& operator = (const tensor& a);

	//tensor& operator *= (const tensor& a);
	//tensor& operator * (const tensor& a);
	tensor& operator * (const int& a);
	tensor& operator * (const float& a);
	tensor& operator*=(const int& a);
	tensor& operator*=(const float& a);

};