#include<iostream>
#include "3.h"
using namespace std;

	//default constructor
	Matrix :: Matrix() 
	{
		rows = 0;
		cols = 0;
		matrix = nullptr;

	}

	Matrix :: Matrix (int row, int col)
	{
		rows=row;
		cols=col;
		int ini=0;
		matrix = new int*[rows];
        		for (int i = 0; i < row; i++) 
			{
			            matrix[i] = new int[cols];
		        }
   		
   			for(int i=0;i<rows;i++)
    			{
			    	for(int j=0;j<cols;j++)
    				{
			    		matrix[i][j]=ini;
			    		ini++;
				}
			}
	}
	
		
	// copy constructor
	Matrix :: Matrix(const Matrix & mat)
	{
		rows = mat.rows;
		cols = mat.cols;
		matrix = new int*[rows];
    		
    			for (int i = 0; i < rows; i++) 
    			{
				matrix[i] = new int[cols];
    			}
    			
			for(int i=0;i<rows;i++)
    			{
				        for(int j=0;j<cols;j++)
        				{
					            matrix[i][j]=mat.matrix[i][j];
        				}
    			}	
	}



	// overloaded () operator for accessing elements
	int& Matrix :: operator()(int i, int j) 
	{
    		return matrix[i][j];
	}

	
	const int& Matrix :: operator()(int i, int j) const 
	{
    		return matrix[i][j];
	}





	bool Matrix :: operator==(const Matrix & mat)
	{
		if(rows!=mat.rows||cols!=mat.cols)
		{
			return false;
		}
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<cols;j++)
				{
					if(matrix[i][j]!=mat.matrix[i][j])
					return false;
				}
			}
		return true;
	
	}


	Matrix Matrix :: operator+(const Matrix & mat)
	{
		// Allocate memory for the rows
		int** temp = new int*[rows];
			// Allocate memory for the columns of each row
			for (int i = 0; i < rows; i++) 
			{
   				temp[i] = new int[cols];
			}
	
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<cols;j++)
				{
					temp[i][j] = matrix[i][j] + mat.matrix[i][j];
				}
			}
		
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<cols;j++)
				{
					cout<<temp[i][j]<<" ";
				}
				cout<<endl;
			}
		
			return mat;
	}


	Matrix Matrix :: operator-(const Matrix & mat)	
	{
			// Allocate memory for the rows
		int** temp = new int*[rows];
		// Allocate memory for the columns of each row
		for (int i = 0; i < rows; i++) 
		{
   			temp[i] = new int[cols];
		}
	
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				temp[i][j] = matrix[i][j] - mat.matrix[i][j];
			}
		}
		
		
		return mat;
	}


	Matrix Matrix :: operator*(const Matrix& other) const 
	{
		Matrix result(rows, other.cols);

    		for (int i = 0; i < rows; ++i) 
    		{
        		for (int j = 0; j < other.cols; ++j) 
        		{
            			result(i, j) = 0;
            			
            			for (int k = 0; k < cols; ++k) 
				{
			                result(i, j) += matrix[i][k] * other.matrix[k][j];
            			}
        		}
    		}

		    return result;
	}




	Matrix& Matrix :: operator++(int m)
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				matrix[i][j]=matrix[i][j]+1;
			}
		}
		return *this;
	}

	
	void Matrix :: operator+=(const Matrix & mat)
	{
		// Allocate memory for the rows
		int** temp = new int*[rows];
	
		// Allocate memory for the columns of each row
		for (int i = 0; i < rows; i++) 
		{
   			temp[i] = new int[cols];
		}
	
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				temp[i][j] = matrix[i][j] + mat.matrix[i][j];
			}
		}
		
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				cout<<temp[i][j]<<" ";
			}
			cout<<endl;
		}	
	}



	void Matrix :: operator-=(const Matrix& mat)
	{
			// Allocate memory for the rows
		int** temp = new int*[rows];
			// Allocate memory for the columns of each row
		for (int i = 0; i < rows; i++) 
		{
	   		temp[i] = new int[cols];
		}
	
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				temp[i][j] = matrix[i][j] - mat.matrix[i][j];
			}
		}
		
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				cout<<temp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	
	void Matrix :: print()
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				cout<<matrix[i][j]<<"  ";
			}
			cout<<endl;
		}
				
	}

	Matrix :: ~Matrix() 
	{
		for (int i = 0; i < rows; i++) 
		{
        		delete[] matrix[i];
    		}
        	
        	delete[] matrix;
    	}

		 // Overload assignment operator (=) as a member function
	Matrix& Matrix :: operator=(const Matrix &mat) 
	{
        	if (this == &mat) 
        	{  
        		// Check for self-assignment
         	   return *this;
        	}

        	// Copy data from mat to *this
        	// ... implementation ...

        	return *this;
    	}	

    	// Overload insertion operator (<<) as a member function
	ostream&  operator<<(ostream &out, const Matrix &mat) 	
    	{
    		cout<<"THE MATRIX is: \n";
    		for(int i = 0 ; i < mat .rows ; i++)
    		{
    			for(int j = 0 ; j < mat .cols ; j++)
    			{	
    				out << mat . matrix[i][j] << " ";	
    			}
    			cout << endl;
    		
    		}
        	

        	return out;
    	}

    	// Overload extraction operator (>>) as a member function
	istream&  operator>>(istream &in, Matrix &mat) 
    	{
    		cout << "\nEnter the rows : ";
        	in >> mat.rows;
		cout << "Enter the columns : ";
		in >> mat.cols;
		
		int ini=0;
		
		mat.matrix = new int*[mat.rows];
		for (int i = 0; i < mat.rows; ++i) 
		{
		      	mat.matrix[i] = new int[mat.cols];
	    	}
   			for(int i=0;i<mat .rows;i++)
    			{
			    	for(int j=0;j<mat .cols;j++)
    				{
			    		mat . matrix[i][j]=ini;
			    		ini++;
				}
			}

        	return in;
    	}
