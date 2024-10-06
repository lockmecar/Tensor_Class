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

Dataset::Dataset(std::string name, int numButches, std::string img, std::string label) // передаем имя, кол-во батчей, путь к файлу с картинками и путь к файлу с подписью картинок
{
	this->name = name;
    this->numButches = numButches;

    // открываем потоки
    std::ifstream imgF(img, std::ios::binary); 
    std::ifstream labelF(label, std::ios::binary);

    // читаем магическое число файла с картинками, кол-во картинок и их размер
    int magicNumberImg = readIntImage(imgF);
    int numberOfImagesImg = readIntImage(imgF);
    int rows = readIntImage(imgF);
    int cols = readIntImage(imgF);

    // читаем магическое число файла с подписями и кол-во подписей
    int magicNumberLabel = readIntImage(labelF);
    int numberOfImagesLabel = readIntImage(labelF);

    // резервируем место для батчей
    this->img.resize(this->numButches);
    this->label.resize(this->numButches);

    // создаем буфер
    Ten3D buf(rows, cols, 1, "aboba");

    // перебираем батчи
    for (int butch = 0; butch < this->numButches; butch++)
    {
        // резервируем место в батче для картинок и подписей
        this->img[butch].reserve(numberOfImagesImg / this->numButches);
        this->label[butch].reserve(numberOfImagesLabel / this->numButches);

        // перебираем элементы в батче
        for(int element = 0; element < numberOfImagesImg / this->numButches; element++)
        {
            // пишем картинку из файла в элемент батча
            buf.imgToMatrix(imgF); // пишем в буфер данные из файла
            this->img[butch].push_back(buf); // заносим буфер в элемент батча при помощи push_back()

            // пишем подпись из файла в элемент батча
            unsigned char buffer[1];
            labelF.read(reinterpret_cast<char*>(buffer), 1);
            this->label[butch].push_back(int(buffer[0]));
        }
    }
    std::cout << "Импорт MNIST завершен успешно." << std::endl;
}

void Dataset::printData(char mode) // вывод датасета на консоль, режимы: 'n' - числами, 'z' - символами
{
    for (int butch = 0; butch < this->img.size(); butch++)
    {
        std::cout << "Батч " << butch + 1 << ":" << std::endl;
        for (int elem = 0; elem < this->img[butch].size(); elem++)
            this->img[butch][elem].print(mode);
    }
}
