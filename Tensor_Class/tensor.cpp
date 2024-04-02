#include "tensor.h"

void Ten2D::print()
{
    std::cout << std::endl;
    for (int i = 0; i < Ten2D::size_x; i++)
    {
        for (int j = 0; j < Ten2D::size_y; j++)
            std::cout << "\t" << Ten2D::matrix[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Ten2D::set_object_of_matrix(int x, int y, float value)
{
    Ten2D::matrix[x][y] = value;
}

void Ten2D::clear()
{
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
        {
            matrix[i][j] = 0;
        }
}

void Ten2D::ElemFunc(float (*func)(float))
{
    for (int i = 0; i < Ten2D::size_x; i++)
        for (int j = 0; j < Ten2D::size_y; j++)
            this->matrix[i][j] = func(matrix[i][j]);
}

float Ten2D::operator()(unsigned x, unsigned y)
{
    return Ten2D::matrix[x][y];
}


Ten2D& Ten2D::operator=(const Ten2D& b)
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

std::vector<float> Ten2D::matrix_to_vector()
{
    std::vector<float> result;
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            result.push_back(Ten2D::matrix[i][j]);

    return result;
}

Ten2D Ten2D::operator+(const Ten2D& b) const
{
    if ((b.size_x != size_x) || (b.size_y != size_y)) throw(std::length_error("TensorErrorOp+: Попытка сложить тензоры различной размерности"));
    Ten2D buf(*this);
    for (int i = 0; i < buf.size_x; i++)
        for (int j = 0; j < buf.size_y; j++)
            buf.matrix[i][j] += b.matrix[i][j];

    return buf;
}

Ten2D& Ten2D::operator+=(const Ten2D& b)
{
    if ((b.size_x != size_x) || (b.size_y != size_y)) throw(std::length_error("TensorErrorOp+=: Попытка сложить тензоры различной размерности"));
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            this->matrix[i][j] += b.matrix[i][j];

    return *this;
}


Ten2D Ten2D::operator*(const Ten2D& b) const
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp*: Попытка умножить тензоры различной размерности"));
    Ten2D buf(*this);
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

Ten2D& Ten2D::operator*= (const Ten2D& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp*=: Попытка умножить тензоры различной размерности"));
    Ten2D buf(*this);
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


Ten2D Ten2D::operator^(const float& b) const
{
    Ten2D buf(*this);
    for (int i = 0; i < this->size_x; i++) 
        for (int j = 0; j < this->size_y; j++) 
            buf.set_object_of_matrix(i, j, pow(buf(i,j), b));
    return buf;
}

Ten2D& Ten2D::operator^=(const float& b)
{
    Ten2D buf(*this);
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            buf.set_object_of_matrix(i, j, pow(buf(i, j), b));
    *this = buf;
    return *this;
}


Ten2D Ten2D::transp()
{
    Ten2D buf(*this);
    for (int i = 0; i < buf.size_x; i++)
        for (int j = 0; j < buf.size_y; j++)
            buf.matrix[i][j] = this->matrix[j][i];

    return buf;
}

Ten2D Ten2D::abs()
{
    Ten2D buf(*this);

    for (int i = 0; i < buf.size_x; i++)
        for (int j = 0; j < buf.size_y; j++)
            if(this->matrix[j][i]<0)
                buf.matrix[i][j] =(-1 * this->matrix[j][i]);

    return buf;
}

Ten2D Ten2D::sqrt()
{
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            this->matrix[i][j]=pow(this->matrix[i][j],0.5);
    return *this;
}


void Ten2D::fileout10(std::string NameOfFile)
{
    std::ofstream out;
    NameOfFile += ".txt";
    out.open(NameOfFile);
    for (int i = 0; i < Ten2D::size_x; i++)
    {
        for (int j = 0; j < Ten2D::size_y; j++)
            out << Ten2D::matrix[i][j] << "\t";
        out << std::endl;
    }
    out.close();
}


void Ten2D::fileout16(std::string NameOfFile)
{
    std::ofstream out;
    ftoul fu;
    NameOfFile += ".txt";
    out.open(NameOfFile);
    for (int i = 0; i < Ten2D::size_x; i++)
    {
        for (int j = 0; j < Ten2D::size_y; j++)
        {
            fu.input = Ten2D::matrix[i][j];
            out << std::hex << fu.output << "\t";
        }
        out << std::endl;
    }
    out.close();
}


Ten2D Ten2D::operator-(const Ten2D& b) const
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp-: Попытка отнять тензоры различной размерности"));
    Ten2D t1(*this);
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            t1.matrix[i][j] -= b.matrix[i][j];

    return t1;
}

Ten2D& Ten2D::operator-=(const Ten2D& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp-=: Попытка отнять тензоры различной размерности"));
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            this->matrix[i][j] -= b.matrix[i][j];
            
    return *this;
}


size_t& Ten2D::count()
{
    static size_t c = 0;
    return c;
}

Ten2D::Ten2D(int size_x, int size_y, std::string name, char mode)
{
    Ten2D::count()++;
    Ten2D::name = name;
    Ten2D::size_x = size_x;
    Ten2D::size_y = size_y;
    Ten2D::matrix = new float* [size_x];
    for (int i = 0; i < size_x; i++)
        matrix[i] = new float[size_y];

    if (mode == '0')
    {
        for(int i = 0; i < size_x; i++)
            for (int j = 0; j < size_y; j++)
            {
                matrix[i][j] = 0;
            }
        std::cout << "Object " << Ten2D::name << " created. " << "Mode: 0. " << "Count: " << Ten2D::count() << std::endl;
    }
    else if (mode == 'r')
    {
        srand(Ten2D::rand_seed);
        for (int i = 0; i < size_x; i++)
            for (int j = 0; j < size_y; j++)
            {
                matrix[i][j] = (static_cast <float> (rand()) / static_cast <float> (rand()));
            }
        std::cout << "Object " << Ten2D::name << " created. " << "Mode: r. " << "Count: " << Ten2D::count() << std::endl;
    }
}

Ten2D::Ten2D(int size_x, int size_y, std::string name)
{
    Ten2D::count()++;
    Ten2D::name = name;
    Ten2D::size_x = size_x;
    Ten2D::size_y = size_y;
    Ten2D::matrix = new float* [size_x];
    for (int i = 0; i < size_x; i++)
        matrix[i] = new float[size_y];
    std::cout << "Object " << Ten2D::name << " created. " << "Count: " << Ten2D::count() << std::endl;
}

Ten2D::Ten2D(const Ten2D& copied_obj)
{
    Ten2D::count()++;
    Ten2D::name = copied_obj.name + "_copy";
    Ten2D::size_x = copied_obj.size_x;
    Ten2D::size_y = copied_obj.size_y;
    Ten2D::matrix = new float* [copied_obj.size_x];

    for (int i = 0; i < copied_obj.size_x; i++)
        matrix[i] = new float[copied_obj.size_y];

    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            if (&copied_obj != this)
                this->matrix[i][j] = copied_obj.matrix[i][j];

    std::cout << "Object " << Ten2D::name << " created. " << "Count: " << Ten2D::count() << std::endl;
}

Ten2D::~Ten2D()
{
    Ten2D::count()--;
    for (int i = 0; i < size_x; i++)
        delete[](Ten2D::matrix[i]);
    delete[](Ten2D::matrix);
    std::cout << "Object " << Ten2D::name << " destroyed. " << "Count: " << Ten2D::count() << std::endl;
}
//------------------------------------------------------------------------------------------------------

Ten3D::Ten3D(int size_x, int size_y, int size_z, std::string name)
{
    Ten3D::count()++;
    Ten3D::name = name;
    Ten3D::size_x = size_x;
    Ten3D::size_y = size_y;
    Ten3D::size_z = size_z;
    Ten3D::matrix = new float** [size_x];
    for (int i = 0; i < size_x; i++)
    {
        matrix[i] = new float* [size_y];
        for (int j = 0; j < size_z; j++)
            matrix[i][j] = new float[size_z];
    }

    std::cout << "Object " << Ten3D::name << " created. " << "Count: " << Ten3D::count() << std::endl;
}

Ten3D::Ten3D(const Ten3D& copied_obj)
{
    Ten3D::count()++;
    Ten3D::name = copied_obj.name + "_copy";
    Ten3D::size_x = copied_obj.size_x;
    Ten3D::size_y = copied_obj.size_y;
    Ten3D::size_z = copied_obj.size_z;
    Ten3D::matrix = new float** [copied_obj.size_x];
    for (int i = 0; i < copied_obj.size_x; i++)
    {
        matrix[i] = new float* [copied_obj.size_y];
        for (int j = 0; j < copied_obj.size_z; j++)
            matrix[i][j] = new float[copied_obj.size_z];
    }
    for (int x = 0; x < copied_obj.size_x; x++)
        for (int y = 0; y < copied_obj.size_y; y++)
            for(int z = 0; z < copied_obj.size_z ; z++)
                if (&copied_obj != this)
                    this->matrix[x][y][z] = copied_obj.matrix[x][y][z];

    std::cout << "Object " << Ten3D::name << " created. " << "Count: " << Ten3D::count() << std::endl;
}

Ten3D::Ten3D(int size_x, int size_y, int size_z, std::string name, char mode)
{
    Ten3D::count()++;
    Ten3D::name = name;
    Ten3D::size_x = size_x;
    Ten3D::size_y = size_y;
    Ten3D::size_z = size_z;
    Ten3D::matrix = new float** [size_x];
    for (int i = 0; i < size_x; i++)
    {
        matrix[i] = new float* [size_y];
        for (int j = 0; j < size_z; j++)
            matrix[i][j] = new float[size_z];
    }

    if (mode == '0')
    {
        for (int x = 0; x < size_x; x++)
            for (int y = 0; y < size_y; y++)
                for (int z = 0; z < size_z; z++)
                    matrix[x][y][z] = 0;
        std::cout << "Object " << Ten3D::name << " created. " << "Mode: 0. " << "Count: " << Ten3D::count() << std::endl;
    }
    else if (mode == 'r')
    {
        srand(Ten3D::rand_seed);
        for (int x = 0; x < size_x; x++)
            for (int y = 0; y < size_y; y++)
                for (int z = 0; z < size_z; z++)
                    matrix[x][y][z] = (static_cast <float> (rand()) / static_cast <float> (rand()));
        std::cout << "Object " << Ten3D::name << " created. " << "Mode: r. " << "Count: " << Ten3D::count() << std::endl;
    }
}

void Ten3D::print()
{
    std::cout << std::endl;
    for (int i = 0; i < Ten3D::size_x; i++)
        for (int j = 0; j < Ten3D::size_y; j++)
            for(int k = 0; k < Ten3D::size_z; k++)
                std::cout << "tensor_"<<name<<"["<<i<<"]["<<j<<"]["<<k<<"] = " << Ten3D::matrix[i][j][k] << "\n";
    std::cout << std::endl;
}

void Ten3D::set_object_of_matrix(int x, int y, int z, float value)
{
    Ten3D::matrix[x][y][z] = value;
}

void Ten3D::clear()
{
    for (int x = 0; x < size_x; x++)
        for (int y = 0; y < size_y; y++)
            for (int z = 0; z < size_z; z++)
                matrix[x][y][z] = 0;
}

float Ten3D::operator()(unsigned x, unsigned y, unsigned z)
{
    return Ten3D::matrix[x][y][z];
}

Ten3D::~Ten3D()
{
    Ten3D::count()--;
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
            delete[](Ten3D::matrix[i][j]);
        delete[](Ten3D::matrix[i]);

    }
    delete[](Ten3D::matrix);
    std::cout << "Object " << Ten3D::name << " destroyed. " << "Count: " << Ten3D::count() << std::endl;
}

Ten3D Ten3D::operator+(const Ten3D& b) const
{
    if (b.size_x != size_x or b.size_y != size_y or b.size_z != size_z) throw(std::length_error("TensorErrorOp+: Попытка сложить тензоры различной размерности"));
    
    Ten3D buf(*this);
    for (int i = 0; i < buf.size_x; i++)
        for (int j = 0; j < buf.size_y; j++)
            for(int k = 0;k< buf.size_z; k++)
                buf.matrix[i][j][k] += b.matrix[i][j][k];
    return buf;
}

Ten3D& Ten3D::operator+=(const Ten3D& b)
{
    if (b.size_x != size_x or b.size_y != size_y or b.size_z != size_z) throw(std::length_error("TensorErrorOp+=: Попытка сложить тензоры различной размерности"));
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            for (int k = 0; k < this->size_z; k++)
                this->matrix[i][j][k] += b.matrix[i][j][k];
    return *this;
}

Ten3D& Ten3D::operator=(const Ten3D& b)
{
    if (b.size_x != size_x or b.size_y != size_y or b.size_z != size_z) throw(std::length_error("TensorErrorOp=: Попытка присвоить тензоры различной размерности"));
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            for (int k = 0; k < size_z; k++)
                if (&b != this)
                    this->matrix[i][j][k] = b.matrix[i][j][k];
    this->size_x = b.size_x;
    this->size_y = b.size_y;
    this->size_z = b.size_z;
    return *this;
}

Ten3D Ten3D::operator-(const Ten3D& b) const
{
    if (b.size_x != size_x or b.size_y != size_y or b.size_z != size_z) throw(std::length_error("TensorErrorOp-: Попытка отнять тензоры различной размерности"));
    Ten3D t1(*this);
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            for(int k = 0; k < size_z; k++)
                t1.matrix[i][j][k] -= b.matrix[i][j][k];
    return t1;
}

Ten3D& Ten3D::operator-=(const Ten3D& b)
{
    if (b.size_x != size_x or b.size_y != size_y or b.size_z != size_z) throw(std::length_error("TensorErrorOp-=: Попытка отнять тензоры различной размерности"));
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            for (int k = 0; k < this->size_z; k++)
                this->matrix[i][j][k] -= b.matrix[i][j][k];
    return *this;
}

Ten3D Ten3D::operator*(const Ten3D& b) const
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp*: Попытка умножить тензоры различной размерности"));// добавить что при z1!=y2 не раб
    Ten3D buf(*this);

    for (int x = 0; x < buf.size_x; x++)
        for (int y = 0; y < buf.size_y; y++)
            for (int z = 0; z < buf.size_z; z++)
            {
                float sum = 0;
                for (int k = 0; k < buf.size_z; k++)
                    sum += this->matrix[x][y][k] * b.matrix[x][k][z];
                buf.matrix[x][y][z] = sum;
            }
    return buf;
}

Ten3D Ten3D::operator^(const float& b) const
{
    Ten3D buf(*this);
    for (int i = 0; i < this->size_x; i++)
        for (int j = 0; j < this->size_y; j++)
            for (int k = 0; k < this->size_z; k++)
                buf.set_object_of_matrix(i, j, k, pow(buf(i, j, k), b));
    return buf;
}

size_t& Ten3D::count()
{
    static size_t c = 0;
    return c;
}

std::vector<float> Ten3D::matrix_to_vector()
{
    std::vector<float> result;
    for (int x = 0; x < size_x; x++)
        for (int y = 0; y < size_y; y++)
            for (int z = 0; z < size_z; z++)
            result.push_back(Ten3D::matrix[x][y][z]);

    return result;
}

void Ten3D::fileout10(std::string NameOfFile)
{
    std::ofstream out;
    NameOfFile += ".txt";
    out.open(NameOfFile);
    for (int i = 0; i < Ten3D::size_x; i++)
        for (int j = 0; j < Ten3D::size_y; j++)
            for (int k = 0; k < Ten3D::size_z; k++)
                out << "tensor_" << name << "[" << i << "][" << j << "][" << k << "] = " << Ten3D::matrix[i][j][k] << "\n";
    out << std::endl;
    out.close();
}


void Ten3D::fileout16(std::string NameOfFile)
{
    std::ofstream out;
    ftoul fu;
    NameOfFile += ".txt";
    out.open(NameOfFile);
    for (int i = 0; i < Ten3D::size_x; i++)
        for (int j = 0; j < Ten3D::size_y; j++)
            for (int k = 0; k < Ten3D::size_z; k++)
            {
                fu.input = Ten3D::matrix[i][j][k];
                out << "tensor_" << name << "[" << i << "][" << j << "][" << k << "] = " << fu.output << "\n";
            }
    out << std::endl;
    out.close();
}
