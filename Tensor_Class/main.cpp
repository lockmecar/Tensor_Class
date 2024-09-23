#include <iostream>
#include "tensor.h"
#include "dataset.h"
#include "Layer.h"
#include "Neuro.h"
#include <fstream>

/*Полезные ссылки
https://habr.com/ru/articles/514372/


*/
using namespace std;

void filldata(Ten3D &a, Ten3D &filter)
{

	ifstream data1("data.txt");//условия для файла числа в одну строку без пробелов и переносов

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


void genWeights(std::vector<float>& weights,int size,float matO, float md)
{

	std::default_random_engine generator;
	std::normal_distribution<double> distribution(matO, md);
	for (int i = 0; i < size; i++) //iter????
		weights.push_back(distribution(generator));
}


void printWei(std::vector<float>& weights)
{
	for (int i = 0; i < weights.size(); i++)
		std::cout << weights[i] << std::endl;
}


 
int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		//Dataset A("name");
		//A.importMnist("t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");
		//printData('z');

		Ten3D B(3, 3, 1, "b", 'r');//z не может быть 0(ошибки)
		Neuro C({ 9,9,9 }, B);
		
		std::vector<float> weights;

		weights.reserve(27);

		genWeights(weights,27,0, 1);

		printWei(weights);

		//Layer C(B, 'n');
		//C.printA();
		C.step(weights);//исправить ошибку в лаере спп 35 стр
		
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}