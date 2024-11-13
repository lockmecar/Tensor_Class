#include "Neuro2.h"

Neuro2::Neuro2(std::vector<unsigned> numNeurones, Dataset& inData): layers_t(numNeurones.size()), layers_h(numNeurones.size()),
																	back_layers_t(numNeurones.size()), back_layers_h(numNeurones.size()),
																	weights(numNeurones.size() - 1)
{
	for (size_t i = 1; i <= /*ten.getSizeZ()*/1; i++)
	{
		if (numNeurones[0] != (inData.img[0][0].getSizeX() * inData.img[0][0].getSizeY()))
			std::cout << "АЛЯРМ, ВЫ ДОПУСТИЛИ КАСЯХ!!!!" << std::endl;//подправить на error

		for (size_t j = 0; j < numNeurones.size(); j++) // инициализируем каждый слой
		{
			layers_h[j].resize(numNeurones[j]);
			if(j>=1)
			{
				layers_t[j].resize(numNeurones[j]);
				back_layers_t[j].resize(numNeurones[j]);
				back_layers_h[j].resize(numNeurones[j]);
			}
		}
	}
	error = 0;
}

//Neuro2::Neuro2(std::vector<unsigned> numNeurones, std::vector<float> debug)
//{
//	layerSoftMax.resize(numNeurones[numNeurones.size() - 1]);//????????????
//	w.resize(numNeurones.size() - 1);
//
//
//	for (size_t i = 1; i <= /*ten.getSizeZ()*/1; i++)
//	{
//
//		vector_Layers.resize(numNeurones.size());
//
//		for (size_t j = 0; j < numNeurones.size(); j++)
//			vector_Layers[j].resize(numNeurones[j]);
//
//		vector_Layers[i - 1] = debug;
//
//		for (size_t i = 1; i < vector_Layers.size(); i++)
//			w[i - 1].resize(vector_Layers[i - 1].size() * vector_Layers[i].size());
//
//		gener_w(0, 1);
//		//print_w();
//		for (size_t i = 0; i < 1; i++)// узнать до скольки
//		{
//			Layer();
//			print_w();
//			printLayers();
//			print_softMax();
//			printError();
//
//			//crossEntropy(3);//????
//			//backprop(3);
//			//apdate(0.01);
//		}
//	}
//}


void Neuro2::init(Dataset& inData)
{
	layers_h[0] = inData.img[0][0].matrix_to_vector(1); // заливаем картинку в x

	// нормализация входных значений
	for (int j = 0; j < layers_h[0].size(); j++) 
	{
		layers_h[0][j] /= 255;
	}

	for (size_t j = 1; j < layers_t.size(); j++) // инициализация весов
		weights[j - 1].resize(layers_h[j - 1].size() * layers_h[j].size());

	gener_w(0, 1); // заполняем веса случайными значениями

	// прямой ход
	for (int i = 1; i < layers_h.size(); i++) 
	{

		for (size_t j = 0; j < layers_h[i].size(); j++)
		{
			double sum = 0;
			for (int k = 0; k < layers_h[i-1].size(); k++)
			{
				int indx2 = k + (j * layers_h[i - 1].size());
				sum+=layers_h[i-1][k] * weights[i-1][indx2];
			}
			layers_t[i][j] = sum;
			if (i != layers_h.size() - 1) 
			{
				layers_h[i][j] = leaky_Relu(sum);//func , leaky_Relu 
			}
		}
	}

	softMax();
	crossEntropy(inData.label[0][0]);
}

/*for (size_t i = 1; i < layers_t.size(); i++)
	{

		int j = 0;
		while (j < layers_t[i].size())
		{
			//float sum = 0;
			int k = 0;
			while (k < layers_t[i - 1].size())
			{
				int indx2 = k + (j * layers_t[i - 1].size());
				float b1 = weights[i - 1][indx2];
				
				float b2 = layers_h[i][k];

				layers_t[i][j] += b2 * b1;
				
				k++;
			}

			if (i != layers_t.size() - 1)
				layers_h[i][j] = func(layers_t[i][j]);
			j++;
		}


	}

	softMax();*/


