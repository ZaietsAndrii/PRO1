#include <iostream>
#include <vector>
using namespace std;

/*
int nrows = a.size();
int ncols = a[0].size();
Matrix c(nrows, vector<int>(ncols));
*/

bool magic_square(const vector< vector<int> >& t){
    int expectedSum = 0, sum = 0, matrixSize = t.size();
    vector<bool> seuqenceOfAllNumbers(matrixSize * matrixSize, false);    

    // verify that matrix contain numbers from 1 to matrixSize * matrixSize
    for (int i = 0; i < matrixSize; i++){ // num of rows 
        for (int j = 0; j < matrixSize; j++){ // num of columns
            if(t[i][j] < 1 || t[i][j] > matrixSize * matrixSize) return false;
            seuqenceOfAllNumbers[t[i][j] - 1] = true;
        }
    }

    for (int i = 0; i < matrixSize * matrixSize; i++){
        if(seuqenceOfAllNumbers[i] == false) return false;
    }
    

    for (int i = 0; i < matrixSize; i++){
        expectedSum += t[0][i];
    }

    // verify rows addition sum
    for (int i = 0; i < matrixSize; i++){ // num of rows 
        sum = 0;
        for (int j = 0; j < matrixSize; j++){ // num of columns
            sum += t[i][j];
        }
        if(expectedSum != sum) return false;
    }

    // verify columns addition sum
    for (int i = 0; i < matrixSize; i++){ // num of rows 
        sum = 0;
        for (int j = 0; j < matrixSize; j++){ // num of columns
            sum += t[j][i];
        }
        if(expectedSum != sum) return false;
    }

    // verify main diagonals addiction sum
    sum = 0;
    for (int i = 0; i < matrixSize; i++)
    {
        sum += t[i][i];
    }
    if(expectedSum != sum) return false;

    sum = 0;
    for (int i = 0; i < matrixSize; i++)
    {
        sum += t[i][matrixSize - i - 1];
    }
    if(expectedSum != sum) return false;

    return true;
}