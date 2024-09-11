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

float Ten2D::operator()(int x, int y)
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

    //std::cout << "Ten3D \"" << Ten3D::name << "\" created. Ten3D count: " << counter<Ten3D>::objects_alive << std::endl;
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

void Ten3D::print(char mode)
{
    if (mode == 'n') 
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
                    std::cout << this->matrix[z][y][x] << " ";
                std::cout << std::endl;
            }
        }

        std::cout << std::endl;
    }
    else if(mode=='z')
    {
        std::cout << "\n\t{--------";
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
                {
                    if (this->matrix[z][y][x] > 200)
                        std::cout << " ";
                    else if (this->matrix[z][y][x] > 150)
                        std::cout << ".";
                    else if (this->matrix[z][y][x] > 100)
                        std::cout << "*";
                    else if (this->matrix[z][y][x] > 50)
                        std::cout << "#";
                    else
                        std::cout << "@";
                }
                std::cout << std::endl;
            }
        }

        std::cout << std::endl;
    }
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

int Ten3D::getSizeX()
{
    return this->size_x;
}

int Ten3D::getSizeY()
{
    return this->size_y;
}

int Ten3D::getSizeZ()
{
    return this->size_z;
}

void Ten3D::imgToMatrix(std::ifstream& file)
{
    unsigned char buffer[1];
    for (int y = 0; y < this->size_y; y++)
        for (int x = 0; x < this->size_x; x++)
        {
            file.read(reinterpret_cast<char*>(buffer), 1);
            this->matrix[0][y][x] = float(buffer[0]);// ??????????????????
        }




}

float Ten3D::operator()(int x, int y, int z)
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
    //std::cout << "Ten3D \"" << Ten3D::name << "\" destroyed. Ten3D alive: " << counter<Ten3D>::objects_alive - 1 << std::endl;
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

void Ten3D::convolutionHard(Ten3D &filter, Ten3D &result, int step)
{
    int xr = 0, yr = 0;
    float testa, testb, testc, test, qwe = 0, qwe1 = 0;
    for (int y = 1; y < 7; y += step)
    {
        for (int x = 1; x < 7; x += step)
        {

            test = 0;
            for (int z = 0; z < 3; z++)
            {
                testa = 0; testb = 0; testc = 0;

                qwe1 = this->matrix[z][y - 1][x - 1]; qwe = filter(0, 0, z); testa += qwe1 * qwe;
                qwe1 = this->matrix[z][y - 1][x];     qwe = filter(1, 0, z); testb += qwe1 * qwe;
                qwe1 = this->matrix[z][y - 1][x + 1]; qwe = filter(2, 0, z); testc += qwe1 * qwe;

                qwe1 = this->matrix[z][y][x - 1];     qwe = filter(0, 1, z); testa += qwe1 * qwe;
                qwe1 = this->matrix[z][y][x];         qwe = filter(1, 1, z); testb += qwe1 * qwe;
                qwe1 = this->matrix[z][y][x + 1];     qwe = filter(2, 1, z); testc += qwe1 * qwe;

                qwe1 = this->matrix[z][y + 1][x - 1]; qwe = filter(0, 2, z); testa += qwe1 * qwe;
                qwe1 = this->matrix[z][y + 1][x];     qwe = filter(1, 2, z); testb += qwe1 * qwe;
                qwe1 = this->matrix[z][y + 1][x + 1]; qwe = filter(2, 2, z); testc += qwe1 * qwe;

                test += testa + testb + testc;
            }
            result.set_object_of_matrix(xr, yr, 0, (result(xr, yr, 0) + test));
            if (xr < 2)xr++;
        }
        xr = 0;
        if (yr < 2)yr++;
    }
}

void Ten3D::convolution(Ten3D& filter, Ten3D& result, int step)
{
    if (this->size_z != filter.size_z)                                     throw(std::length_error("Ten3D_ConvErr_size_z: попытка свертки тензера с неравным количеством слоев"));
    else if ((this->size_x - filter.size_x) % step != 0)                   throw(std::length_error("Ten3D_ConvErr_size_f: попытка свертки не подходящим по размеру фильтром"));
    else if (((this->size_x - filter.size_x) / step) + 1 != result.size_x) throw(std::length_error("Ten3D_ConvErr_size_r: попытка свертки не подходящим по размеру результатом"));
    int xr = 0, yr = 0, zr = 0;
    int xd = 0, yd = 0, zd = 0;
    int xf = 0, yf = 0, zf = 0;
    float buf = 0;

    while (yr < result.size_y)
    {
        while (xr < result.size_x)
        {
            while (zf < filter.size_z)
            {
                while (yf < filter.size_y)
                {
                    while (xf < filter.size_x)
                    {
                        buf += this->matrix[zf][yd + yf][xd + xf] * filter.matrix[zf][yf][xf];
                        xf++;
                    }
                    xf = 0;
                    yf++;
                }
                yf = 0;
                zf++;
            }
            
            result.matrix[zr][yr][xr] = buf;
            buf = 0;
            xr++;
            xd += step;
            xf = 0; yf = 0; zf = 0;
        }
        xr = 0;
        xd = 0;
        yr++;
        yd += step;
    }
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


int readIntImage(std::ifstream& fileImage)
{
    unsigned char buffer[4];
    fileImage.read(reinterpret_cast<char*>(buffer), 4);
    int z = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
    return z;
}

int readIntLabel(std::ifstream& fileLabel) {
    unsigned char buffer[4];
    fileLabel.read(reinterpret_cast<char*>(buffer), 4);
    int z = (buffer[2] << 8) | buffer[3];
    return z;
}

//std::vector<Ten3D> Ten3D::importMNIST(std::string imageFile, std::string labelFile)
//{
//    std::vector<Ten3D> result;
//    std::ifstream fileImage(imageFile, std::ios::binary);
//    if (!fileImage) {
//        std::cerr << "Не удалось открыть файл!" << std::endl;
//        throw(std::length_error("")); // доделать исключение
//    }
//    std::ifstream fileLabel(labelFile, std::ios::binary);
//    if (!fileLabel) {
//        std::cerr << "Не удалось открыть файл!" << std::endl;
//        throw(std::length_error("")); // доделать исключение
//    }
//
//    int magicNumberImage = readIntImage(fileImage);
//    int magicNumberLabel = readIntLabel(fileLabel);
//    int numberOfImages = readIntImage(fileImage);
//    int rows = readIntImage(fileImage);
//    int cols = readIntImage(fileImage);
//
//    int q = 0;
//
//    for (int indexObj = 0; indexObj < numberOfImages; indexObj++)
//    {
//
//        result.push_back(Ten3D(rows, cols, 1, "name"));
//
//        char bufL[1];
//        fileLabel.read(bufL, 1);
//        listOfObjects[indexObj].label = int(bufL - '0');
//
//        char buff_ten[784];
//        fileImage.read(buff_ten, 784);
//        for (int y = 0; y < cols; y++)
//            for (int x = 0; x < rows; x++)
//            {
//                listOfObjects[indexObj].set_object_of_matrix(x, y, 0, float(buff_ten[q] - '0'));
//                q++;
//            }
//
//        listOfObjects[indexObj].print();
//        std::cin.get();
//    }
//    q = 0;
//
//    return result;
//}
