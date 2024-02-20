#include <iostream>
#include "tensor.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	try
	{
		tensor a(3, 4, "a");
		tensor b(3, 4, "b");
		tensor c(3, 4, "c");
		c = a * b;
		c.print();

	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}