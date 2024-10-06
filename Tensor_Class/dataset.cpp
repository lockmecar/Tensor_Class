#include "dataset.h"

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

Dataset::Dataset(std::string name, int numButches, std::string img, std::string label) // �������� ���, ���-�� ������, ���� � ����� � ���������� � ���� � ����� � �������� ��������
{
	this->name = name;
    this->numButches = numButches;

    // ��������� ������
    std::ifstream imgF(img, std::ios::binary); 
    std::ifstream labelF(label, std::ios::binary);

    // ������ ���������� ����� ����� � ����������, ���-�� �������� � �� ������
    int magicNumberImg = readIntImage(imgF);
    int numberOfImagesImg = readIntImage(imgF);
    int rows = readIntImage(imgF);
    int cols = readIntImage(imgF);

    // ������ ���������� ����� ����� � ��������� � ���-�� ��������
    int magicNumberLabel = readIntImage(labelF);
    int numberOfImagesLabel = readIntImage(labelF);

    // ����������� ����� ��� ������
    this->img.resize(this->numButches);
    this->label.resize(this->numButches);

    // ������� �����
    Ten3D buf(rows, cols, 1, "aboba");

    // ���������� �����
    for (int butch = 0; butch < this->numButches; butch++)
    {
        // ����������� ����� � ����� ��� �������� � ��������
        this->img[butch].reserve(numberOfImagesImg / this->numButches);
        this->label[butch].reserve(numberOfImagesLabel / this->numButches);

        // ���������� �������� � �����
        for(int element = 0; element < numberOfImagesImg / this->numButches; element++)
        {
            // ����� �������� �� ����� � ������� �����
            buf.imgToMatrix(imgF); // ����� � ����� ������ �� �����
            this->img[butch].push_back(buf); // ������� ����� � ������� ����� ��� ������ push_back()

            // ����� ������� �� ����� � ������� �����
            unsigned char buffer[1];
            labelF.read(reinterpret_cast<char*>(buffer), 1);
            this->label[butch].push_back(int(buffer[0]));
        }
    }
    std::cout << "������ MNIST �������� �������." << std::endl;
}

void Dataset::printData(char mode) // ����� �������� �� �������, ������: 'n' - �������, 'z' - ���������
{
    for (int butch = 0; butch < this->img.size(); butch++)
    {
        std::cout << "���� " << butch + 1 << ":" << std::endl;
        for (int elem = 0; elem < this->img[butch].size(); elem++)
            this->img[butch][elem].print(mode);
    }
}
