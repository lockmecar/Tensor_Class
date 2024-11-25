#include "Neuro2.h"
#include <random>
#include <iostream>
#include <cmath>
#include <stdexcept>

Neuro2::Neuro2(std::vector<unsigned> numNeurones, Dataset& inData)
    :layers_t(numNeurones.size()),
    layers_h(numNeurones.size()),
    back_layers_t(numNeurones.size()),
    back_layers_h(numNeurones.size()),
    weights(numNeurones.size() - 1),
    inData(inData),
    current_step(0)
{
    if (numNeurones[0] != (inData.img[0][1].getSizeX() * inData.img[0][1].getSizeY())) {
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
    // ��������� �����
    gener_w(0, 1);
}

void Neuro2::init(Dataset& inData, const int& current_step)
{
    if (current_step < 0 || current_step >= inData.img[0].size()) {
        throw std::out_of_range("������: current_step ������� �� ������� ��������.");
    }
    //����� ��������� �������� � �����
    for (auto& layer : back_layers_w) {
        for (auto& neuron : layer) {
            std::fill(neuron.begin(), neuron.end(), 0.0f);
        }
    }

    for (auto& layer : back_layers_t) {
        std::fill(layer.begin(), layer.end(), 0.0);
    }
    for (auto& layer : back_layers_h) {
        std::fill(layer.begin(), layer.end(), 0.0);
    }

    cross_entropy = 0.0f;//������ ������
    this->current_step = current_step;
    layers_h[0] = inData.img[0][current_step].matrix_to_vector(1); // ������� ������

    // ������������ ������� ��������
    for (auto& value : layers_h[0]) {
        value /= 255.0f;
    }

    // ������ ���
    for (size_t i = 1; i < layers_h.size(); ++i)
    {
        for (size_t j = 0; j < layers_h[i].size(); ++j)
        {
            double sum = 0.0;
            for (size_t k = 0; k < layers_h[i - 1].size(); ++k)
                sum += layers_h[i - 1][k] * weights[i - 1][j][k];

            layers_t[i][j] = sum;
            layers_h[i][j] = (i != layers_h.size() - 1) ? leaky_Relu(sum) : 0.0; // ��������� ���� � softmax
        }
    }
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
    std::cout << "������� �������� ������: " << cross_entropy << std::endl;
}

int Neuro2::result()
{
    if (layers_h.back().empty()) {
        std::cerr << "������: ��������� ���� ����!" << std::endl;
        return 0;
    }

    // ������������� ���������� ��� ���������� ������������� �������� � ��� �������
    double max_value = layers_h.back()[0];
    size_t max_index = 0;

    // ����� ������������� �������� � ��� �������
    for (size_t i = 1; i < layers_h.back().size(); ++i) {
        if (layers_h.back()[i] > max_value) {
            max_value = layers_h.back()[i];
            max_index = i;
        }
    }

    // ����� ����������
    std::cout << "label:  = " << inData.label[0][current_step] << "|" << std::endl;
    std::cout << "�����:  = " << max_index << "|" << std::endl;
    std::cout << "����    = " << max_value << std::endl << std::endl;

    return (inData.label[0][current_step] == max_index) ? 1 : 0;
}

void Neuro2::softMax() {
    double maxVal = *std::max_element(layers_t.back().begin(), layers_t[layers_h.size() - 1].end());
    double sumExp = 0.0;
    for (size_t i = 0; i < layers_h.back().size(); ++i) {
        sumExp += exp(layers_t.back()[i] - maxVal);
    }
    for (size_t i = 0; i < layers_h.back().size(); ++i) {
        layers_h.back()[i] = exp(layers_t.back()[i] - maxVal) / sumExp;
    }
}


void Neuro2::backprop(int& indx_label)
{
    if (indx_label < 0 || indx_label >= inData.label[0].size()) {
        throw std::out_of_range("������: indx_label ������� �� ������� �����.");
    }

    // 1. ���������� ������ �� �������� ���� � �������������� �����-��������

    float cross_entropy = 0.0f;
    for (size_t i = 0; i < layers_h.back().size(); ++i) {
        float target = (i == indx_label ? 1.0f : 0.0f);
        cross_entropy -= target * std::log(layers_h.back()[i] + 1e-8); // �������� ��������� ����� ��� �������������� ������� �� ����
    }

    // 2. ���� ��������� ���������������
    for (int layer = layers_h.size() - 1; layer > 0; --layer) {
        // �������� dE/dt
        for (size_t i = 0; i < layers_t[layer].size(); ++i) {
            back_layers_t[layer][i] = back_layers_h[layer][i] * softmax_derivative(layers_t[layer][i]);//������� softmax_derivative
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

void Neuro2::updateWeights(const float& alpha)
{
    // ���������� ����� ��� ������� ����, ������� � 0-��
    for (size_t layer = 0; layer < layers_h.size() - 1; ++layer) {
        // ���������� ����� ����� ����� � ��������� �����
        for (size_t i = 0; i < layers_h[layer].size(); ++i) {
            for (size_t j = 0; j < layers_h[layer + 1].size(); ++j) {
                // ���������� ���� �� �������: W = W - alpha * dE/dW
                weights[layer][j][i] -= alpha * back_layers_w[layer][j][i];
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

float Neuro2::softmax_derivative(float value)
{
    return value * (1 - value);
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

double Neuro2::leaky_Relu_der(float x) {
    return (x >= 0) ? 1.0 : 0.01;
}