void Neuro2::softMax() {

	double sumExp = 0;
	for (size_t i = 0; i < layers_t[layers_t.size()-1].size(); i++)
	{
		float b1 = layers_t[layers_t.size() - 1][i];
		sumExp += std::exp(b1);
	}

	for (size_t i = 0; i < layers_h[layers_h.size() - 1].size(); i++)
	{
		layers_h[layers_h.size() - 1][i] = (std::exp(layers_t[layers_t.size() - 1][i]) / sumExp);
	}

	//vector_backprop.resize(layers_h.size() - 1);
	//for (int i = vector_backprop.size() - 1; i >= 0; i--)
		//vector_backprop[i].resize(vector_Layers[i + 1].size());
}

//void Neuro2::backprop(int indx_lable)
//{
//	// dE/dt
//	for (int i = 0; i < layers_h.size(); i++)
//	{
//		if (i != indx_lable)
//		{
//			this->back_layers_t[3][indx_lable] = this->layers_h[3][indx_lable];
//		}
//		else
//		{
//			this->back_layers_t[3][indx_lable] = this->layers_h[3][indx_lable] -= 1;
//		}
//	}
//	
//	// dE/dW
//	std::vector<std::vector<float>> test;
//	std::vector<std::vector<float>> de_dw = transp(test);
//
//}

//void Neuro2::backprop(int indx_label)
//{
//	// Шаг 1: Вычисляем градиент ошибки на выходном слое с использованием кросс-энтропийной функции
//	int output_layer = layers_h.size() - 1;  // Индекс выходного слоя
//
//	// Инициализируем градиенты ошибки для выходного слоя
//	back_layers_h[output_layer].resize(layers_h[output_layer].size());
//
//	// Вычисляем градиент ошибки для каждого нейрона выходного слоя
//	for (size_t i = 0; i < layers_h[output_layer].size(); ++i) {
//		back_layers_h[output_layer][i] = layers_h[output_layer][i] - (i == indx_label ? 1.0 : 0.0);
//	}
//
//	// Шаг 2: Обратное распространение ошибки на скрытые слои
//	for (int layer = output_layer - 1; layer >= 0; --layer) {
//		back_layers_h[layer].resize(layers_h[layer].size());
//
//		for (size_t j = 0; j < layers_h[layer].size(); ++j) {
//			double sum_error = 0.0;
//
//			// Используем веса между текущим слоем и следующим для вычисления суммы ошибок
//			for (size_t k = 0; k < layers_h[layer + 1].size(); ++k) {
//				sum_error += back_layers_h[layer + 1][k] * weights[layer][j];
//			}
//
//			// Применяем производную функции активации для нейрона
//			back_layers_h[layer][j] = sum_error * ((layers_h[layer][j] > 0) ? 1.0 : 0.01);  // для Leaky ReLU, где f'(x) = 0.01 при x < 0
//		}
//	}
//
//	// Шаг 3: Вычисление градиентов для весов
//	for (size_t layer = 0; layer < weights.size(); ++layer) {
//		back_layers_w[layer].resize(weights[layer].size());
//
//		for (size_t i = 0; i < weights[layer].size(); ++i) {
//			back_layers_w[layer][i].resize(weights[layer][i].size());
//
//			for (size_t j = 0; j < weights[layer][i].size(); ++j) {
//				// Градиент для веса равен градиенту ошибки нейрона, умноженному на значение активации предыдущего слоя
//				back_layers_w[layer][i][j] = back_layers_h[layer + 1][j] * layers_h[layer][i];
//			}
//		}
//	}
//}


//void Neuro2::backprop1(int indx_lable)
//{
//	for (int i = vector_backprop.size() - 1; i >= 0; i--)
//		for (size_t j = 0; j < vector_backprop[i].size(); j++)
//			if (i == (vector_Layers.size() - 2))
//			{
//				if (j + 1 == indx_lable)
//					for (int k = vector_Layers[i + 1].size() - 1; k >= 0; k--)
//						vector_backprop[i][k] = 1 - vector_Layers[i + 1][k];
//			}
//
//			else
//			{
//				double delta = 0.0;
//				for (size_t k = 0; k < vector_Layers[i].size() - 1; k++)
//				{
//					double b1 = vector_Layers[i][k];
//					double b2 = w[i][j * vector_Layers[i].size() + k];
//					delta += b1 * b2;
//				}
//				vector_backprop[i][j] = delta * relu_derivative(vector_Layers[i + 1][j]);
//			}
//}


