#include <iostream>
#include "tensor.h"
#include "fstream"

using namespace std;


void filldata(Ten3D &a, Ten3D &filter)
{
	ifstream data1("data.txt");

	if (data1) 
	{
		char buff[150];
		data1.getline(buff, 150);
		data1.close();

		int q = 0;
		for(int z = 0; z < 3; z++)
			for (int y = 0; y < 7; y++)
				for (int x = 0; x < 7; x++)
				{
					a.set_object_of_matrix(x, y, z, int(buff[q] - '0'));
					q++;
				}
		q = 0;
	}

	//data.set_object_of_matrix(0, 0, 0, 0);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Ten3D data(7, 7, 3, "a", '0');
		Ten3D filter(3, 3, 3, "filter", '0');
		//Ten3D result(3, 3, 1, "result", '0');
		filldata(data, filter);

		//data.print();
		//filter.print();

		//data.convolution(filter, result, 2);

		//result.print();
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}