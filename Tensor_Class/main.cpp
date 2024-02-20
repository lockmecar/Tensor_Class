#include <iostream>
#include "tensor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int q = 9;
	try
	{

	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}