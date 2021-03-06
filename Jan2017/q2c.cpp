/*) A symmetric matrix is a square matrix where the for any given
(row,col) location, the value at that location is equal to the value
at location (col,row). The following is an example of a symmetric
matrix:
[
2 3 5
3 1 6
5 6 7
]
Derive a SymMatrix class from the Matrix class defined in
part (b). The new class should include the following methods:
 SymMatrix(int r) : a single parameter constructor
that creates a square matrix i.e. with r rows and r
columns.
 set(int row, int col, int value) : that should
set the values at (row,col) and (col,row) to
value i.e. to enforce the symmetry constraint.
Through the use of example code, explain the need for the
virtual keyword in the declaration of the set method in the
Matrix class.*/

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <valarray>

using namespace std;

class Matrix {
public:

    Matrix(int row, int col) : r(row), c(col), data(new int[r*c]) {
        memset(data, 0, r * c * sizeof (int));
    };

    virtual ~Matrix() {
        delete[] data;
    };
    virtual void set(int row, int col, int value);
            void print();
        protected:
            int r, c; // number of rows and columns
            int *data; // pointer to matrix data
};
//----------------Question-------------------//
class SymMatrix: public Matrix{
	public:
		SymMatrix(int r): Matrix(r, r){}
		void set(int row, int col, int value){
			data[row*c + col] = value;
			data[col*c + row] = value;
		}
};
//---------------------------------------------//

void Matrix::set(int row, int col, int value){
    int index = (c*row)+col;
    data[index] = value;
}

void Matrix::print(){
    for(int i = 0; i<r*c; i++)
    {
        cout << data[i] << " ";
        if((i+1) % c == 0){
            cout << endl;
        }
    }
}

int main(){
    Matrix m(5,3);
    m.set(3,2,5);
    m.print();
	
	cout << endl;
	
	SymMatrix l(3);
    l.set(2,2,1);
    l.set(0,0,3);
	l.set(1, 0, 2);
	l.set(2, 0, 2);
    l.print();
	
	cout << endl;
//----------------Question-------------------//
	/* 
	 * This is why you need a virtual function for Sym Matrix
	 * This is legal code because SymMatrix inherits from Matrix 
	 * The pointer is of type Matrix, therefore it expects to use the functions of Matrix
	 * Using virtual in the Matrix class tells the compiler that this function is expected to be overridden
	 * If set wasn't virtual then it would use set from the Matrix class instead of the SymMatrix class
	*/
	Matrix *k = new SymMatrix(3);
	k->set(0,1,2);
	k->print();
	delete k;
//---------------------------------------------//
}