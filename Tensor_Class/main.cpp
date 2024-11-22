#include <iostream>
#include "tensor.h"
#include "dataset.h"
#include "Neuro2.h"
#include <fstream>

/*Полезные ссылки
https://habr.com/ru/articles/514372/

https://www.youtube.com/playlist?list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK //ютуб на чувака

https://habr.com/ru/articles/846088/


Что нужно:
	класс нейронки: ~
	класс слоя: ~
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


int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Dataset a("a", 100, "t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");
		//гиперпараметры 
		const float alpha = 0.001;
		int current_step = 0;
		int good = 0;
		Neuro2 C({784,4,3,10}, a);
		for (current_step; current_step < 100; current_step++)
		{
			std::cout << current_step << ") " << std::endl;
			for (size_t i = 0; i < 100; i++)
			{
				C.init(a, alpha, current_step);
				//C.result();
			}
			good+=C.result();
		}
		cout << endl<< good << endl;
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}