#include <iostream>
#include "tensor.h"

using namespace std;

float sum(float v)
{
	return v + 5;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Ten2D a(3, 3, "a", '0');
		a.ElemFunc(sum);
		a.print();

	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}