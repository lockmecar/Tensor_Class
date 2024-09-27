#include "Layer.h"

Layer::Layer(int in, int out) :inNeu(in), outNeu(out), w(in, std::vector<float>(out)) {} //инициализируем вектора

void Layer::init()
{
	for (int row = 0; row < outNeu.size(); row++) //считаем по формуле: outNeu1 = inNeu1 * w11 + inNeu2 * w21 + ..   Объяснение: https://youtu.be/xMz7XSaqdRA?si=ju7vq6IEkttCDg6K&t=164
		for (int col = 0; col < inNeu.size(); col++)
			outNeu[row] += inNeu[row] * w[col][row];

	//тут надо добавить нелинейность (функцию активации)
}

void Layer::printInNeu()
{
	std::cout << "Входные нейроны: ";
	for (int i = 0; i < inNeu.size(); i++)
		std::cout << inNeu[i] << ", ";
	std::cout << std::endl;
}

void Layer::printOutNeu()
{
	std::cout << "Выходные нейроны: ";
	for (int i = 0; i < outNeu.size(); i++)
		std::cout << outNeu[i] << ", ";
	std::cout << std::endl;
}

