#include "Neuro2.h"

Neuro2::Neuro2(std::vector<unsigned> numNeurones, Dataset &inData)
{

	layerSoftMax.resize(numNeurones[numNeurones.size() - 1]);//????????????
	w.resize(numNeurones.size() - 1);


	for (size_t i = 1; i <= /*ten.getSizeZ()*/1; i++)
	{
		if (numNeurones[0] != (inData.img[0][0].getSizeX()* inData.img[0][0].getSizeY()))
			std::cout << "АЛЯРМ, ВЫ ДОПУСТИЛИ КАСЯХ!!!!" << std::endl;//подправить на error
		  
		vector_Layers.resize(numNeurones.size());

		for (size_t j = 0; j < numNeurones.size(); j++)
			vector_Layers[j].resize(numNeurones[j]);

		vector_Layers[i-1] = inData.img[0][0].matrix_to_vector(i);

		for (size_t i = 1; i < vector_Layers.size(); i++)
			w[i - 1].resize(vector_Layers[i - 1].size() * vector_Layers[i].size());

		gener_w(0, 1);

		Layer_softMax();//обьединил layer и softMax

		crossEntropy(inData.label[0]);//????

		backprop(inData.label[0]);
	}
}

void Neuro2::printLayers()
{
	for (size_t i = 0; i < vector_Layers.size(); i++)
	{
		if (i != vector_Layers.size()-1) 
			std::cout << std::endl << "Слой " << i << ": ";
		else 
			std::cout << std::endl << "Soft Max" << ": ";

		for (size_t j = 0; j < vector_Layers[i].size(); j++)
			std::cout << vector_Layers[i][j]<<" ";
		std::cout << std::endl;
	}
}


float Neuro2::func(float x)
{
	return 1/(1+std::exp(-x));
}

float Neuro2::funcPrime(float x)
{
	float sig = func(x);
	return sig * (1 - sig);
}

void Neuro2::gener_w(float matO, float md)
{
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(matO, md);
	for (int i = 0; i < w.size(); i++) //iter????
		for(int j=0;j<w[i].size();j++)
			w[i][j]=(distribution(generator));
}


void Neuro2::crossEntropy(std::vector<int> lable)
{
	for (size_t i = 0; i < layerSoftMax.size(); i++)
		if(lable[i]!=0)// Избегаем log(0), так как это неопределенность
			error = -(lable[i] * std::log(layerSoftMax[i]));
}

void Neuro2::backprop(const std::vector<int> label)// Обратное распространение ошибки для выходного слоя
{
	for (int i = vector_Layers.size() - 1; i >= 1; i--)  // Цикл от последнего слоя к первому
	{
		for (size_t j = 0; j < vector_Layers[i].size(); j++)
		{
			if (i == vector_Layers.size() - 1)  // Для выходного слоя H
			{
				vector_backprop[i][j] = -(label[j] / (vector_Layers[i][j] + 1e-8));//dE/dH 
			}
			else if (i == vector_Layers.size() - 2) // Для выходного слоя T
			{
				vector_backprop[i][j] = vector_Layers[i][j] * (1 - vector_Layers[i][j]);
			}
			//else  // Для скрытых слоёв
			//{
			//	float delta = 0;
			//	for (size_t k = 0; k < vector_Layers[i + 1].size(); k++)
			//	{
			//		// Умножаем на весовые коэффициенты и на производную функции активации
			//		delta += vector_backprop[i + 1][k] * w[i][k];
			//	}
			//	vector_backprop[i][j] = delta * vector_Layers[i][j] * (1 - vector_Layers[i][j]); // Производная сигмоиды
			//}
		}
	}
}

void Neuro2::Layer_softMax()
{
		for (size_t i = 1; i < vector_Layers.size(); i++)
		{
			for (size_t j = 0; j < vector_Layers[i].size(); j++)
			{
				float sum = 0;
				for (size_t k = 0; k < vector_Layers[i - 1].size(); k++)
					sum += vector_Layers[i - 1][k] * w[i - 1][j];

				if (i == vector_Layers.size() - 1)
					vector_Layers[i][j] = sum;
				else
					vector_Layers[i][j] = func(sum);
			}
		}

		// Применяем softmax к последнему слою
		float sumExp = 0;
		for (size_t i = 0; i < vector_Layers.back().size(); i++)
			sumExp += std::exp(vector_Layers.back()[i]);

		for (size_t i = 0; i < layerSoftMax.size(); i++)
			layerSoftMax[i] = std::exp(vector_Layers.back()[i]) / sumExp;

		// Перезаписываем значения последнего слоя с нормализованными значениями softmax
		vector_Layers.emplace_back(layerSoftMax);
		vector_backprop.resize(vector_Layers.size());

		for (size_t i = 0; i < vector_Layers.size(); i++)
			vector_backprop[i].resize(vector_Layers[i].size());
}



void Neuro2::print_w()
{
	std::cout << std::endl << "Веса" << std::endl;
	for (size_t i = 0; i < w.size(); i++)
	{
		for (size_t j = 0; j < w[i].size(); j++)
			std::cout << w[i][j]<<" ";
		std::cout << std::endl;
	}
}


void Neuro2::printError()
{
	std::cout << std::endl << "Error: " << error << std::endl;
}


void Neuro2::print_vector_backprop()
{
	for (size_t i = 0; i < vector_backprop.size(); i++)
	{
		if (i != vector_backprop.size() - 1)
			std::cout << std::endl << "Слой " << i << ": ";
		else
			std::cout << std::endl << "Soft Max" << ": ";

		for (size_t j = 0; j < vector_backprop[i].size(); j++)
			std::cout << vector_backprop[i][j] << " ";
		std::cout << std::endl;
	}
}


//void Neuro2::Layer() 
//{
//	for (size_t i = 1; i < vector_Layers.size(); i++) 
//		for (size_t j = 0; j < vector_Layers[i].size(); j++) 
//		{
//			float sum = 0; 
//			for (size_t k = 0; k < vector_Layers[i - 1].size(); k++)
//				sum += vector_Layers[i - 1][k] * w[i - 1][j];
//			
//			if (i == vector_Layers.size() - 1) //на последнем слое обычно ф-ция активации не применяется
//				vector_Layers[i][j] =sum;      //сюда запихнуть софтмакс
//			else
//				vector_Layers[i][j] = func(sum); 
//		}
//}

//void Neuro2::softMax() {
//
//	float sumExp = 0;
//
//	// Вычисляем экспоненту для каждого нейрона в последнем слое и находим их сумму
//	for (size_t i = 0; i < vector_Layers.back().size(); i++)
//		sumExp += std::exp(vector_Layers.back()[i]);
//
//	// Нормализуем каждый элемент слоя
//	for (size_t i = 0; i < layerSoftMax.size(); i++)
//		layerSoftMax[i] = (std::exp(vector_Layers.back()[i]) / sumExp) /**100*/;//можно без 100 будет точнее
//}