//void Neuro2::apdate(float alpha)
//{
//
//	for (size_t i = 0; i < vector_Layers.size() - 1; i++) // Проходим по всем слоям, кроме входного
//		for (size_t j = 0; j < vector_Layers[i + 1].size(); j++) // Проходим по всем нейронам текущего слоя
//			for (size_t k = 0; k < vector_Layers[i].size(); k++) // Для каждого нейрона текущего слоя обновляем веса, которые его соединяют с предыдущим слоем
//			{
//
//				float d1 = vector_Layers[i][k];
//				int d3 = j * vector_Layers[i].size() + k;
//				float d2 = alpha * vector_backprop[i][j];
//
//				w[i][d3] -= d2 * d1;
//			}
//}



double Neuro2::func(float x)
{
	return 1 / (1 + exp(-x)); 
	//return (x >= 0) ? x : 0.01 * (std::exp(x) - 1);
	//return (x > 0) ? x : 0.01 * x;
}


float Neuro2::relu(float x)
{
	return (x > 0) ? x : 0;
}


double Neuro2::leaky_Relu(float x)
{
	return (x >= 0) ? x : x * 0.01;
}



float Neuro2::relu_derivative(float x)
{
	float sig = func(x);
	return sig * (1.0f - sig);
	//return (x > 0) ? 1 : 0; 
	//return (x >= 0) ? 1 : 0.01 * std::exp(x);
	//return (x > 0) ? 1 : 0.01;
}


void Neuro2::gener_w(float matO, float md)
{
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(matO, md);
	for (int i = 0; i < weights.size(); i++) //iter????
		for (int j = 0; j < weights[i].size(); j++)
			weights[i][j] = (distribution(generator));
}


void Neuro2::crossEntropy(int indx_lable)
{
	error = -(std::log(layers_h[layers_h.size()-1][indx_lable]));
}

std::vector<std::vector<float>> Neuro2::transp(std::vector<std::vector<float>>& matrixA)
{
	std::vector<std::vector<float>> matrixB(matrixA[0].size(), std::vector<float>(matrixA.size()));

	int n = matrixA.size();
	int m = matrixA[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrixB[j][i] = matrixA[i][j];
		}
	}

	return matrixB;
}

std::vector<std::vector<float>> Neuro2::multi(const std::vector<std::vector<float>>& matrixA, const std::vector<std::vector<float>>& matrixB)
{
	int rowsA = matrixA.size();
	int colsA = matrixA[0].size();
	int rowsB = matrixB.size();
	int colsB = matrixB[0].size();

	if (colsA != rowsB) {
		throw std::invalid_argument("Умножение невозможно: количество столбцов первой матрицы не равно количеству строк второй матрицы.");
	}

	std::vector< std::vector<float>> result(rowsA, std::vector<float>(colsB, 0));

	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsB; j++) {
			for (int k = 0; k < colsA; k++) {
				result[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}

	return result;
}


void Neuro2::print_w()
{
	std::cout << std::endl << "Веса " << std::endl;
	for (size_t i = 0; i < weights.size(); i++)
	{
		for (size_t j = 0; j < weights[i].size(); j++)
			std::cout << weights[i][j] << " ";
		std::cout << std::endl;
	}
}

void Neuro2::printLayersT()
{
	for (size_t i = 0; i < layers_t.size(); i++)
	{
		std::cout << std::endl << "Слой t " << i << ": ";
		for (size_t j = 0; j < layers_t[i].size(); j++)
			std::cout << layers_t[i][j] << " ";
		std::cout << std::endl;
	}
}

void Neuro2::printLayersH()
{
	for (size_t i = 0; i < layers_h.size(); i++)
	{
		std::cout << std::endl << "Слой h " << i << ": ";
		for (size_t j = 0; j < layers_h[i].size(); j++)
			std::cout << layers_h[i][j] << " ";
		std::cout << std::endl;
	}
}


void Neuro2::printError()
{
	std::cout << std::endl << "Error: " << error << std::endl;
}


//void Neuro2::print_vector_backprop()
//{
//	for (size_t i = 0; i < vector_backprop.size(); i++)
//	{
//		std::cout << std::endl << "Слой " << i << ": ";
//		for (size_t j = 0; j < vector_backprop[i].size(); j++)
//			std::cout << vector_backprop[i][j] << " ";
//		std::cout << std::endl;
//	}
//}
//
//void Neuro2::print_softMax()
//{
//	std::cout << std::endl << "softMax: ";
//	for (size_t i = 0; i < layers_h[layers_h.size()-1].size(); i++)
//	{
//		std::cout <<" ["<<i<<"] " << layers_h[layers_h.size() - 1][i] << " ";
//	}
//	std::cout << std::endl;
//}
