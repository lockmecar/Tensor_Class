#pragma once
#include <vector>
#include "tensor.h"
#include "dataset.h"

class Neuro2
{
public:
    // Конструктор
    Neuro2(std::vector<unsigned> numNeurones, Dataset& inData);

    // Инициализация сети
    void init(Dataset& inData);

    // Функции для отладки
    void printLayersT();
    void printLayersH();
    void print_w();
    void printError();

private:
    // Структура сети
    std::vector<std::vector<float>> layers_t;       // Значения до функции активации t = W * x
    std::vector<std::vector<double>> layers_h;      // Значения после функции активации h = F(t)
    std::vector<std::vector<std::vector<float>>> weights;  // Матрицы весов [слой][нейрон][связи]

    // Для обратного распространения
    std::vector<std::vector<double>> back_layers_t; // Градиенты dE/dt
    std::vector<std::vector<double>> back_layers_h; // Градиенты dE/dh
    std::vector<std::vector<std::vector<float>>> back_layers_w; // Градиенты dE/dW

    // Для хранения ошибки
    float error=0.0f;

    // Вспомогательные функции
    float relu(float x);                       // Функция активации ReLU
    float relu_derivative(float x);            // Производная ReLU
    double leaky_Relu(float x);                // Leaky ReLU (если потребуется)
    //double func(float x);                      // Общая функция активации (если потребуется)
    void gener_w(float minVal, float maxVal);  // Генератор случайных весов

    void softMax();                            // Softmax на выходном слое
    //void crossEntropy(int indx_label);         // Кросс-энтропийная ошибка

    // Вспомогательные функции для работы с матрицами
    std::vector<std::vector<float>> transp(const std::vector<std::vector<float>>& matrixA); // Транспонирование
    std::vector<std::vector<float>> multi(const std::vector<std::vector<float>>& matrixA,
        const std::vector<std::vector<float>>& matrixB); // Умножение матриц

    // Обратное распространение ошибки
    void backprop(int indx_label);

    // Обновление весов 
    //void updateWeights(float alpha);          // Скорость обучения alpha
};
