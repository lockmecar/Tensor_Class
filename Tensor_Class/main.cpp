#include <iostream>
#include "tensor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Ten3D a(3, 3, 3, "a",'r');
		Ten3D b(a);
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}