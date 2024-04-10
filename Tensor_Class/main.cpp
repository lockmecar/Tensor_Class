#include <iostream>
#include "tensor.h"

using namespace std;

void convolution(Ten3D a, Ten3D kernel, Ten2D result)
{
	int step = 2;
	// Тут надо сделать алгоритм свертки по примеру с сайта https://russianblogs.com/article/291049586/
}

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Ten3D a(7, 7, 3, "a", 'r');
		Ten3D kernel(3, 3, 3, "Kernel", 'r');
		a.padd();
		a.print();
		kernel.print();

	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}