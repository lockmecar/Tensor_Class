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

};