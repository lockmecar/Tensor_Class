#include <iostream>
#include "tensor.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	try
	{
		tensor a(3, "a");
		a.set_object_of_matrix(1, 1, 50);
		tensor b(3,"b");
		b.set_object_of_matrix(1, 1, 50);
		tensor c(3, "c");
		c = a + b;
		c.print();
		a.print();
	}
	catch(length_error& ex)
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}