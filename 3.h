#ifndef MATRIX_H_
#define MATRIX_H_

#include<iostream>
using namespace std;
class Matrix
{
	int **matrix; // declare 2D pointer
    	int rows;
    	int cols;

	public:
	
	//default constructor
	Matrix(); 
	Matrix (int row, int col);	
	// copy constructor
	Matrix(const Matrix & mat);
	
	// overloaded () operator for accessing elements
	int& operator()(int i, int j);
	
	const int& operator()(int i, int j) const ;
	bool operator==(const Matrix & mat);
	Matrix operator+(const Matrix & mat);
	Matrix operator-(const Matrix & mat);	
	Matrix operator*(const Matrix& other) const; 
	Matrix& operator++(int m);	
	void operator+=(const Matrix & mat);
	void operator-=(const Matrix& mat);
	// Overload assignment operator (=) as a member function
	Matrix& operator=(const Matrix &mat) ;
    	// Overload insertion operator (<<) as a member function
    	friend ostream& operator<<(ostream &out, const Matrix &mat); 	
    	// Overload extraction operator (>>) as a member function
    	friend istream& operator>>(istream &in, Matrix &mat) ;
	
	
	void print();
	~Matrix(); 


};


#endif /* MATRIX_H_ */
