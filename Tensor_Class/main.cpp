#include <iostream>
#include "tensor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		int q = 0;
		Ten3D a(3, 3, 3, "a", '0');
		for (int x = 0; x < 3; x++)
		{
			q = 1;
			for (int y = 0; y < 3; y++)
				for (int z = 0; z < 3; z++)
				{
					a.set_object_of_matrix(x, y, z, q);
					q++;
				}
		}
		a.print();

		Ten3D b(3, 3, 3, "b", '0');
		for (int x = 0; x < 3; x++)
		{
			q = 1;
			for (int y = 0; y < 3; y++)
				for (int z = 0; z < 3; z++)
				{
					b.set_object_of_matrix(x, y, z, q);
					q++;
				}
		}
		b.print();
		Ten3D c(3, 3, 3, "c", '0');
		c.print();
		cout << "-------------------------" << endl;
		c = a * b;
		c.print();

	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}