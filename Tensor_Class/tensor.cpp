#include "tensor.h"

void tensor::print()
{
    for (int i = 0; i < tensor::size; i++) 
    {
        for (int j = 0; j < tensor::size; j++)
            std::cout << " " << tensor::matrix[i][j];
        std::cout << std::endl;
    }
}

size_t& tensor::count()
{
    static size_t c = 0;
    return c;
}

tensor::tensor(int size_of_matrix)
{
    tensor::count()++;
    tensor::size = size_of_matrix;
    tensor::matrix = new float* [size_of_matrix];
    for (int i = 0; i < size_of_matrix; i++)
    {
        matrix[i] = new float[size_of_matrix];
    }
    std::cout << "Object created. " << "Count: " << tensor::count() << std::endl;
}

tensor::~tensor()
{
    tensor::count()--;
    for (int i = 0; i < size; i++)
    {
        delete[](matrix[i]);
    }
    delete[](matrix);
    std::cout << "Object destroyed. " << "Count: " << tensor::count() << std::endl;
}
