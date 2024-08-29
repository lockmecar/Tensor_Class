#include "dataset.h"

Dataset::Dataset(std::string name)
{
	this->name = name;
}

void Dataset::printData()
{
	for (int i = 0; i < img.size(); i++)
	{
		this->img[i].print();
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
        this->img[i].print();

        unsigned char buffer[1];
        labelF.read(reinterpret_cast<char*>(buffer), 1);
        this->label.push_back(int(buffer[0]));
        std::cout << this->label[i] << std::endl;
    }

    


}
