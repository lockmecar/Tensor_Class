#include "tensor.h"

void tensor::print()
{
    std::cout << std::endl;
    for (int i = 0; i < tensor::size; i++) 
    {
        for (int j = 0; j < tensor::size; j++)
            std::cout << "\t" << tensor::matrix[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

float tensor::get_object_of_matrix(int x, int y)
{
    return tensor::matrix[x][y];
}

void tensor::set_object_of_matrix(int x, int y, float value)
{
    tensor::matrix[x][y] = value;
}

tensor& tensor::operator=(const tensor& a)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (&a != this)
                this->matrix[i][j] = a.matrix[i][j];
    this->size = a.size;
    return *this;
}

tensor tensor::operator+(const tensor& a) const
{
    if (a.size != size) throw(std::length_error("TensorErrorOp+: Попытка сложить тензоры различной размерности"));
    tensor t1(this->size,"BUF");
    t1 = *this;
    for (int i = 0; i < t1.size; i++)
        for (int j = 0; j < t1.size; j++)
            t1.matrix[i][j] += a.matrix[i][j];

    return t1;
}

size_t& tensor::count()
{
    static size_t c = 0;
    return c;
}

tensor::tensor(int size_of_matrix, std::string name)
{
    tensor::count()++;
    tensor::name = name;
    tensor::size = size_of_matrix;
    tensor::matrix = new float* [size_of_matrix];
    for (int i = 0; i < size_of_matrix; i++)
        matrix[i] = new float[size_of_matrix];
    std::cout << "Object " << tensor::name << " created. " << "Count: " << tensor::count() << std::endl;
}

tensor::tensor(const tensor& t1)
{
    tensor::count()++;
    tensor::name = "TMP_BUF";
    tensor::size = t1.size;
    tensor::matrix = t1.matrix;
    std::cout << "Object " << tensor::name << " created. " << "Count: " << tensor::count() << std::endl;
}

tensor::~tensor()
{
    tensor::count()--;
    for (int i = 0; i < size; i++)
        delete[](tensor::matrix[i]);
    delete[](tensor::matrix);
    std::cout << "Object " << tensor::name << " destroyed. " << "Count: " << tensor::count() << std::endl;
}
