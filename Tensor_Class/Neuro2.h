#pragma once
#include <vector>
#include "tensor.h"
#include "dataset.h"

class Neuro2
{
public:

    Neuro2(std::vector<unsigned> numNeurones, Dataset& inData);

    // ������������� ����
    void init(Dataset& inData, const int& current_step);


    void printLayersT();
    void printLayersH();
    void print_w();
    void printError();
    int result();

    //private:

    Dataset& inData; // ��������� ������ �� �������
    int current_step;   // ������� ��� ���������

    // ��������� ����
    std::vector<std::vector<float>> layers_t;       // �������� �� ������� ��������� t = W * x
    std::vector<std::vector<double>> layers_h;      // �������� ����� ������� ��������� h = F(t)
    std::vector<std::vector<std::vector<float>>> weights;  // ������� ����� [����][������][�����]

    // ��� ��������� ���������������
    std::vector<std::vector<double>> back_layers_t; // ��������� dE/dt
    std::vector<std::vector<double>> back_layers_h; // ��������� dE/dh
    std::vector<std::vector<std::vector<float>>> back_layers_w; // ��������� dE/dW

    // ��� �������� ������
    float cross_entropy = 0.0f;

    // ��������������� �������
    float relu(float x);                       // ������� ��������� ReLU
    float relu_derivative(float x);            // ����������� ReLU
    double leaky_Relu(float x);                // Leaky ReLU 
    double leaky_Relu_der(float x);
    void gener_w(float minVal, float maxVal);  // ��������� ��������� �����
    float softmax_derivative(float value);

    void softMax();                            // Softmax �� �������� ����

    // ��� ������ � ���������
    std::vector<std::vector<float>> transp(const std::vector<std::vector<float>>& matrixA); // ����������������
    std::vector<std::vector<float>> multi(const std::vector<std::vector<float>>& matrixA,
        const std::vector<std::vector<float>>& matrixB); // ��������� ������

    // �������� ��������������� ������
    void backprop(int& indx_label);

    // ���������� ����� 
    void updateWeights(const float& alpha);          // �������� �������� alpha
};
