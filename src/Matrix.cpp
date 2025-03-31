#include "../include/Matrix.h"

void Matrix::Matrix_Delete() { // implementation of the memory cleanup function in an array
  for (int i = 0; i < height; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void Matrix::Matrix_NewMemory(int value_Height, int value_Width) { // the function of allocating memory for the matrix
  height = value_Height;
  width = value_Width;
  matrix = new int*[height]; // allocating memory for a row of the matrix
  for (int i = 0; i < height; i++) {
    matrix[i] = new int[width]; // allocation of memory for each element of the matrix
  }
}

void Matrix::Matrix_Replace(const Matrix& other) { // the function of replacing an element of a matrix with an element from another matrix, a reference to which we pass as a parameter
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
}

int* Matrix::Matrix_Index(int index) const { // the function of obtaining an element of the matrix
  if (index < 0 || index >= height) {
    throw out_of_range("Index out of bounds");
  } else {
    return matrix[index];
  }
}

Matrix::Matrix() : height(0), width(0), matrix(nullptr) {} // default constructor

Matrix::Matrix(int value_Height, int value_Width)
    : height(0),
      width(0),
      matrix(nullptr) {  // a constructor in which you can set the size of the matrix and the memory allocation function is called.
  if (value_Height > 0 && value_Width > 0) {
    Matrix_NewMemory(value_Height, value_Width);
  }
}

std::istream& operator>>(istream& input, Matrix& sourse) { // overload of the input operator. Accepts a reference to a class object istream and a reference to a class object Matrix as parameters.
  for (int i = 0; i < sourse.Matrix_GetHeight(); i++) {
    for (int j = 0; j < sourse.Matrix_GetWidth(); j++) {
      input >> sourse.matrix[i][j];
    }
  }
  return input; //Return type : std::istream&(a reference to the input stream)
}

std::ostream& operator<<(ostream& output, const Matrix& source) { // overload of the output operator. Accepts a reference to a class object istream and a reference to a  constant object of the class Matrix as parameters.
  for (int i = 0; i < source.Matrix_GetHeight(); i++) {
    for (int j = 0; j < source.Matrix_GetWidth(); j++) {
      output << source.matrix[i][j] << " ";
    }
    output << endl;
  }
  return output; // Return type: std::ostream& (a reference to the output stream)
}

int Matrix::Matrix_GetHeight() const {  // getting the height of the matrix
  return height;
}

int Matrix::Matrix_GetWidth() const {  // getting the width of the matrix
  return width;
}

int* Matrix::operator[](int index) { return Matrix_Index(index); } // a non-constant version of the indexing operator

const int* Matrix::operator[](int index) const { return Matrix_Index(index); } // a constant version of the indexing operator

Matrix::Matrix(const Matrix& other)
    : height(0),
      width(0),
      matrix(nullptr)  // a copy constructor where a reference to an already existing object of the matrix class is passed as a parameter
{
  cout << "Calling copy constructor" << endl;
  Matrix_NewMemory(other.height, other.width); // calling the new memory allocation function
  Matrix_Replace(other); // calling the element replacement function
}

Matrix& Matrix::operator=(const Matrix& object) {  // the assignment operator where a reference to an already existing object of the matrix class is passed as a parameter
  cout << "Calling operator =" << endl;
  if (this == &object) { // checking for self-sealing
    return *this;
  }
  Matrix_Delete(); // deleting the memory that was previously allocated for the object
  Matrix_NewMemory(object.height, object.width); // calling the new memory allocation function
  Matrix_Replace(object); // calling the element replacement function
  return *this;  // dereferencing a pointer to an object
}

Matrix::~Matrix() { Matrix_Delete(); } // the destructor in which the memory cleanup function is called
