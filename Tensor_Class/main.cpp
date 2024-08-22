#include <iostream>
#include "tensor.h"
#include "fstream"

using namespace std;


//это переделать и внедрить
/*#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Функция для чтения 4 байтов как числа
int readInt(ifstream& file) {
    unsigned char buffer[4];
    file.read(reinterpret_cast<char*>(buffer), 4);
    return (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
}

// Функция для отображения изображения в консоли
void displayImage(const vector<unsigned char>& image, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            unsigned char pixel = image[i * cols + j];
            // Отображаем пиксели как символы (чем темнее пиксель, тем более "плотный" символ)
            if (pixel > 200)
                cout << " ";
            else if (pixel > 150)
                cout << ".";
            else if (pixel > 100)
                cout << "*";
            else if (pixel > 50)
                cout << "#";
            else
                cout << "@";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream file("t10k-images.idx3-ubyte", ios::binary);
    
    if (!file) {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }

    // Чтение заголовка файла
    int magicNumber = readInt(file);
    int numberOfImages = readInt(file);
    int rows = readInt(file);
    int cols = readInt(file);

    cout << "Магическое число: " << magicNumber << endl;
    cout << "Количество изображений: " << numberOfImages << endl;
    cout << "Размер изображений: " << rows << "x" << cols << endl;

    // Чтение изображений и их отображение
    for (int i = 0; i < numberOfImages; ++i) {
        vector<unsigned char> image(rows * cols);
        file.read(reinterpret_cast<char*>(image.data()), rows * cols);

        cout << "\nИзображение #" << i + 1 << ":" << endl;
        displayImage(image, rows, cols);

        // Ожидание нажатия клавиши для продолжения
        cout << "Нажмите Enter для отображения следующего изображения..." << endl;
        cin.get();
    }

    return 0;
}
*/

//void test() 
//{
//	ifstream testoviy("t10k-images.idx3-ubyte");
//	char buff[200];
//	testoviy.getline(buff, 200);
//	cout << buff<<endl;
//}

void filldata(Ten3D &a, Ten3D &filter)
{
	//для нормальной работы необходима возможность узнавать размер файла заранее
	//так же из файла узнавать размер тензера

	ifstream data1("data.txt");//условия для файла числа в одну строку без пробелов и переносов

	if (data1) //добавить к файла заголовок и возможность читать его в коде
	{
		char buff_ten[150];
		data1.getline(buff_ten, 150);
		data1.close();

		int q = 0;
		for(int z = 0; z < 3; z++)
			for (int y = 0; y < 7; y++)
				for (int x = 0; x < 7; x++)
				{
					a.set_object_of_matrix(x, y, z, int(buff_ten[q] - '0'));
					q++;
				}
		q = 0;
	}

	ifstream filter1("filter.txt");

	if (filter1) //добавить к файла заголовок и возможность читать его в коде
	{
		char buff_fil[54];
		filter1.getline(buff_fil, 54);
		filter1.close();

		int q = 0;
		for (int z = 0; z < 3; z++)
			for (int y = 0; y < 3; y++)
				for (int x = 0; x < 3; x++)
				{
					if(buff_fil[q]=='-')
					{
						filter.set_object_of_matrix(x, y, z, -int(buff_fil[q+1] - '0'));
						q+=2;
					}
					else 
					{
						filter.set_object_of_matrix(x, y, z, int(buff_fil[q] - '0'));
						q ++;
					}
				}
		q = 0;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		test();
		/*Ten3D data(7, 7, 3, "a", '0');
		Ten3D filter(3, 3, 3, "filter", '0');
		Ten3D result(3, 3, 1, "result", '0');
		filldata(data, filter);

		data.print();
		filter.print();

		data.convolution(filter, result, 2);

		result.print();*/
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}