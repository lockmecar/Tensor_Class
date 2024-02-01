#include "tensor.h"

void tensor::print()
{
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
    tensor t1(*this);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            t1.matrix[i][j] += a.matrix[i][j];

    return t1;
}

tensor& tensor::operator+=(const tensor& a)
{
    if (a.size != size) throw(std::length_error("TensorErrorOp+: Попытка отнять тензоры различной размерности"));
    for (int i = 0; i < this->size; i++)
        for (int j = 0; j < this->size; j++)
            this->matrix[i][j] += a.matrix[i][j];

    return *this;
}


tensor tensor::operator-(const tensor& a) const
{
    if (a.size != size) throw(std::length_error("TensorErrorOp+: Попытка отнять тензоры различной размерности"));
    tensor t1(*this);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            t1.matrix[i][j] -= a.matrix[i][j];

    return t1;
}

tensor& tensor::operator-=(const tensor& a)
{
    if (a.size != size) throw(std::length_error("TensorErrorOp+: Попытка отнять тензоры различной размерности"));
    for (int i = 0; i < this->size; i++)
        for (int j = 0; j < this->size; j++)
            this->matrix[i][j] -= a.matrix[i][j];
            
    return *this;
}





//
//tensor& tensor::operator*(const int& a)
//{
//    for (int i = 0; i < size; i++)
//        for (int j = 0; j < size; j++)
//            this->matrix[i][j] *= a;
//    return *this;
//}
//
//tensor& tensor::operator*(const float& a)
//{
//    for (int i = 0; i < size; i++)
//        for (int j = 0; j < size; j++)
//            this->matrix[i][j] *= a;
//    return *this;
//}
//
//tensor& tensor::operator*=(const int& a)
//{
//    for (int i = 0; i < size; i++)
//        for (int j = 0; j < size; j++)
//            this->matrix[i][j] *= a;
//    return *this;
//}
//
//tensor& tensor::operator*=(const float& a)
//{
//    for (int i = 0; i < size; i++)
//        for (int j = 0; j < size; j++)
//            this->matrix[i][j] *= a;
//    return *this;
//}

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

tensor::tensor(const tensor& copied_obj)
{
    tensor::count()++;
    tensor::name = copied_obj.name + "_copy";
    tensor::size = copied_obj.size;
    tensor::matrix = new float* [copied_obj.size];

    for (int i = 0; i < copied_obj.size; i++)
        matrix[i] = new float[copied_obj.size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (&copied_obj != this)
                this->matrix[i][j] = copied_obj.matrix[i][j];

    std::cout << "Object " << tensor::name << " created. " << "Count: " << tensor::count() << std::endl;
}

tensor::~tensor()
{
    tensor::count()--;
    for (int i = 0; i < size; i++)
        delete[](matrix[i]);
    delete[](matrix);
    std::cout << "Object " << tensor::name << " destroyed. " << "Count: " << tensor::count() << std::endl;
}
