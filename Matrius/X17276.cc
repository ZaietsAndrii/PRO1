#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

bool isElementsInIncreaingOrder(const Matrix& matrix, int posR, int posC, int dirR, int dirC){
    bool ordered = true;
    int maxR = matrix.size() - 1, maxC = matrix[0].size() - 1;
    int curValue = matrix[posR][posC], nextValue;
    posR += dirR;
    posC += dirC;
    while (ordered && (posR >= 0 && posC >= 0 && posR <= maxR && posC <= maxC))
    {
        nextValue = matrix[posR][posC];
        if (curValue < nextValue) curValue = nextValue;
        else ordered = false;
        posR += dirR;
        posC += dirC;
    }
    return ordered;
}

int main(){
    int r, c;

    while (cin >> r >> c)
    {
        Matrix matrix(r, vector<int>(c));
        int initPosR, initPosC;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
            
        }
        cin >> initPosR >> initPosC;
        bool ordered = 
        isElementsInIncreaingOrder(matrix, initPosR, initPosC, 1, 1) && // Horizontal down-right
        isElementsInIncreaingOrder(matrix, initPosR, initPosC, -1, 1) && // Horizontal down-left
        isElementsInIncreaingOrder(matrix, initPosR, initPosC, 1, -1) && // Horizontal up-right
        isElementsInIncreaingOrder(matrix, initPosR, initPosC, -1, -1);  // Horizontal up-left

        if(ordered) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    
}