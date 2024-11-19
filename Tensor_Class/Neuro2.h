#pragma once
#include <vector>
#include "tensor.h"
#include "dataset.h"

class Neuro2
{
public:
    // �����������
    Neuro2(std::vector<unsigned> numNeurones, Dataset& inData);

    // ������������� ����
    void init(Dataset& inData);

    // ������� ��� �������
    void printLayersT();
    void printLayersH();
    void print_w();
    void printError();

private:
    // ��������� ����
    std::vector<std::vector<float>> layers_t;       // �������� �� ������� ��������� t = W * x
    std::vector<std::vector<double>> layers_h;      // �������� ����� ������� ��������� h = F(t)
    std::vector<std::vector<std::vector<float>>> weights;  // ������� ����� [����][������][�����]

    // ��� ��������� ���������������
    std::vector<std::vector<double>> back_layers_t; // ��������� dE/dt
    std::vector<std::vector<double>> back_layers_h; // ��������� dE/dh
    std::vector<std::vector<std::vector<float>>> back_layers_w; // ��������� dE/dW

    // ��� �������� ������
    float error=0.0f;

    // ��������������� �������
    float relu(float x);                       // ������� ��������� ReLU
    float relu_derivative(float x);            // ����������� ReLU
    double leaky_Relu(float x);                // Leaky ReLU (���� �����������)
    //double func(float x);                      // ����� ������� ��������� (���� �����������)
    void gener_w(float minVal, float maxVal);  // ��������� ��������� �����

    void softMax();                            // Softmax �� �������� ����
    //void crossEntropy(int indx_label);         // �����-����������� ������

    // ��������������� ������� ��� ������ � ���������
    std::vector<std::vector<float>> transp(const std::vector<std::vector<float>>& matrixA); // ����������������
    std::vector<std::vector<float>> multi(const std::vector<std::vector<float>>& matrixA,
        const std::vector<std::vector<float>>& matrixB); // ��������� ������

    // �������� ��������������� ������
    void backprop(int indx_label);

    // ���������� ����� 
    //void updateWeights(float alpha);          // �������� �������� alpha
};
