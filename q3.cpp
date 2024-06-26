#include "3.h"
#include<iostream>
using namespace std;


int main()
{
    Matrix m1(2,2);
    Matrix m2(2,2);

	// print result
    cout << "m1 = " << endl;
    m1.print();
    
    
    // print result
    cout << "m2 = " << endl;
    m2.print();
    
    
    // add matrices
    cout<<"m1+m2"<<endl;
    Matrix m3 = m1 + m2;



    // subtract matrices
    Matrix m4 = m1 - m2;



    // multiply matrices
    Matrix m5 = m1 * m2;

    // print result
    cout << "m5 = " << endl;
    m5.print();

    // increment matrix by 1
    m1++;

    // print result
    cout << "m1++ = " << endl;
    m1.print();

    // add matrices and assign result to m1
    cout<<"m1+=m2"<<endl;
    m1 += m2;


    
    // add matrices and assign result to m1
    cout<<"m1-=m2"<<endl;
    m1 -= m2;

	//check if matrix are equal
	cout<<"m1==m2"<<endl;
	if(m1==m2)
	cout<<"matrix are same"<<endl;
	else
	cout<<"matrix are not same"<<endl;
	
	cout<<"m4()"<<endl;
	Matrix m6(3, 3); // create a 3x3 matrix
	m6(0, 0) = 1;
	m6.print();
	
	cout<<"m7()"<<endl;
	const Matrix m7(3, 3); // create a const 3x3 matrix
	int value = m7(0, 0); 
	cout<<value<<endl;
	
	cout << endl;
	cout << "Insertion: \n";
	Matrix m9;
	cin >> m9;	

	cout<<endl;
	cout << "Excertion: \n";
	cout << m9;
	
	cout << endl;

    return 0;
}
