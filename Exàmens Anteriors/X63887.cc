#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

void insertionSort(vector<int>& v){
    int sizeV = v.size();
    for (int i = 1; i < sizeV; i++)
    {
        int x = v[i];
        int j = i;
        while (j > 0 && v[j - 1] > x) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = x;
    }
    
}

bool doesContainMx(const Matrix& matrix, int r, int c, int posR, int posC){
    vector<int> mxConten;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            mxConten.push_back(matrix[posR + i][posC+ j]);
        }
    }
    insertionSort(mxConten);
    bool containAllNum = true;
    for (int i = 0; i < 9 && containAllNum; i++){
        if (mxConten[i - 1] >= mxConten[i]) containAllNum = false;
    }
    return containAllNum;        
}

int main(){
    int r, c;
    while (cin >> r >> c)
    {
        Matrix matrix(r, vector<int>(c));
        for (int i = 0; i < r; i++){
            string x;
            cin >> x;
            for (int j = 0; j < c; j++){
                matrix[i][j] = x[j] - '0';
                //cout << matrix[i][j] << " ";
            }
            //cout << endl;
        }
        if (r >= 3 && c >= 3)
        {
            int counter = 0;
            for (int i = 0; i < r - 2; i++){
                for (int j = 0; j < c - 2; j++){
                    if (doesContainMx(matrix, r, c, i, j)) counter++;
                }
            }
            cout << counter << endl;            
        }
        else{
            cout << 0 << endl;
        }
        
        
    }
    
}