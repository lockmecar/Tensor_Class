#include <iostream>
#include "tensor.h"

using namespace std;


void filldata(Ten3D &a, Ten3D &filter)
{
	a.set_object_of_matrix(0, 0, 0, 0); a.set_object_of_matrix(1, 0, 0, 0); a.set_object_of_matrix(2, 0, 0, 0); a.set_object_of_matrix(3, 0, 0, 0); a.set_object_of_matrix(4, 0, 0, 0); a.set_object_of_matrix(5, 0, 0, 0); a.set_object_of_matrix(6, 0, 0, 0);
	a.set_object_of_matrix(0, 1, 0, 0); a.set_object_of_matrix(1, 1, 0, 0); a.set_object_of_matrix(2, 1, 0, 1); a.set_object_of_matrix(3, 1, 0, 1); a.set_object_of_matrix(4, 1, 0, 2); a.set_object_of_matrix(5, 1, 0, 2); a.set_object_of_matrix(6, 1, 0, 0);
	a.set_object_of_matrix(0, 2, 0, 0); a.set_object_of_matrix(1, 2, 0, 0); a.set_object_of_matrix(2, 2, 0, 1); a.set_object_of_matrix(3, 2, 0, 1); a.set_object_of_matrix(4, 2, 0, 0); a.set_object_of_matrix(5, 2, 0, 0); a.set_object_of_matrix(6, 2, 0, 0);
	a.set_object_of_matrix(0, 3, 0, 0); a.set_object_of_matrix(1, 3, 0, 1); a.set_object_of_matrix(2, 3, 0, 1); a.set_object_of_matrix(3, 3, 0, 0); a.set_object_of_matrix(4, 3, 0, 1); a.set_object_of_matrix(5, 3, 0, 0); a.set_object_of_matrix(6, 3, 0, 0);
	a.set_object_of_matrix(0, 4, 0, 0); a.set_object_of_matrix(1, 4, 0, 1); a.set_object_of_matrix(2, 4, 0, 0); a.set_object_of_matrix(3, 4, 0, 1); a.set_object_of_matrix(4, 4, 0, 1); a.set_object_of_matrix(5, 4, 0, 1); a.set_object_of_matrix(6, 4, 0, 0);
	a.set_object_of_matrix(0, 5, 0, 0); a.set_object_of_matrix(1, 5, 0, 0); a.set_object_of_matrix(2, 5, 0, 2); a.set_object_of_matrix(3, 5, 0, 0); a.set_object_of_matrix(4, 5, 0, 1); a.set_object_of_matrix(5, 5, 0, 0); a.set_object_of_matrix(6, 5, 0, 0);
	a.set_object_of_matrix(0, 6, 0, 0); a.set_object_of_matrix(1, 6, 0, 0); a.set_object_of_matrix(2, 6, 0, 0); a.set_object_of_matrix(3, 6, 0, 0); a.set_object_of_matrix(4, 6, 0, 0); a.set_object_of_matrix(5, 6, 0, 0); a.set_object_of_matrix(6, 6, 0, 0);

	a.set_object_of_matrix(0, 0, 1, 0); a.set_object_of_matrix(1, 0, 1, 0); a.set_object_of_matrix(2, 0, 1, 0); a.set_object_of_matrix(3, 0, 1, 0); a.set_object_of_matrix(4, 0, 1, 0); a.set_object_of_matrix(5, 0, 1, 0); a.set_object_of_matrix(6, 0, 1, 0);
	a.set_object_of_matrix(0, 1, 1, 0); a.set_object_of_matrix(1, 1, 1, 1); a.set_object_of_matrix(2, 1, 1, 1); a.set_object_of_matrix(3, 1, 1, 1); a.set_object_of_matrix(4, 1, 1, 2); a.set_object_of_matrix(5, 1, 1, 0); a.set_object_of_matrix(6, 1, 1, 0);
	a.set_object_of_matrix(0, 2, 1, 0); a.set_object_of_matrix(1, 2, 1, 0); a.set_object_of_matrix(2, 2, 1, 2); a.set_object_of_matrix(3, 2, 1, 1); a.set_object_of_matrix(4, 2, 1, 1); a.set_object_of_matrix(5, 2, 1, 2); a.set_object_of_matrix(6, 2, 1, 0);
	a.set_object_of_matrix(0, 3, 1, 0); a.set_object_of_matrix(1, 3, 1, 1); a.set_object_of_matrix(2, 3, 1, 2); a.set_object_of_matrix(3, 3, 1, 0); a.set_object_of_matrix(4, 3, 1, 0); a.set_object_of_matrix(5, 3, 1, 2); a.set_object_of_matrix(6, 3, 1, 0);
	a.set_object_of_matrix(0, 4, 1, 0); a.set_object_of_matrix(1, 4, 1, 0); a.set_object_of_matrix(2, 4, 1, 2); a.set_object_of_matrix(3, 4, 1, 1); a.set_object_of_matrix(4, 4, 1, 2); a.set_object_of_matrix(5, 4, 1, 1); a.set_object_of_matrix(6, 4, 1, 0);
	a.set_object_of_matrix(0, 5, 1, 0); a.set_object_of_matrix(1, 5, 1, 2); a.set_object_of_matrix(2, 5, 1, 0); a.set_object_of_matrix(3, 5, 1, 1); a.set_object_of_matrix(4, 5, 1, 2); a.set_object_of_matrix(5, 5, 1, 0); a.set_object_of_matrix(6, 5, 1, 0);
	a.set_object_of_matrix(0, 6, 1, 0); a.set_object_of_matrix(1, 6, 1, 0); a.set_object_of_matrix(2, 6, 1, 0); a.set_object_of_matrix(3, 6, 1, 0); a.set_object_of_matrix(4, 6, 1, 0); a.set_object_of_matrix(5, 6, 1, 0); a.set_object_of_matrix(6, 6, 1, 0);

	a.set_object_of_matrix(0, 0, 2, 0); a.set_object_of_matrix(1, 0, 2, 0); a.set_object_of_matrix(2, 0, 2, 0); a.set_object_of_matrix(3, 0, 2, 0); a.set_object_of_matrix(4, 0, 2, 0); a.set_object_of_matrix(5, 0, 2, 0); a.set_object_of_matrix(6, 0, 2, 0);
	a.set_object_of_matrix(0, 1, 2, 0); a.set_object_of_matrix(1, 1, 2, 2); a.set_object_of_matrix(2, 1, 2, 0); a.set_object_of_matrix(3, 1, 2, 2); a.set_object_of_matrix(4, 1, 2, 0); a.set_object_of_matrix(5, 1, 2, 2); a.set_object_of_matrix(6, 1, 2, 0);
	a.set_object_of_matrix(0, 2, 2, 0); a.set_object_of_matrix(1, 2, 2, 0); a.set_object_of_matrix(2, 2, 2, 0); a.set_object_of_matrix(3, 2, 2, 1); a.set_object_of_matrix(4, 2, 2, 2); a.set_object_of_matrix(5, 2, 2, 1); a.set_object_of_matrix(6, 2, 2, 0);
	a.set_object_of_matrix(0, 3, 2, 0); a.set_object_of_matrix(1, 3, 2, 1); a.set_object_of_matrix(2, 3, 2, 0); a.set_object_of_matrix(3, 3, 2, 2);	a.set_object_of_matrix(4, 3, 2, 2); a.set_object_of_matrix(5, 3, 2, 1); a.set_object_of_matrix(6, 3, 2, 0);
	a.set_object_of_matrix(0, 4, 2, 0); a.set_object_of_matrix(1, 4, 2, 2); a.set_object_of_matrix(2, 4, 2, 0); a.set_object_of_matrix(3, 4, 2, 2);	a.set_object_of_matrix(4, 4, 2, 0); a.set_object_of_matrix(5, 4, 2, 0); a.set_object_of_matrix(6, 4, 2, 0);
	a.set_object_of_matrix(0, 5, 2, 0); a.set_object_of_matrix(1, 5, 2, 0); a.set_object_of_matrix(2, 5, 2, 0); a.set_object_of_matrix(3, 5, 2, 1);	a.set_object_of_matrix(4, 5, 2, 1); a.set_object_of_matrix(5, 5, 2, 2); a.set_object_of_matrix(6, 5, 2, 0);
	a.set_object_of_matrix(0, 6, 2, 0); a.set_object_of_matrix(1, 6, 2, 0); a.set_object_of_matrix(2, 6, 2, 0); a.set_object_of_matrix(3, 6, 2, 0);	a.set_object_of_matrix(4, 6, 2, 0); a.set_object_of_matrix(5, 6, 2, 0); a.set_object_of_matrix(6, 6, 2, 0);


	filter.set_object_of_matrix(0, 0, 0, 1); filter.set_object_of_matrix(1, 0, 0, 1); filter.set_object_of_matrix(2, 0, 0, -1);
	filter.set_object_of_matrix(0, 1, 0, -1); filter.set_object_of_matrix(1, 1, 0, 0); filter.set_object_of_matrix(2, 1, 0, 1);
	filter.set_object_of_matrix(0, 2, 0, -1); filter.set_object_of_matrix(1, 2, 0, -1); filter.set_object_of_matrix(2, 2, 0, 0);

	filter.set_object_of_matrix(0, 0, 1, -1); filter.set_object_of_matrix(1, 0, 1, 0); filter.set_object_of_matrix(2, 0, 1, -1);
	filter.set_object_of_matrix(0, 1, 1, 0); filter.set_object_of_matrix(1, 1, 1, 0); filter.set_object_of_matrix(2, 1, 1, -1);
	filter.set_object_of_matrix(0, 2, 1, 1); filter.set_object_of_matrix(1, 2, 1, -1); filter.set_object_of_matrix(2, 2, 1, 0);

	filter.set_object_of_matrix(0, 0, 2, 0); filter.set_object_of_matrix(1, 0, 2, 1); filter.set_object_of_matrix(2, 0, 2, 0);
	filter.set_object_of_matrix(0, 1, 2, 1); filter.set_object_of_matrix(1, 1, 2, 0); filter.set_object_of_matrix(2, 1, 2, 1);
	filter.set_object_of_matrix(0, 2, 2, 0); filter.set_object_of_matrix(1, 2, 2, -1); filter.set_object_of_matrix(2, 2, 2, 1);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Ten3D a(7, 7, 3, "a", '0');
		Ten3D filter(3, 3, 3, "filter", '0');
		Ten3D result(3, 3, 1, "result", '0');
		filldata(a, filter);

		a.print();
		filter.print();
		result.print();

		a.convolution(filter, result, 2);

		result.print();
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}