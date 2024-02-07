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

tensor& tensor::operator=(const tensor& b)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (&b != this)
                this->matrix[i][j] = b.matrix[i][j];
    this->size = b.size;
    return *this;
}

tensor tensor::operator+(const tensor& b) const
{
    if (b.size != size) throw(std::length_error("TensorErrorOp+: ������� ������� ������� ��������� �����������"));
    tensor buf(*this);
    for (int i = 0; i < buf.size; i++)
        for (int j = 0; j < buf.size; j++)
            buf.matrix[i][j] += b.matrix[i][j];

    return buf;
}

tensor& tensor::operator+=(const tensor& b)
{
    if (b.size != size) throw(std::length_error("TensorErrorOp+: ������� ������ ������� ��������� �����������"));
    for (int i = 0; i < this->size; i++)
        for (int j = 0; j < this->size; j++)
            this->matrix[i][j] += b.matrix[i][j];

    return *this;
}

tensor& tensor::operator*(const tensor& b)
{
    if (b.size != size) throw(std::length_error("TensorErrorOp+: ������� ������� ������� ��������� �����������"));
    tensor buf(*this);
    for (int i = 0; i < buf.size; i++) 
        for (int j = 0; j < b.size; j++)
        {
            float sum = 0;
            for (int k = 0; k < buf.size; k++) 
                sum += this->matrix[i][k] * b.matrix[k][j];
            buf.matrix[i][j] = sum;
        }
    return buf;
}


tensor tensor::operator-(const tensor& b) const
{
    if (b.size != size) throw(std::length_error("TensorErrorOp+: ������� ������ ������� ��������� �����������"));
    tensor t1(*this);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            t1.matrix[i][j] -= b.matrix[i][j];

    return t1;
}

tensor& tensor::operator-=(const tensor& b)
{
    if (b.size != size) throw(std::length_error("TensorErrorOp+: ������� ������ ������� ��������� �����������"));
    for (int i = 0; i < this->size; i++)
        for (int j = 0; j < this->size; j++)
            this->matrix[i][j] -= b.matrix[i][j];
            
    return *this;
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
        delete[](tensor::matrix[i]);
    delete[](tensor::matrix);
    std::cout << "Object " << tensor::name << " destroyed. " << "Count: " << tensor::count() << std::endl;
}
