#include <iostream>

using namespace std;

class Matrix {
private:
     int height;
     int width;
    int** matrix;
public:
    Matrix() : height(0), width(0), matrix(nullptr) {

    }

    void Delete() {
        for (int i = 0; i < height; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void new_memory(int value_Height, int value_Width) {
        height = value_Height;
        width = value_Width;
        matrix = new int* [height];
        for (int i = 0; i < height; i++) {
            matrix[i] = new int[width];
        }

    }

    Matrix( int value_Height,  int value_Width) : height(0), width(0), matrix(nullptr) { // конструктор, в котором можно задать размер матрицы
        if (value_Height > 0 && value_Width > 0) {
            new_memory(value_Height, value_Width);
        }
    }

    friend istream& operator >> (istream& input, Matrix& sourse)
    {
        for (int i = 0; i < sourse. GetHeight(); i++) {
            for (int j = 0; j < sourse.GetWidth(); j++) {
                input >> sourse.matrix[i][j];
            }
        }
        return input;
    }

    friend ostream& operator << (ostream& output, const Matrix& source)
    {
        for (int i = 0; i < source.GetHeight(); i++) {
            for (int j = 0; j < source.GetWidth(); j++) {
                output << source.matrix[i][j] << " ";
            }
            output << endl;
        }
        return output;
    }


     int GetHeight() const { // получение высоты матрицы
            return height;
    }

    int GetWidth() const{ // получение ширины матрицы
            return width;
     }


    int* operator[](int index) {
        if (index < 0 || index >= height) {
            cout << "Out of range";
            throw out_of_range("Index out of bounds");
        }
        else {
            return matrix[index];
        }
    }

   const int* operator[](int index) const {
        if (index < 0 || index >= height) {
            cout << "Out of range";
            throw out_of_range("Index out of bounds");
        }
        else {
            return matrix[index];
        }
    }

    void replace(const Matrix& other) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    Matrix(const Matrix& other) : height(0), width(0), matrix(nullptr) //конструктор копирования
    {
        cout << "Calling copy constructor" << endl;
        new_memory(other.height, other.width);
        replace(other);
    }

    Matrix& operator=(const Matrix& object) {//операор присваивания
        cout << "Calling operator =" << endl;
        if (this == &object) {
            return *this;
        }
        Delete();
        new_memory(object.height, object.width);
        replace(object);
            return *this; //разыменование указателя
    }

    ~Matrix() {
        Delete();
    }
};


int main()
{
    Matrix a(3, 3);
    cin >> a;
    cout << a;
    unsigned w = a.GetHeight();
    cout << w << endl;
    unsigned h = a.GetWidth();
    cout << h << endl;
    Matrix d(a);
    cout << d;
    Matrix e;
    e = a;
    cout << e;

    a[0][0] = 10;
    cout << a;
    return 0;
}
