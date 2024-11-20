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


int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Dataset a("a", 100, "t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");
		//гипер параметры 
		float alpha = 0.01;


		Neuro2 C({784,4,3,10}, a);
		for (size_t i = 0; i < 36; i++)
		{
			cout << i << " ";
			C.init(a, alpha);
			//C.print_w();
			//C.printLayersT();
			//C.printLayersH();
			C.printError();
		}
		C.printLayersT();
		C.printLayersH();
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}