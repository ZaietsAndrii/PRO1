#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

void printRow(const Matrix& matrix, int rowLenght){
    int n;
    cin >> n;
    cout << "row " << n << ":";
    for(int i = 0; i < rowLenght; i++){
        cout << " " << matrix[n - 1][i];
    }
    cout << endl;
}

void printColumn(const Matrix& matrix, int columnLenght){
    int n;
    cin >> n;
    cout << "column " << n << ":";
    for (int i = 0; i < columnLenght; i++){
        cout << " " << matrix[i][n - 1];
    }
    cout << endl;
}

void printElement(const Matrix& matrix){
    int n, m;
    cin >> n >> m;
    cout << "element " << n << " " << m << ": " << matrix[n - 1][m - 1] << endl;
}

int main(){
    int n, m;
    string word;
    cin >> n >> m;
    Matrix matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    while (cin >> word)
    {
        if (word == "row") printRow(matrix, m); 
        else if (word == "column") printColumn(matrix, n);
        else if (word == "element") printElement(matrix);
    } 
}