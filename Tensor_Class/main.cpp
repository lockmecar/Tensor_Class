#include <iostream>
#include "tensor.h"

using namespace std;

void convolution(Ten3D a, Ten3D filter, Ten2D &result)
{
	int step = 2;
	int testa, testb, testc, test, qwe = 0,qwe1=0;
	// Тут надо сделать алгоритм свертки по примеру с сайта https://russianblogs.com/article/291049586/
	for (int y = 1; y < 7; y += step)
	{
		for (int x = 1; x < 7; x+=step) 
		{
			
			test = 0;
			for (int z = 0; z < 3; z++)
			{
				testa = 0;
				testb = 0;
				testc = 0;

				qwe1 = a(x - 1, y - 1, z); qwe = filter(0, 0, z); testa += qwe1 * qwe;

				qwe1 = a(x, y - 1, z); qwe = filter(1, 0, z);     testb += qwe1 * qwe;

				qwe1 = a(x + 1, y - 1, z); qwe = filter(2, 0, z); testc += qwe1 * qwe;
				//-------------------------------------------------------------------------
				qwe1 = a(x - 1, y, z); qwe = filter(0, 1, z);     testa += qwe1 * qwe;
				
				qwe1 = a(x, y, z); qwe = filter(1, 1, z);         testb += qwe1 * qwe;

				qwe1 = a(x + 1, y, z); qwe = filter(2, 1, z);     testc += qwe1 * qwe;
				//-------------------------------------------------------------------------
				qwe1 = a(x - 1, y + 1, z); qwe = filter(0, 2, z); testa += qwe1 * qwe;

				qwe1 = a(x, y + 1, z); qwe = filter(1, 2, z);     testb += qwe1 * qwe;

				qwe1 = a(x + 1, y + 1, z); qwe = filter(2, 2, z); testc += qwe1 * qwe;


				test += testa + testb + testc;
			}
			int i=0,j=0;
			

			while (true) 
			{
				if (i == 2)
				{
					i = 0;
					break;
				}
				while (true) 
				{
					if (j == 2)
					{
						j = 0;
						break;
					}
					
					result.set_object_of_matrix(i,j,result(i,j)+test);
					j++;
					break;
				}
				i++;
				break;
			}
			
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Ten3D a(7, 7, 3, "a", 0);
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

		Ten3D filter(3, 3, 3, "filter", 'r');

		filter.set_object_of_matrix(0, 0, 0, 1); filter.set_object_of_matrix(1, 0, 0, 1); filter.set_object_of_matrix(2, 0, 0, -1);
		filter.set_object_of_matrix(0, 1, 0, -1); filter.set_object_of_matrix(1, 1, 0, 0); filter.set_object_of_matrix(2, 1, 0, 1);
		filter.set_object_of_matrix(0, 2, 0, -1); filter.set_object_of_matrix(1, 2, 0, -1); filter.set_object_of_matrix(2, 2, 0, 0);

		filter.set_object_of_matrix(0, 0, 1, -1); filter.set_object_of_matrix(1, 0, 1, 0); filter.set_object_of_matrix(2, 0, 1, -1);
		filter.set_object_of_matrix(0, 1, 1, 0); filter.set_object_of_matrix(1, 1, 1, 0); filter.set_object_of_matrix(2, 1, 1, -1);
		filter.set_object_of_matrix(0, 2, 1, 1); filter.set_object_of_matrix(1, 2, 1, -1); filter.set_object_of_matrix(2, 2, 1, 0);

		filter.set_object_of_matrix(0, 0, 2, 0); filter.set_object_of_matrix(1, 0, 2, 1); filter.set_object_of_matrix(2, 0, 2, 0);
		filter.set_object_of_matrix(0, 1, 2, 1); filter.set_object_of_matrix(1, 1, 2, 0); filter.set_object_of_matrix(2, 1, 2, 1);
		filter.set_object_of_matrix(0, 2, 2, 0); filter.set_object_of_matrix(1, 2, 2, -1); filter.set_object_of_matrix(2, 2, 2, 1);

		Ten2D result(3, 3, "result", '0');
		a.print();
		filter.print();
		result.print();
		convolution(a, filter, result);

		result.print();
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}