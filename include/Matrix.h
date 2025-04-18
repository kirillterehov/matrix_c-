#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class Matrix {
private:
	int m_height;    // matrix height
	int m_width;     // matrix width
	int** m_matrix;  // declares a variable named matrix that is a pointer to a
	// pointer to an integer. This is commonly used to represent a
	// dynamically allocated two-dimensional array, or a matrix.
	void m_Matrix_Delete();  // declaring a function that cleans up allocated memory
	void m_Matrix_NewMemory(
		int value_Height,
		int value_Width);  // declaring a function that allocates new memory
	void m_Matrix_Replace(
		const Matrix& other);  // declaring an element replacement function
	int* m_Matrix_Index(
		int index) const;  // the function of getting an element by index

public:
	Matrix();                                   // default constructor
	Matrix(int value_Height, int value_Width);  // constructor with two parameters
	friend istream& operator>>(
		istream& input, Matrix& sourse);  //  declaring an input operator overload
	friend ostream& operator<<(
		ostream& output,
		const Matrix& source);  // declaring an output operator overload
	int Matrix_GetHeight()
		const;  // declaring a function for obtaining the height of a matrix
	int Matrix_GetWidth()
		const;  // declaring a function for obtaining the width of a matrix
	int* operator[](int index);  // declaring overloading of the indexing operator
	// is not a constant version
	const int* operator[](
		int index) const;  // declaring overloading of the indexing operator is a
	// constant version
	Matrix(const Matrix& other);              // copy constructor
	Matrix& operator=(const Matrix& object);  // the assignment operator
	~Matrix();                                // the destructor
};
#endif