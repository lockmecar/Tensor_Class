#pragma once
#include <iostream>

class tensor
{
private:
	

public:
	tensor(int size); // ����������� � ��������� �������
	void print();

	short size;
	float array[100][100] = { 0 };

	
};