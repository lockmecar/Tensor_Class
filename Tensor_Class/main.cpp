#include <iostream>
#include "tensor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		int q = 20;
		tensor a(3, 3, "a");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				a.set_object_of_matrix(i, j, q++);
			}
		}

		a.fileout10("test");//C:\Users\User\source\repos\lockmecar\Tensor_Class\Debug путь у меня
		a.fileout16("test16");
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}