#include "tensor.h"

void Ten2D::print()
{
    std::cout << "\n\t--------";
    for (int index = 0; index <= size(Ten2D::name) + 1; index++)
        std::cout << "-";
    std::cout << std::endl << "\t Ten2D " << "\"" << Ten2D::name << "\"" << std::endl;
    std::cout << "\t--------";
    for (int index = 0; index <= size(Ten2D::name) + 1; index++)
        std::cout << "-";
    std::cout << std::endl;

    for (int y = 0; y < size_y; y++)
    {
        std::cout << "\t";
        for (int x = 0; x < size_x; x++)
            std::cout << " " << Ten2D::matrix[y][x];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Ten2D::set_object_of_matrix(int x, int y, float value)
{
    Ten2D::matrix[y][x] = value;
}

void Ten2D::clear()
{
    for (int y = 0; y < size_y; y++)
        for (int x = 0; x < size_x; x++)
        {
            matrix[y][x] = 0;
        }
}

void Ten2D::ElemFunc(float (*func)(float))
{
    for (int y = 0; y < Ten2D::size_y; y++)
        for (int x = 0; x < Ten2D::size_x; x++)
            this->matrix[y][x] = func(matrix[y][x]);
}

float Ten2D::operator()(unsigned y, unsigned x)
{
    return Ten2D::matrix[y][x];
}

Ten2D& Ten2D::operator=(const Ten2D& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp=: Попытка присвоить тензоры различной размерности"));
    for (int y = 0; y < size_y; y++)
        for (int x = 0; x < size_x; x++)
            if (&b != this)
                this->matrix[y][x] = b.matrix[y][x];
    this->size_x = b.size_x;
    this->size_y = b.size_y;
    return *this;
}

std::vector<float> Ten2D::matrix_to_vector()
{
    std::vector<float> result;
    for (int y = 0; y < size_y; y++)
        for (int x = 0; x < size_x; x++)
            result.push_back(Ten2D::matrix[y][x]);

    return result;
}

Ten2D Ten2D::operator+(const Ten2D& b) const
{
    if ((b.size_x != size_x) || (b.size_y != size_y)) throw(std::length_error("TensorErrorOp+: Попытка сложить тензоры различной размерности"));
    Ten2D buf(*this);
    for (int y = 0; y < buf.size_y; y++)
        for (int x = 0; x < buf.size_x; x++)
            buf.matrix[y][x] += b.matrix[y][x];

    return buf;
}

Ten2D& Ten2D::operator+=(const Ten2D& b)
{
    if ((b.size_x != size_x) || (b.size_y != size_y)) throw(std::length_error("TensorErrorOp+=: Попытка сложить тензоры различной размерности"));
    for (int y = 0; y < this->size_y; y++)
        for (int x = 0; x < this->size_x; x++)
            this->matrix[y][x] += b.matrix[y][x];

    return *this;
}

Ten2D Ten2D::operator*(const Ten2D& b) const
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp*: Попытка умножить тензоры различной размерности"));
    Ten2D buf(*this);
    for (int y = 0; y < buf.size_y; y++)
        for (int x = 0; x < b.size_x; x++)
        {
            float sum = 0;
            for (int i = 0; i < buf.size_x; i++)
                sum += this->matrix[y][i] * b.matrix[i][x];
            buf.matrix[y][x] = sum;
        }
    return buf;
}

Ten2D& Ten2D::operator*= (const Ten2D& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp*=: Попытка умножить тензоры различной размерности"));
    Ten2D buf(*this);
    for (int y = 0; y < buf.size_y; y++)
        for (int x = 0; x < b.size_x; x++)
        {
            float sum = 0;
            for (int i = 0; i < buf.size_y; i++)
                sum += this->matrix[y][i] * b.matrix[i][x];
            buf.matrix[y][x] = sum;
        }
    *this = buf;
    return *this;
}

Ten2D Ten2D::operator^(const float& b) const
{
    Ten2D buf(*this);
    for (int y = 0; y < this->size_y; y++) 
        for (int x = 0; x < this->size_x; x++) 
            buf.set_object_of_matrix(x, y, pow(buf(x,y), b));
    return buf;
}

Ten2D& Ten2D::operator^=(const float& b)
{
    Ten2D buf(*this);
    for (int y = 0; y < this->size_y; y++)
        for (int x = 0; x < this->size_x; x++)
            buf.set_object_of_matrix(x, y, pow(buf(x, y), b));
    *this = buf;
    return *this;
}

Ten2D Ten2D::transp()
{
    Ten2D buf(*this);
    for (int y = 0; y < buf.size_x; y++)
        for (int x = 0; x < buf.size_y; x++)
            buf.matrix[y][x] = this->matrix[x][y];

    return buf;
}

Ten2D Ten2D::abs()
{
    Ten2D buf(*this);

    for (int y = 0; y < buf.size_y; y++)
        for (int x = 0; x < buf.size_x; x++)
            if(this->matrix[y][x]<0)
                buf.matrix[y][x] =(-1 * this->matrix[y][x]);

    return buf;
}

Ten2D Ten2D::sqrt()
{
    for (int y = 0; y < this->size_y; y++)
        for (int x = 0; x < this->size_x; x++)
            this->matrix[y][x]=pow(this->matrix[y][x],0.5);
    return *this;
}

void Ten2D::fileout10(std::string NameOfFile)
{
    std::ofstream out;
    NameOfFile += ".txt";
    out.open(NameOfFile);
    for (int y = 0; y < Ten2D::size_y; y++)
    {
        for (int x = 0; x < Ten2D::size_x; x++)
            out << Ten2D::matrix[y][x] << "\t";
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
    for (int y = 0; y < Ten2D::size_y; y++)
    {
        for (int x = 0; x < Ten2D::size_x; x++)
        {
            fu.input = Ten2D::matrix[y][x];
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
    for (int x = 0; x < size_x; x++)
        for (int y = 0; y < size_y; y++)
            t1.matrix[y][x] -= b.matrix[y][x];

    return t1;
}

Ten2D& Ten2D::operator-=(const Ten2D& b)
{
    if (b.size_x != size_x) throw(std::length_error("TensorErrorOp-=: Попытка отнять тензоры различной размерности"));
    for (int x = 0; x < this->size_x; x++)
        for (int y = 0; y < this->size_y; y++)
            this->matrix[y][x] -= b.matrix[y][x];
            
    return *this;
}

Ten2D::Ten2D(int size_x, int size_y, std::string name, char mode)
{
    Ten2D::name = name;
    Ten2D::size_x = size_x;
    Ten2D::size_y = size_y;
    Ten2D::matrix = new float* [size_y];
    for (int y = 0; y < size_y; y++)
        matrix[y] = new float[size_x];

    if (mode == '0')
    {
        for(int y = 0; y < size_y; y++)
            for (int x = 0; x < size_x; x++)
            {
                matrix[y][x] = 0;
            }
        std::cout << "Ten2D \"" << Ten2D::name << "\" [NULL] created. Ten2D count: " << counter<Ten2D>::objects_alive << std::endl;
    }
    else if (mode == 'r')
    {
        srand(Ten2D::rand_seed);
        for (int y = 0; y < size_y; y++)
            for (int x = 0; x < size_x; x++)
            {
                matrix[y][x] = (static_cast <float> (rand()) / static_cast <float> (rand()));
            }
        std::cout << "Ten2D \"" << Ten2D::name << "\" [RANDOM] created. Ten2D count: " << counter<Ten2D>::objects_alive << std::endl;
    }
}

Ten2D::Ten2D(int size_x, int size_y, std::string name)
{
    Ten2D::name = name;
    Ten2D::size_x = size_x;
    Ten2D::size_y = size_y;
    Ten2D::matrix = new float* [size_y];
    for (int y = 0; y < size_y; y++)
        matrix[y] = new float[size_x];
    std::cout << "Ten2D \"" << Ten2D::name << "\" [NO_MODE] created. Ten2D count: " << counter<Ten2D>::objects_alive << std::endl;
}

Ten2D::Ten2D(const Ten2D& copied_obj)
{
    Ten2D::name = copied_obj.name + "_copy";
    Ten2D::size_x = copied_obj.size_x;
    Ten2D::size_y = copied_obj.size_y;
    Ten2D::matrix = new float* [copied_obj.size_y];

    for (int y = 0; y < copied_obj.size_y; y++)
        matrix[y] = new float[copied_obj.size_x];

    for (int x = 0; x < size_x; x++)
        for (int y = 0; y < size_y; y++)
            if (&copied_obj != this)
                this->matrix[y][x] = copied_obj.matrix[y][x];

    std::cout << "Ten2D \"" << Ten2D::name << "\" created. Ten2D count: " << counter<Ten2D>::objects_alive << std::endl;
}

Ten2D::~Ten2D()
{
    for (int y = 0; y < size_y; y++)
        delete[](Ten2D::matrix[y]);
    delete[](Ten2D::matrix);
    std::cout << "Ten2D \"" << Ten2D::name << "\" destroyed. Ten2D alive: " << counter<Ten2D>::objects_alive - 1 << std::endl;
}





Ten3D::Ten3D(int size_x, int size_y, int size_z, std::string name)
{
    Ten3D::name = name;
    Ten3D::size_x = size_x;
    Ten3D::size_y = size_y;
    Ten3D::size_z = size_z;
    Ten3D::matrix = new float** [size_z];
    for (int z = 0; z < size_z; z++)
    {
        matrix[z] = new float* [size_y];
        for (int y = 0; y < size_y; y++)
            matrix[z][y] = new float[size_x];
    }

    std::cout << "Ten3D \"" << Ten3D::name << "\" created. Ten3D count: " << counter<Ten3D>::objects_alive << std::endl;
}

Ten3D::Ten3D(const Ten3D& copied_obj)
{
    Ten3D::name = copied_obj.name + "_copy";
    Ten3D::size_x = copied_obj.size_x;
    Ten3D::size_y = copied_obj.size_y;
    Ten3D::size_z = copied_obj.size_z;
    Ten3D::matrix = new float** [copied_obj.size_z];
    for (int z = 0; z < copied_obj.size_z; z++)
    {
        matrix[z] = new float* [copied_obj.size_y];
        for (int y = 0; y < copied_obj.size_y; y++)
            matrix[z][y] = new float[copied_obj.size_x];
    }
    for (int z = 0; z < copied_obj.size_z; z++)
        for (int y = 0; y < copied_obj.size_y; y++)
            for(int x = 0; x < copied_obj.size_x ; x++)
                if (&copied_obj != this)
                    this->matrix[z][y][x] = copied_obj.matrix[z][y][x];

    std::cout << "Ten3D \"" << Ten3D::name << "\" created. Ten3D count: " << counter<Ten3D>::objects_alive << std::endl;
}

Ten3D::Ten3D(int size_x, int size_y, int size_z, std::string name, char mode)
{
    int start = 0;
    int end = 3;
    Ten3D::name = name;
    Ten3D::size_x = size_x;
    Ten3D::size_y = size_y;
    Ten3D::size_z = size_z;
    Ten3D::matrix = new float** [size_z];
    for (int z = 0; z < size_z; z++)
    {
        matrix[z] = new float* [size_y];
        for (int y = 0; y < size_y; y++)
            matrix[z][y] = new float[size_x];
    }

    if (mode == '0')
    {
        for (int z = 0; z < size_z; z++)
            for (int y = 0; y < size_y; y++)
                for (int x = 0; x < size_x; x++)
                    matrix[z][y][x] = 0;
        std::cout << "Ten3D \"" << Ten3D::name << "\" [NULL] created. Ten3D count: " << counter<Ten3D>::objects_alive << std::endl;
    }
    else if (mode == 'r')
    {
        srand(Ten3D::rand_seed);
        for (int z = 0; z < size_z; z++)
            for (int y = 0; y < size_y; y++)
                for (int x = 0; x < size_x; x++)
                    matrix[z][y][x] = (start + rand() % end);
        std::cout << "Ten3D \"" << Ten3D::name << "\" [RANDOM] created. Ten3D count: " << counter<Ten3D>::objects_alive << std::endl;
    }
}

void Ten3D::print()
{
    std::cout << "\n\t--------";
    for (int index = 0; index <= size(Ten3D::name) + 1; index++)
        std::cout << "-";
    std::cout << std::endl << "\t Ten3D " << "\"" << Ten3D::name << "\"" << std::endl;
    std::cout << "\t--------";
    for (int index = 0; index <= size(Ten3D::name) + 1; index++)
        std::cout << "-";
    std::cout << std::endl;

    for (int z = 0; z < size_z; z++)
    {
        std::cout << "z: " << z << std::endl;
        for (int y = 0; y < size_y; y++)
        {
            std::cout << "\t";
            for (int x = 0; x < size_x; x++)
                std::cout << " " << matrix[z][y][x];
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
}

void Ten3D::set_object_of_matrix(int x, int y, int z, float value)
{
    Ten3D::matrix[z][y][x] = value;
}

void Ten3D::clear()
{
    for (int z = 0; z < size_z; z++)
        for (int y = 0; y < size_y; y++)
            for (int x = 0; x < size_x; x++)
                matrix[z][y][x] = 0;
}

float Ten3D::operator()(unsigned x, unsigned y, unsigned z)
{
    return Ten3D::matrix[z][y][x];
}

Ten3D::~Ten3D()
{
    for (int z = 0; z < size_z; z++)
    {
        for (int y = 0; y < size_y; y++)
            delete[](Ten3D::matrix[z][y]);
        delete[](Ten3D::matrix[z]);

    }
    delete[](Ten3D::matrix);
    std::cout << "Ten3D \"" << Ten3D::name << "\" destroyed. Ten3D alive: " << counter<Ten3D>::objects_alive - 1 << std::endl;
}

Ten3D Ten3D::operator+(const Ten3D& b) const
{
    if (b.size_x != size_x or b.size_y != size_y or b.size_z != size_z) throw(std::length_error("TensorErrorOp+: Попытка сложить тензоры различной размерности"));
    
    Ten3D buf(*this);
    for (int z = 0; z < buf.size_z; z++)
        for (int y = 0; y < buf.size_y; y++)
            for(int x = 0; x < buf.size_x; x++)
                buf.matrix[z][y][x] += b.matrix[z][y][x];
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
    for (int z = 0; z < size_z; z++)
        for (int y = 0; y < size_y; y++)
            for (int x = 0; x < size_x; x++)
                if (&b != this)
                    this->matrix[z][y][x] = b.matrix[z][y][x];
    return *this;
}

Ten3D Ten3D::operator-(const Ten3D& b) const
{
    if (b.size_x != size_x or b.size_y != size_y or b.size_z != size_z) throw(std::length_error("TensorErrorOp-: Попытка отнять тензоры различной размерности"));
    Ten3D t1(*this);
    for (int z = 0; z < size_z; z++)
        for (int y = 0; y < size_y; y++)
            for (int x = 0; x < size_x; x++)
                t1.matrix[z][y][x] -= b.matrix[z][y][x];
    return t1;
}

Ten3D& Ten3D::operator-=(const Ten3D& b)
{
    if (b.size_x != size_x or b.size_y != size_y or b.size_z != size_z) throw(std::length_error("TensorErrorOp-=: Попытка отнять тензоры различной размерности"));
    for (int z = 0; z < size_z; z++)
        for (int y = 0; y < size_y; y++)
            for (int x = 0; x < size_x; x++)
                this->matrix[z][y][x] -= b.matrix[z][y][x];
    return *this;
}

Ten3D Ten3D::operator*(const Ten3D& b) const
{
    if (b.size_x != size_x or b.size_y!=size_y) throw(std::length_error("TensorErrorOp*: Попытка умножить тензоры различной размерности"));
    Ten3D buf(*this);

    for (int z = 0; z < size_z; z++)
        for (int y = 0; y < size_y; y++)
            for (int x = 0; x < size_x; x++)
            {
                float sum = 0;
                for (int i = 0; i < buf.size_x; i++)
                    sum += this->matrix[z][y][i] * b.matrix[z][i][x];
                buf.matrix[z][y][x] = sum;
            }
    return buf;
}

Ten3D& Ten3D::operator*=(const Ten3D& b)
{
    if (b.size_x != size_x or b.size_y != size_y) throw(std::length_error("TensorErrorOp*=: Попытка умножить тензоры различной размерности"));
    Ten3D buf(*this);

    for (int z = 0; z < size_z; z++)
        for (int y = 0; y < size_y; y++)
            for (int x = 0; x < size_x; x++)
            {
                float sum = 0;
                for (int i = 0; i < buf.size_x; i++)
                    sum += this->matrix[z][y][i] * b.matrix[z][i][x];
                buf.matrix[z][y][x] = sum;
            }
    *this = buf;
    return *this;
}

Ten3D Ten3D::operator^(const float& b) const
{
    Ten3D buf(*this);
    for (int z = 0; z < size_z; z++)
        for (int y = 0; y < size_y; y++)
            for (int x = 0; x < size_x; x++)
                buf.set_object_of_matrix(x, y, z, pow(buf(x, y, z), b));
    return buf;
}

std::vector<float> Ten3D::matrix_to_vector()
{
    std::vector<float> result;
    for (int z = 0; z < size_z; z++)
        for (int y = 0; y < size_y; y++)
            for (int x = 0; x < size_x; x++)
            result.push_back(Ten3D::matrix[z][y][x]);

    return result;
}

void Ten3D::padd()
{
    for (int z = 0; z < size_z; z++)
    {
        for (int y = 0; y < size_y; y++)
        {
            if (y == 0 or y == 6)
            {
                for (int x = 0; x < size_x; x++)
                    matrix[z][y][x] = 0;
            }
            else
                matrix[z][y][0] = 0; matrix[z][y][6] = 0;
        }
            
    }
}

void Ten3D::fileout10(std::string NameOfFile)
{
    std::ofstream out;
    NameOfFile += ".txt";
    out.open(NameOfFile);

    for (int z = 0; z < size_z; z++)
    {
        out << "z: " << z << std::endl;
        for (int y = 0; y < size_y; y++)
        {
            out << "\t";
            for (int x = 0; x < size_x; x++)
                out << " " << matrix[z][y][x];
            out << std::endl;
        }
    }

    out << std::endl;
    out.close();
}

void Ten3D::fileout16(std::string NameOfFile)
{
    std::ofstream out;
    ftoul fu;
    NameOfFile += ".txt";
    out.open(NameOfFile);
    for (int z = 0; z < size_z; z++)
    {
        out << "z: " << z << std::endl;
        for (int y = 0; y < size_y; y++)
        {
            out << "\t";
            for (int x = 0; x < size_x; x++)
            {
                fu.input = matrix[z][y][x];
                out << " " << std::hex << fu.output;
            }
            out << std::endl;
        }
    }
    out << std::endl;
    out.close();
}
