#include <iostream>
#include "tensor.h"
#include "dataset.h"
#include "Neuro2.h"
#include <fstream>

/*�������� ������
https://habr.com/ru/articles/514372/

https://www.youtube.com/playlist?list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK //���� �� ������

https://habr.com/ru/articles/846088/


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
		Dataset a("a", 1, "train-images.idx3-ubyte", "train-labels.idx1-ubyte");
		//�������������� 
		const float alpha = 1;
		int current_step = 0;
		int good = 0;

		Neuro2 C({784,16,16,10}, a);
		//for (int i = 0; i < 100; i++)
		//{
		for (int epoh = 0; epoh < 10; epoh++)
		{
			for (current_step; current_step < 40000; current_step++)
			{
				//std::cout << current_step << ") " << std::endl;

				C.init(a, current_step);
				C.softMax();
				C.backprop(a.label[0][current_step]);
				C.updateWeights(alpha);
				good += C.result();
			}
		}
			
			
			
		//}
		cout << endl << good  << "%" << endl;
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}