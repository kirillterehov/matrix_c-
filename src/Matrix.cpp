#include "../include/Matrix.h"

void Matrix::m_Matrix_Delete() {  // implementation of the memory cleanup function
                                // in an array
  for (int i = 0; i < m_height; i++) {
    delete[] m_matrix[i];
  }
  delete[] m_matrix;
}

void Matrix::m_Matrix_NewMemory(
    int value_Height,
    int value_Width) {  // the function of allocating memory for the matrix
    m_height = value_Height;
    m_width = value_Width;
    m_matrix = new int*[m_height];  // allocating memory for a row of the matrix
  for (int i = 0; i < m_height; i++) {
      m_matrix[i] =
        new int[m_width];  // allocation of memory for each element of the matrix
  }
}

void Matrix::m_Matrix_Replace(
    const Matrix& other) {  // the function of replacing an element of a matrix
                            // with an element from another matrix, a reference
                            // to which we pass as a parameter
  for (int i = 0; i < m_height; i++) {
    for (int j = 0; j < m_width; j++) {
        m_matrix[i][j] = other.m_matrix[i][j];
    }
  }
}

int* Matrix::m_Matrix_Index(
    int index) const {  // the function of obtaining an element of the matrix
  if (index < 0 || index >= m_height) {
    throw out_of_range("Index out of bounds");
  } else {
    return m_matrix[index];
  }
}

Matrix::Matrix()
    : m_height(0), m_width(0), m_matrix(nullptr) {}  // default constructor

Matrix::Matrix(int value_Height, int value_Width)
    : m_height(0),
    m_width(0),
    m_matrix(nullptr) {  // a constructor in which you can set the size of the
                         // matrix and the memory allocation function is called.
  if (value_Height > 0 && value_Width > 0) {
      m_Matrix_NewMemory(value_Height, value_Width);
  }
}

std::istream& operator>>(
    istream& input,
    Matrix& sourse) {  // overload of the input operator. Accepts a reference to
                       // a class object istream and a reference to a class
                       // object Matrix as parameters.
  for (int i = 0; i < sourse.Matrix_GetHeight(); i++) {
    for (int j = 0; j < sourse.Matrix_GetWidth(); j++) {
      input >> sourse.m_matrix[i][j];
    }
  }
  return input;  // Return type : std::istream&(a reference to the input stream)
}

std::ostream& operator<<(
    ostream& output,
    const Matrix&
        source) {  // overload of the output operator. Accepts a reference to a
                   // class object istream and a reference to a  constant object
                   // of the class Matrix as parameters.
  for (int i = 0; i < source.Matrix_GetHeight(); i++) {
    for (int j = 0; j < source.Matrix_GetWidth(); j++) {
      output << source.m_matrix[i][j] << " ";
    }
    output << endl;
  }
  return output;  // Return type: std::ostream& (a reference to the output
                  // stream)
}

int Matrix::Matrix_GetHeight() const {  // getting the height of the matrix
  return m_height;
}

int Matrix::Matrix_GetWidth() const {  // getting the width of the matrix
  return m_width;
}

int* Matrix::operator[](int index) {
  return m_Matrix_Index(index);
}  // a non-constant version of the indexing operator

const int* Matrix::operator[](int index) const {
  return m_Matrix_Index(index);
}  // a constant version of the indexing operator

Matrix::Matrix(const Matrix& other)
    : m_height(0),
    m_width(0),
    m_matrix(nullptr)  // a copy constructor where a reference to an already
                       // existing object of the matrix class is passed as a
                       // parameter
{
  cout << "Calling copy constructor" << endl;
  m_Matrix_NewMemory(other.m_height,
                   other.m_width);  // calling the new memory allocation function
  m_Matrix_Replace(other);          // calling the element replacement function
}

Matrix& Matrix::operator=(
    const Matrix& object) {  // the assignment operator where a reference to an
                             // already existing object of the matrix class is
                             // passed as a parameter
  cout << "Calling operator =" << endl;
  if (this == &object) {  // checking for self-sealing
    return *this;
  }
  m_Matrix_Delete();  // deleting the memory that was previously allocated for the
                    // object
  m_Matrix_NewMemory(object.m_height,
                   object.m_width);  // calling the new memory allocation function
  m_Matrix_Replace(object);          // calling the element replacement function
  return *this;                    // dereferencing a pointer to an object
}

Matrix::~Matrix() {
    m_Matrix_Delete();
}  // the destructor in which the memory cleanup function is called
