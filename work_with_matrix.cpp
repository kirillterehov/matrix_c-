#include <iostream>

using namespace std;

class Matrix {
private:
     int height=0;
     int width=0;
    int** matrix;
public:
    Matrix() {
        height = 0;
        width = 0;
        matrix = nullptr;
    }
    Matrix( int value_Height,  int value_Width) { // конструктор, в котором можно задать размер матрицы
        if (value_Height > 0 && value_Width > 0) {
            height = value_Height;
            width = value_Width;
            matrix = new int* [height];
                for (int i = 0; i < height; i++) {
                    matrix[i] = new int[width];
            }

        }
        
    }

    void Input() { // ввод матрицы
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    cin >> matrix[i][j];
                }
            }
        }
    
    
    void Output() { // вывод матрицы

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
    }

     int GetHeight() { // получение длины матрицы
            return height;
    }

    int GetWidth() { // получение ширины матрицы
            return width;
     }

    int Access_by_index_read(int i, int j) { // доступ по операции индексирования (чтение элемента)
        if (i>=0 && j>=0 && i < height && j < width) {
            return matrix[i][j];
        }
        else {
            return -1;
        }
    }

    int Access_by_index_write(int i, int j, int new_value) { // доступ по операции индексирования (замена элемента)
        if (i >= 0 && j >= 0 && i < height && j < width) {
            matrix[i][j] = new_value;
            return matrix[i][j];
        }
        else {
            return -1;
        }
    }

    Matrix(const Matrix& other) //конструктор копирования
    {
        cout << "Calling copy constructor" << endl;
        height = other.height;
        width = other.width;
        matrix =  new int * [height];
        for (int i = 0; i < height; i++) {
            matrix[i] =  new int[width];

        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                matrix[i][j]= other.matrix[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& object) {//операор присваивания
        cout << "Calling operator =" << endl;
        if (this == &object) {
            return *this;
        }
            for (int i = 0; i < height; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;

            height = object.height;
            width = object.width;
            matrix = new int* [height];
            for (int i = 0; i < height; i++) {
                matrix[i] = new int[width];

            }
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    matrix[i][j] = object.matrix[i][j];
                }
            }
            return *this; //разыменование указателя
    }


    ~Matrix() {
        for (int i = 0; i < height; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};


int main()
{
    Matrix a(3, 3);
    a.Input();
    a.Output();
    unsigned w = a.GetHeight();
    cout << w << endl;
    unsigned h = a.GetWidth();
    cout << h << endl;
    int b = a.Access_by_index_read(0, 0);
    cout << b << endl;
    Matrix d(a);
    d.Output();
    int c = a.Access_by_index_write(2, 2, 10);
    Matrix e;
    e = a;
    e.Output();
    return 0;
}
