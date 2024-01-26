#include <iostream>
#include "tensor.h"
using namespace std;

int main()
{
	tensor tensor_1(6);

	tensor_1.array[0][0] = 1;
	tensor_1.array[3][3] = 2;
	tensor_1.print();

	return 0;
}