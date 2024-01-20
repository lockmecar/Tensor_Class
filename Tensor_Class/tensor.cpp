#include "tensor.h"

void tensor::print()
{

    for (int i = 0; i < tensor::size; i++) 
    {
        for (int j = 0; j < tensor::size; j++)
            std::cout << " " << tensor::array[i][j];
        std::cout << std::endl;
    }


}

tensor::tensor(int size)
{
    tensor::size = size;
}
