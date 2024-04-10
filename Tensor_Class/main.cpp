#include <iostream>
#include "tensor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Ten3D a(7, 7, 3, "a", '0');
		a.set_object_of_matrix(1, 1, 0, 4);
		Ten3D b(a);
		b.set_object_of_matrix(1, 1, 0, -2);
		Ten3D c(7, 7, 3, "c", '0');
		c = a + b;
		c.fileout10("Test");

	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}