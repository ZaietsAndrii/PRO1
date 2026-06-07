#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matrix;

void min_max(const Matrix& mat, int& minimum, int& maximum){
    int nRows = mat.size(), nColumns = mat[0].size();
    minimum = maximum = mat[0][0];
    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < nColumns; j++){
            minimum = min(minimum, mat[i][j]);
            maximum = max(maximum, mat[i][j]);
        }
    }
}

int main(){
    int nRows, nColumns, counter = 1, maxDiff = 0, numOfMatrixWithMaxDiff = 1;
    while (cin >> nRows >> nColumns)
    {
        int minimum, maximum;
        Matrix matrix(nRows, vector<int>(nColumns));
        for (int i = 0; i < nRows; i++){
            for (int j = 0; j < nColumns; j++){
                cin >> matrix[i][j];
            }
        }

        min_max(matrix, minimum, maximum);
        if (maximum - minimum > maxDiff) {
            numOfMatrixWithMaxDiff = counter;
            maxDiff = maximum - minimum;
        }
        counter++;
    }

    cout << "la diferencia maxima es " << maxDiff << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << numOfMatrixWithMaxDiff << endl;
}

