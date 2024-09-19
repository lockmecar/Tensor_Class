#include <iostream>
#include "tensor.h"
#include "dataset.h"
#include "Layer.h"
#include "Neuro.h"
#include <fstream>

/*ѕолезные ссылки
https://habr.com/ru/articles/514372/


*/
using namespace std;

void filldata(Ten3D &a, Ten3D &filter)
{

	ifstream data1("data.txt");//услови€ дл€ файла числа в одну строку без пробелов и переносов

	if (data1) //добавить к файла заголовок и возможность читать его в коде
	{
		char buff_ten[150];
		data1.getline(buff_ten, 150);
		data1.close();

		int q = 0;
		for(int z = 0; z < 3; z++)
			for (int y = 0; y < 7; y++)
				for (int x = 0; x < 7; x++)
				{
					a.set_object_of_matrix(x, y, z, int(buff_ten[q] - '0'));
					q++;
				}
		q = 0;
	}

	ifstream filter1("filter.txt");

	if (filter1) //добавить к файла заголовок и возможность читать его в коде
	{
		char buff_fil[54];
		filter1.getline(buff_fil, 54);
		filter1.close();

		int q = 0;
		for (int z = 0; z < 3; z++)
			for (int y = 0; y < 3; y++)
				for (int x = 0; x < 3; x++)
				{
					if(buff_fil[q]=='-')
					{
						filter.set_object_of_matrix(x, y, z, -int(buff_fil[q+1] - '0'));
						q+=2;
					}
					else 
					{
						filter.set_object_of_matrix(x, y, z, int(buff_fil[q] - '0'));
						q ++;
					}
				}
		q = 0;
	}
}

 
int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		//Dataset A("name");
		//A.importMnist("t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");
		//printData('z');

		Ten3D B(5, 5, 1, "b", 'r');//z не может быть 0(ошибки)

		InLayer C(B, 'n');
		C.genWeights(0,1);
		C.printWei();
		//C.printNeurones();
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}