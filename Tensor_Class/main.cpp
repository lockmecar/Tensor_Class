#include <iostream>
#include "tensor.h"
#include "dataset.h"
#include "Layer.h"
#include "Neuro.h"
#include <fstream>

/*Полезные ссылки
https://habr.com/ru/articles/514372/
https://www.youtube.com/playlist?list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK //ютуб на чувака

*/

/*
Идеи
	1) возможно использовать ссылки в функции вместо векторов и классов (будет быстрее)
	2) размерность вх данных и вых д.??
	5) Flat ?
	6) функция потерь (узнать подробнее)
	7) придумать как в колбасе использовать конвалюшн
	8) обратный ход
Нужно
	при перемещении между слоями нужно реализовать функции
	результат функции в новый входной слой и тд до тех пор пока не будет последний слой
*/



/*
Что нужно:
	класс нейронки: ~
	класс слоя: -
	прямой ход: -
	обратный ход: -
	свертка: -
План работы:
	1) поменять класс слоя
	2) под новый класс слоя дописать класс нейронки
	3) реализовать прямой ход со случайными весами
	4) реализовать обратный ход:
		4.1) изучить алгоритм обратного распространения ошибки (видосы в тг):
			4.1.1) изучить градиентный спуск
			4.1.2) изучить стохастический градиентный спуск
		4.2) закодить эту шнягу
	5) реализовать свертку:
		5.1) изучить архитектуру сверточной нейронной сети (видос в тг):
		5.2) добавить сверточные слои
		5.3) подключить сверточные слои к обычным
	6) жестко тестировать, фиксить, допиливать
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


int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		
		Layer a(2, 3);
		a.printInNeu();
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}