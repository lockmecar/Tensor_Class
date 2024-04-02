#include <iostream>
#include "tensor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Ten3D a(3, 3, 3, "a", 'r');
		a.print();
		Ten3D b(3, 3, 3, "b", 'r');
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