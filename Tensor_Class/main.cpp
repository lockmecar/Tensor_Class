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

		//Ten3D B(28, 28, 1, "B", A);
		//vector<float> bup{ 2.38,1.45,3.1 };


		Neuro2 C({784,4,3,10}, a);

		C.init(a);
		//C.print_w();
		//C.printLayersT();
		C.printLayersH();
		C.printError();


		//Neuro2 C({ 3,2,4 }, bup);
		//C.print_w();

		//C.printLayers();
		
		//C.print_softMax();

		//C.printError();

		//C.print_vector_backprop();
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}