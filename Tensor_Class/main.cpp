#include <iostream>
#include "tensor.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	try
	{
		tensor a(3, "a");
		tensor b(3, "b");
		tensor c(3, "c");

		a.set_object_of_matrix(0, 0, 50);
		b.set_object_of_matrix(0, 0, 70);
		c = b - a;

		a.print();
		b.print();
		c.print();
	}
	catch(length_error& ex)
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}