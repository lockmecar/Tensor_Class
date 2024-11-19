#include "Neuro2.h"
#include <random>
#include <iostream>
#include <cmath>
#include <stdexcept>

Neuro2::Neuro2(std::vector<unsigned> numNeurones, Dataset& inData)
    : layers_t(numNeurones.size()), layers_h(numNeurones.size()),
      back_layers_t(numNeurones.size()), back_layers_h(numNeurones.size()),
      weights(numNeurones.size() - 1)
{
    // �������� �� ������������� ������� ������
    if (numNeurones[0] != (inData.img[0][0].getSizeX() * inData.img[0][0].getSizeY())) {
        throw std::invalid_argument("������: ������� ���� �� ������������� ������!");
    }

    // ������������� �����
    for (size_t j = 0; j < numNeurones.size(); ++j) {
        layers_h[j].resize(numNeurones[j]);
        
        if (j >= 1) {
            layers_t[j].resize(numNeurones[j]);
            back_layers_t[j].resize(numNeurones[j]);
            back_layers_h[j].resize(numNeurones[j]);
        }
    }

    // ������������� �����
    for (size_t i = 0; i < weights.size(); ++i) {
        weights[i].resize(numNeurones[i + 1], std::vector<float>(numNeurones[i], 0.0f));
    }

    back_layers_w.resize(weights.size());
    for (size_t w_layer = 0; w_layer < weights.size(); ++w_layer)
    {
        back_layers_w[w_layer].resize(weights[w_layer].size());
        for (size_t i = 0; i < weights[w_layer].size(); ++i)
        {
            back_layers_w[w_layer][i].resize(weights[w_layer][i].size(), 0.0f);
        }
    }

    error = 0;
}

void Neuro2::init(Dataset& inData)
{
    layers_h[0] = inData.img[0][0].matrix_to_vector(1); // ������� ������

    // ������������ ������� ��������
    for (auto& value : layers_h[0]) {
        value /= 255.0f;
    }

    // ��������� �����
    gener_w(0, 1);

    // ������ ���
    for (size_t i = 1; i < layers_h.size(); ++i) {
        for (size_t j = 0; j < layers_h[i].size(); ++j) {
            double sum = 0.0;
            for (size_t k = 0; k < layers_h[i - 1].size(); ++k) {
                sum += layers_h[i - 1][k] * weights[i - 1][j][k];
            }
            layers_t[i][j] = sum;
            layers_h[i][j] = (i != layers_h.size() - 1) ? relu(sum) : 0.0; // ��������� ���� � softmax
        }
    }

    softMax();
    backprop(inData.label[0][0]);
}

void Neuro2::printLayersT()
{
    std::cout << std::endl << "�������� ���� (�� ���������):" << std::endl;

    for (size_t layer = 0; layer < layers_t.size(); ++layer) {
        std::cout << "���� " << layer + 1 << ": ";

        for (size_t neuron = 0; neuron < layers_t[layer].size(); ++neuron) {
            std::cout << layers_t[layer][neuron] << " ";
        }

        std::cout << std::endl;
    }
    
}

void Neuro2::printLayersH()
{
    std::cout << std::endl << "�������� ���� (����� ���������):" << std::endl;

    for (size_t layer = 0; layer < layers_h.size(); ++layer) {
        std::cout << "���� " << layer + 1 << ": ";

        for (size_t neuron = 0; neuron < layers_h[layer].size(); ++neuron) {
            std::cout << layers_h[layer][neuron] << " ";
        }

        std::cout << std::endl;
    }
}

void Neuro2::print_w()
{
    std::cout << "���� ���������:" << std::endl;

    // �������� �� ������� ���� �����
    for (size_t layer = 0; layer < weights.size(); ++layer) {
        std::cout << "���� " << layer + 1 << ":" << std::endl << std::endl;

        // �������� �� ������� ������� �������� ����
        for (size_t neuron = 0; neuron < weights[layer].size(); ++neuron) {
            std::cout << "  ������ " << neuron + 1 << ": ";

            // ������� ���� ��� �������� �������
            for (size_t prev_neuron = 0; prev_neuron < weights[layer][neuron].size(); ++prev_neuron) {
                std::cout << weights[layer][neuron][prev_neuron] << " ";
            }
            std::cout << std::endl << std::endl;
        }
    }
}

void Neuro2::printError()
{
    std::cout << "������� �������� ������: " << error << std::endl;
}

void Neuro2::softMax()
{
    double sumExp = 0.0;
    for (float value : layers_t.back()) {
        sumExp += std::exp(value);
    }
    for (size_t i = 0; i < layers_h.back().size(); ++i) {
        layers_h.back()[i] = std::exp(layers_t.back()[i]) / sumExp;
    }
}

void Neuro2::backprop(int indx_label)
{
    // 1. ���������� ������ �� �������� ���� � �������������� �����-��������

    for (size_t i = 0; i < layers_h.back().size(); ++i) {
        // ���� i == indx_label, �� y_i = 1, ����� y_i = 0
        float target = (i == indx_label ? 1.0f : 0.0f);

        // �����-��������: -y_i * log(p_i), ��� p_i - ������������� �����������
        if (layers_h.back()[i] > 0) {  // �������� �� ������������ ���������
            error -= target * std::log(layers_h.back()[i]);
        }

        // ������ �� �������� ���� (dE/dh)
        back_layers_h.back()[i] = layers_h.back()[i] - target;
    }

    // 2. ���� ��������� ���������������
    for (int layer = layers_h.size() - 1; layer > 0; --layer) {
        // �������� dE/dt
        for (size_t i = 0; i < layers_t[layer].size(); ++i) {
            back_layers_t[layer][i] = back_layers_h[layer][i] * relu_derivative(layers_t[layer][i]);
        }

        // �������� ����� dE/dW
        for (size_t i = 0; i < layers_h[layer - 1].size(); ++i) {
            for (size_t j = 0; j < layers_t[layer].size(); ++j) {
                back_layers_w[layer - 1][j][i] += layers_h[layer - 1][i] * back_layers_t[layer][j];
            }
        }

        if (layer != 1) { // �������� dE/dh ��� ����������� ����
            for (size_t i = 0; i < layers_h[layer - 1].size(); ++i) {
                double sum = 0.0;
                for (size_t j = 0; j < layers_t[layer].size(); ++j) {
                    sum += back_layers_t[layer][j] * weights[layer - 1][j][i];
                }
                back_layers_h[layer - 1][i] = sum;
            }
        }
    }
}

void Neuro2::gener_w(float mean, float stddev)
{
    std::default_random_engine generator;
    std::normal_distribution<float> distribution(mean, stddev);
    for (auto& layer : weights) {
        for (auto& neuron : layer) {
            for (float& weight : neuron) {
                weight = distribution(generator);
            }
        }
    }
}

float Neuro2::relu(float x)
{
    return (x > 0) ? x : 0.0f;
}

float Neuro2::relu_derivative(float x)
{
    return (x > 0) ? 1.0f : 0.0f;
}

double Neuro2::leaky_Relu(float x)
{
    return (x >= 0) ? x : 0.01 * x;
}
