#include <iostream>
#include <vector>
using namespace std;

 typedef vector< vector<int> > Matrix;
 	
void transpose(Matrix& matrix){
    int n;
    n = matrix.size();

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
        
    }
}

