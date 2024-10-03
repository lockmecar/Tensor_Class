#include <iostream>
#include "tensor.h"
#include "dataset.h"
//#include "Layer.h"
#include "Neuro2.h"
#include <fstream>

/*�������� ������
https://habr.com/ru/articles/514372/

https://www.youtube.com/playlist?list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK //���� �� ������

https://habr.com/ru/articles/846088/


*/

/*
����
	1) �������� ������������ ������ � ������� ������ �������� � ������� (����� �������)
	2) ����������� �� ������ � ��� �.??
	5) Flat ?
	6) ������� ������ (������ ���������)
	7) ��������� ��� � ������� ������������ ���������
	8) �������� ���
�����
	��� ����������� ����� ������ ����� ����������� �������
	��������� ������� � ����� ������� ���� � �� �� ��� ��� ���� �� ����� ��������� ����
*/


/*
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

void filldata(Ten3D &a, Ten3D &filter)
{

	ifstream data1("data.txt");//������� ��� ����� ����� � ���� ������ ��� �������� � ���������

	if (data1) //�������� � ����� ��������� � ����������� ������ ��� � ����
	{
		char buff_ten[150];
		data1.getline(buff_ten, 150);
		data1.close();

		int q = 0;
		for(int z = 0; z < 3; z++)
			for (int y = 0; y < 7; y++)
				for (int x = 0; x < 7; x++)
				{
					a.set_object_of_matrix(x, y, z, int(buff_ten[q] - '0'));
					q++;
				}
		q = 0;
	}

	ifstream filter1("filter.txt");

	if (filter1) //�������� � ����� ��������� � ����������� ������ ��� � ����
	{
		char buff_fil[54];
		filter1.getline(buff_fil, 54);
		filter1.close();

		int q = 0;
		for (int z = 0; z < 3; z++)
			for (int y = 0; y < 3; y++)
				for (int x = 0; x < 3; x++)
				{
					if(buff_fil[q]=='-')
					{
						filter.set_object_of_matrix(x, y, z, -int(buff_fil[q+1] - '0'));
						q+=2;
					}
					else 
					{
						filter.set_object_of_matrix(x, y, z, int(buff_fil[q] - '0'));
						q ++;
					}
				}
		q = 0;
	}
}


int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Ten3D A(3, 3, 1, "A",'r');

		Neuro2 B({ 9,4,3 }, A);
		B.print_w();

		B.printLayers();
		
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}