#include <iostream>

using namespace std;

class Matrix {
private:
     int height;
     int width;
    int** matrix;

    void Matrix_Delete() {
        for (int i = 0; i < height; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void Matrix_NewMemory(int value_Height, int value_Width) {
        height = value_Height;
        width = value_Width;
        matrix = new int* [height];
        for (int i = 0; i < height; i++) {
            matrix[i] = new int[width];
        }

    }

    void Matrix_Replace(const Matrix& other) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

     int * Matrix_Index(int index) const {
        if (index < 0 || index >= height) {
            throw out_of_range("Index out of bounds");
        }
        else{
            return matrix[index];
        }
    }

public:
    Matrix() : height(0), width(0), matrix(nullptr) {

    }

    Matrix( int value_Height,  int value_Width) : height(0), width(0), matrix(nullptr) { // конструктор, в котором можно задать размер матрицы
        if (value_Height > 0 && value_Width > 0) {
            Matrix_NewMemory(value_Height, value_Width);
        }
    }

    friend istream& operator >> (istream& input, Matrix& sourse)
    {
        for (int i = 0; i < sourse.Matrix_GetHeight(); i++) {
            for (int j = 0; j < sourse.Matrix_GetWidth(); j++) {
                input >> sourse.matrix[i][j];
            }
        }
        return input;
    }

    friend ostream& operator << (ostream& output, const Matrix& source)
    {
        for (int i = 0; i < source.Matrix_GetHeight(); i++) {
            for (int j = 0; j < source.Matrix_GetWidth(); j++) {
                output << source.matrix[i][j] << " ";
            }
            output << endl;
        }
        return output;
    }


     int Matrix_GetHeight() const { // получение высоты матрицы
            return height;
    }

    int Matrix_GetWidth() const{ // получение ширины матрицы
            return width;
     }


    int* operator[](int index) {
        return Matrix_Index(index);
    }

   const int* operator[](int index) const {
       return Matrix_Index(index);
    }


    Matrix(const Matrix& other) : height(0), width(0), matrix(nullptr) //конструктор копирования
    {
        cout << "Calling copy constructor" << endl;
        Matrix_NewMemory(other.height, other.width);
        Matrix_Replace(other);
    }

    Matrix& operator=(const Matrix& object) {//операор присваивания
        cout << "Calling operator =" << endl;
        if (this == &object) {
            return *this;
        }
        Matrix_Delete();
        Matrix_NewMemory(object.height, object.width);
        Matrix_Replace(object);
            return *this; //разыменование указателя
    }

    ~Matrix() {
        Matrix_Delete();
    }
};


int main()
{
    Matrix a(3, 3);
    cin >> a;
    cout << a;
    unsigned w = a.Matrix_GetHeight();
    cout << w << endl;
    unsigned h = a.Matrix_GetWidth();
    cout << h << endl;
    Matrix d(a);
    cout << d;
    Matrix e;
    e = a;
    cout << e;

    a[0][0] = 10;
    cout << a;
    a[1][1] = 20;
    a[0][0] = 11;
    cout << a;
    return 0;
}
