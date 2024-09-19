#include "dataset.h"

Dataset::Dataset(std::string name)
{
	this->name = name;
    this->numOfBatches = 1;
    this->numElemInBatch = 0;
}

void Dataset::printData(char mode)
{
    if (mode=='n')
    {
        for (int i = 0; i < img.size(); i++)
            this->img[i].print('n');
    }
    else if (mode=='z') 
    {
        for (int i = 0; i < img.size(); i++)
            this->img[i].print('z');
    }
}

void Dataset::addData(Ten3D& value)
{
	this->img.push_back(value);
}

static int readIntImage(std::ifstream& fileImage)
{
    unsigned char buffer[4];
    fileImage.read(reinterpret_cast<char*>(buffer), 4);
    int z = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
    return z;
}

static int readIntLabel(std::ifstream& fileLabel) {
    unsigned char buffer[4];
    fileLabel.read(reinterpret_cast<char*>(buffer), 4);
    int z = (buffer[2] << 8) | buffer[3];
    return z;
}

void Dataset::importMnist(std::string img, std::string label)
{
    std::ifstream imgF(img, std::ios::binary);
    std::ifstream labelF(label, std::ios::binary);

    int magicNumberImg = readIntImage(imgF);
    int numberOfImagesImg = readIntImage(imgF);
    int rows = readIntImage(imgF);
    int cols = readIntImage(imgF);

    int magicNumberLabel = readIntImage(labelF);
    int numberOfImagesLabel = readIntImage(labelF);

    this->img.reserve(numberOfImagesImg);
    this->label.reserve(numberOfImagesLabel);

    Ten3D buf(rows, cols, 1, "aboba");

    for (int i = 0; i < numberOfImagesImg; i++)
    {
        buf.imgToMatrix(imgF);
        this->img.push_back(buf);

        unsigned char buffer[1];
        labelF.read(reinterpret_cast<char*>(buffer), 1);
        this->label.push_back(int(buffer[0]));
    }

    this->numElemInBatch = this->img.size() / this->numOfBatches;
    std::cout << "Импорт MNIST завершен успешно." << std::endl;
}

void Dataset::divideIntoBatches(int numberOfBatches)
{
    if (this->img.size() % numberOfBatches != 0) std::cout << "Ошибка. Кол-во элементов датасета должно делится на кол-во батчей без остатка." << std::endl;
    else
    {
        this->numOfBatches = numberOfBatches;
        this->numElemInBatch = this->img.size() / numberOfBatches;
        std::cout << "Датасет поделен на батчи, кол-во батчей: " << this->numOfBatches << ", кол-во элементов в каждом батче: " << this->numElemInBatch << std::endl;
    }
}

std::vector<Ten3D> Dataset::getBatch(int batchId)
{
    std::vector<Ten3D> result;
    result.reserve(numElemInBatch);
    for (int i = 0; i < this->numElemInBatch; i++)
    {
        result.push_back(this->img[i + (this->numElemInBatch * batchId)]);
    }
    return result;
}
