#include <iostream>
#include "tensor.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	try
	{
		int q = 0;
		tensor t1(3, "t1");
		tensor t2(3, "t2");
		tensor t3(3, "t3");
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j < 3; j++) 
			{
				q++;
				t1.set_object_of_matrix(i, j, -q);
				//t2.set_object_of_matrix(j, i, q);
			}
		t1.set_object_of_matrix(1, 1, 7);
		t1.set_object_of_matrix(2, 2, 1);
		t1.print();
		t3=t1.abs();
		t3.print();
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}