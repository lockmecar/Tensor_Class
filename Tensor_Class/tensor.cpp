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

void tensor::set_object_of_matrix(int x, int y, float value)
{
    tensor::matrix[x][y] = value;
}

void tensor::clear()
{
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
        {
            matrix[i][j] = 0;
        }
}

float tensor::operator()(unsigned x, unsigned y)
{
    return tensor::matrix[x][y];
}

tensor& tensor::operator=(const tensor& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp=: ������� ��������� ������� ��������� �����������"));
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            if (&b != this)
                this->matrix[i][j] = b.matrix[i][j];
    this->size_x = b.size_x;
    this->size_y = b.size_y;
    return *this;
}

std::vector<float> tensor::matrix_to_vector()
{
    std::vector<float> result;
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            result.push_back(tensor::matrix[i][j]);

    return result;
}

tensor tensor::operator+(const tensor& b) const
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp+: ������� ������� ������� ��������� �����������"));
    tensor buf(*this);
    for (int i = 0; i < buf.size_x; i++)
        for (int j = 0; j < buf.size_y; j++)
            buf.matrix[i][j] += b.matrix[i][j];

    return buf;
}

tensor& tensor::operator+=(const tensor& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp+=: ������� ������� ������� ��������� �����������"));
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            this->matrix[i][j] += b.matrix[i][j];

    return *this;
}

tensor tensor::operator*(const tensor& b) const
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp*: ������� �������� ������� ��������� �����������"));
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
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp*=: ������� �������� ������� ��������� �����������"));
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
    for (int i = 0; i < this->size_x; i++) 
        for (int j = 0; j < this->size_y; j++) 
            buf.set_object_of_matrix(i, j, pow(buf(i,j), b));
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
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            this->matrix[i][j]=pow(this->matrix[i][j],0.5);
    return *this;
}


void tensor::fileout10(std::string b)
{
    std::ofstream out;
    b += ".txt";
    out.open(b);
    for (int i = 0; i < tensor::size_x; i++)
    {
        for (int j = 0; j < tensor::size_y; j++)
            out << tensor::matrix[i][j] << "\t";
        out << std::endl;
    }
    out.close();
}


void tensor::fileout16(std::string b)
{
    std::ofstream out;
    tensor::ftoul fu;
    b += ".txt";
    out.open(b);
    for (int i = 0; i < tensor::size_x; i++)
    {
        for (int j = 0; j < tensor::size_y; j++)
        {
            fu.input = tensor::matrix[i][j];
            out << std::hex << fu.output << "\t";
        }
        out << std::endl;
    }
    out.close();
}


tensor tensor::operator-(const tensor& b) const
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp-: ������� ������ ������� ��������� �����������"));
    tensor t1(*this);
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            t1.matrix[i][j] -= b.matrix[i][j];

    return t1;
}

tensor& tensor::operator-=(const tensor& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp-=: ������� ������ ������� ��������� �����������"));
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

tensor::tensor(int size_x, int size_y, std::string name, char mode)
{
    tensor::count()++;
    tensor::name = name;
    tensor::size_x = size_x;
    tensor::size_y = size_y;
    tensor::matrix = new float* [size_x];
    for (int i = 0; i < size_x; i++)
        matrix[i] = new float[size_y];

    if (mode == '0')
    {
        for(int i = 0; i < size_x; i++)
            for (int j = 0; j < size_y; j++)
            {
                matrix[i][j] = 0;
            }
        std::cout << "Object " << tensor::name << " created. " << "Mode: 0. " << "Count: " << tensor::count() << std::endl;
    }
    else if (mode == 'r')
    {
        srand(tensor::rand_seed);
        for (int i = 0; i < size_x; i++)
            for (int j = 0; j < size_y; j++)
            {
                matrix[i][j] = (static_cast <float> (rand()) / static_cast <float> (rand()));
            }
        std::cout << "Object " << tensor::name << " created. " << "Mode: r. " << "Count: " << tensor::count() << std::endl;
    }
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
