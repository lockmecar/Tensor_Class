#include "tensor.h"

void tensor::print()
{
    std::cout << std::endl;
    for (int i = 0; i < tensor::size_x; i++)
    {
        for (int j = 0; j < tensor::size_y; j++)
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
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp=: Попытка присвоить тензоры различной размерности"));
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            if (&b != this)
                this->matrix[i][j] = b.matrix[i][j];
    this->size_x = b.size_x;
    this->size_y = b.size_y;
    return *this;
}

tensor tensor::operator+(const tensor& b) const
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp+: Попытка сложить тензоры различной размерности"));
    tensor buf(*this);
    for (int i = 0; i < buf.size_x; i++)
        for (int j = 0; j < buf.size_y; j++)
            buf.matrix[i][j] += b.matrix[i][j];

    return buf;
}

tensor& tensor::operator+=(const tensor& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp+=: Попытка сложить тензоры различной размерности"));
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            this->matrix[i][j] += b.matrix[i][j];

    return *this;
}

tensor tensor::operator*(const tensor& b) const
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp*: Попытка умножить тензоры различной размерности"));
    tensor buf(*this);
    for (int i = 0; i < buf.size_x; i++)
        for (int j = 0; j < b.size_y; j++)
        {
            float sum = 0;
            for (int k = 0; k < buf.size_x; k++)
                sum += this->matrix[i][k] * b.matrix[k][j];
            buf.matrix[i][j] = sum;
        }
    return buf;
}

tensor& tensor::operator*= (const tensor& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp*=: Попытка умножить тензоры различной размерности"));
    tensor buf(*this);
    for (int i = 0; i < buf.size_x; i++)
        for (int j = 0; j < b.size_y; j++)
        {
            float sum = 0;
            for (int k = 0; k < buf.size_y; k++)
                sum += this->matrix[i][k] * b.matrix[k][j];
            buf.matrix[i][j] = sum;
        }
    *this = buf;
    return *this;
}

tensor tensor::operator^(const float& b) const
{
    tensor buf(*this);
    for (int i = 0; i < this->size; i++) 
        for (int j = 0; j < this->size; j++) 
            buf.set_object_of_matrix(i, j, pow(buf.get_object_of_matrix(i, j),b));
    return buf;
}

tensor tensor::transp()
{
    tensor buf(*this);
    for (int i = 0; i < buf.size_x; i++)
        for (int j = 0; j < buf.size_y; j++)
            buf.matrix[i][j] = this->matrix[j][i];

    return buf;
}

tensor tensor::abs()
{
    tensor buf(*this);

    for (int i = 0; i < buf.size_x; i++)
        for (int j = 0; j < buf.size_y; j++)
            if(this->matrix[j][i]<0)
                buf.matrix[i][j] =(-1 * this->matrix[j][i]);

    return buf;
}

tensor tensor::sqrt()
{
    for (int i = 0; i < this->size; i++)
        for (int j = 0; j < this->size; j++)
            this->matrix[i][j]=pow(this->matrix[i][j],0.5);
    return *this;
}


tensor tensor::operator-(const tensor& b) const
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp-: Попытка отнять тензоры различной размерности"));
    tensor t1(*this);
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            t1.matrix[i][j] -= b.matrix[i][j];

    return t1;
}

tensor& tensor::operator-=(const tensor& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp-=: Попытка отнять тензоры различной размерности"));
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            this->matrix[i][j] -= b.matrix[i][j];
            
    return *this;
}


size_t& tensor::count()
{
    static size_t c = 0;
    return c;
}

tensor::tensor(int size_x, int size_y, std::string name)
{
    tensor::count()++;
    tensor::name = name;
    tensor::size_x = size_x;
    tensor::size_y = size_y;
    tensor::matrix = new float* [size_x];
    for (int i = 0; i < size_x; i++)
        matrix[i] = new float[size_y];
    std::cout << "Object " << tensor::name << " created. " << "Count: " << tensor::count() << std::endl;
}

tensor::tensor(const tensor& copied_obj)
{
    tensor::count()++;
    tensor::name = copied_obj.name + "_copy";
    tensor::size_x = copied_obj.size_x;
    tensor::size_y = copied_obj.size_y;
    tensor::matrix = new float* [copied_obj.size_x];

    for (int i = 0; i < copied_obj.size_x; i++)
        matrix[i] = new float[copied_obj.size_y];

    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            if (&copied_obj != this)
                this->matrix[i][j] = copied_obj.matrix[i][j];

    std::cout << "Object " << tensor::name << " created. " << "Count: " << tensor::count() << std::endl;
}

tensor::~tensor()
{
    tensor::count()--;
    for (int i = 0; i < size_x; i++)
        delete[](tensor::matrix[i]);
    delete[](tensor::matrix);
    std::cout << "Object " << tensor::name << " destroyed. " << "Count: " << tensor::count() << std::endl;
}
