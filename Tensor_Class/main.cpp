#include <iostream>
#include "tensor.h"
#include "dataset.h"
#include "Neuro2.h"
#include <fstream>

/*�������� ������
https://habr.com/ru/articles/514372/

https://www.youtube.com/playlist?list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK //���� �� ������

https://habr.com/ru/articles/846088/


��� �����:
	����� ��������: ~
	����� ����: ~
	������ ���: -
	�������� ���: -
	�������: -
���� ������:
	1) �������� ����� ����
	2) ��� ����� ����� ���� �������� ����� ��������
	3) ����������� ������ ��� �� ���������� ������
	4) ����������� �������� ���:
		4.1) ������� �������� ��������� ��������������� ������ (������ � ��):
			4.1.1) ������� ����������� �����
			4.1.2) ������� �������������� ����������� �����
		4.2) �������� ��� �����
	5) ����������� �������:
		5.1) ������� ����������� ���������� ��������� ���� (����� � ��):
		5.2) �������� ���������� ����
		5.3) ���������� ���������� ���� � �������
	6) ������ �����������, �������, ����������
*/
using namespace std;


int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Dataset a("a", 100, "t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");
		//�������������� 
		const float alpha = 0.001;
		int current_step = 0;
		int good = 0;
		Neuro2 C({784,4,3,10}, a);
		for (current_step; current_step < 100; current_step++)
		{
			std::cout << current_step << ") " << std::endl;
			for (size_t i = 0; i < 100; i++)
			{
				C.init(a, alpha, current_step);
				//C.result();
			}
			good+=C.result();
		}
		cout << endl<< good << endl;
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}