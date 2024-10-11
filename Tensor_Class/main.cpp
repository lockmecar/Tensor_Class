#include <iostream>
#include "tensor.h"
#include "dataset.h"
#include "Neuro2.h"
#include <fstream>

/*ѕолезные ссылки
https://habr.com/ru/articles/514372/

https://www.youtube.com/playlist?list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK //ютуб на чувака

https://habr.com/ru/articles/846088/


„то нужно:
	класс нейронки: ~
	класс сло€: ~
	пр€мой ход: -
	обратный ход: -
	свертка: -
ѕлан работы:
	1) помен€ть класс сло€
	2) под новый класс сло€ дописать класс нейронки
	3) реализовать пр€мой ход со случайными весами
	4) реализовать обратный ход:
		4.1) изучить алгоритм обратного распространени€ ошибки (видосы в тг):
			4.1.1) изучить градиентный спуск
			4.1.2) изучить стохастический градиентный спуск
		4.2) закодить эту шн€гу
	5) реализовать свертку:
		5.1) изучить архитектуру сверточной нейронной сети (видос в тг):
		5.2) добавить сверточные слои
		5.3) подключить сверточные слои к обычным
	6) жестко тестировать, фиксить, допиливать
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

		Dataset a("a", 100, "t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");

		//Ten3D B(28, 28, 1, "B", A);


		Neuro2 C({ 784,10,5,10}, a);

		//B.print_w();

		//C.printLayers();
		
		//C.print_softMax();

		//C.printError();

		C.print_vector_backprop();
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}