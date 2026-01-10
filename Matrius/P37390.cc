#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

Matrix product(const Matrix& a, const Matrix& b){
    int nrowsA, ncolumnsA, nrowsB, ncolumnsB;
    nrowsA = a.size();
    ncolumnsA = a[0].size();
    nrowsB = b.size();
    ncolumnsB = b[0].size();
    Matrix matrix(nrowsA, vector<int>(ncolumnsB));
    for (int i = 0; i < nrowsA; i++){
        for (int j = 0; j < ncolumnsB; j++){
            for (int c = 0; c < ncolumnsA; c++){
                matrix[i][j] += a[i][c] * b[c][j];
            }  
        }        
    }
    return matrix;    
}