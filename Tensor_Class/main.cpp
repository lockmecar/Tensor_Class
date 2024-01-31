#include <iostream>
#include "tensor.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	try
	{
		tensor i(3, "i");
		i.set_object_of_matrix(1, 1, 50);
		tensor b(3,"b");
		b.set_object_of_matrix(1, 1, 50);
		i.print();
		b.print();

		tensor c(3, "c");
		c = i + b;
		c.print();
		i.print();

	}
	catch(length_error& ex)
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}