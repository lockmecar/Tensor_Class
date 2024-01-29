#include <iostream>
#include "tensor.h"
using namespace std;

int main()
{
	tensor m1(4);
	tensor m2(4);
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			m1.set_object_of_matrix(i, j, i);
		}
	}
	m1.print();
	cout << endl << endl;
	
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m2.set_object_of_matrix(i, j, j);
		}
	}
	m2.print();
	cout << endl << endl;


	tensor m4(4);
	m4 = m1 + m2;//+
	m4.print();
	cout << endl << endl;
	m4 = m4 * 2;//+
	m4.print();
	cout << endl << endl;
	//m4 +=m1;// не работает
	//m4.print();//
	//cout << endl << endl;//
	//m4 *= 2;
	//m4.print();

	//tensor m3 = m1 + m2;
	//m3.print();
	
	
}