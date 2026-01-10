#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<vector<char>> Matrix;

// Helper to convert lowercase to uppercase
void editMatrix(Matrix& matrix, int wordSize, int posM, int posN, int dirM, int dirN) {
    for (int i = 0; i < wordSize; i++) {
        // Only convert if it's currently lowercase to avoid double-processing
        if (matrix[posM][posN] >= 'a' && matrix[posM][posN] <= 'z') {
            matrix[posM][posN] -= 32;
        }
        posM -= dirM;
        posN -= dirN;
    }
}

// Function to scan a single line (horizontal, vertical, or diagonal)
void findWord(Matrix& matrix, const string& word, int m, int n, int startM, int startN, int dirM, int dirN) {
    int i = startM;
    int j = startN;
    int count = 0;
    int wordSize = word.size();

    while (i < m && j < n && i >= 0 && j >= 0) {
        // Compare using lowercase logic (in case the matrix char is already uppercase)
        char currentChar = (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z') ? matrix[i][j] + 32 : matrix[i][j];
        
        if (word[count] == currentChar) {
            count++;
            if (count == wordSize) {
                editMatrix(matrix, wordSize, i, j, dirM, dirN);
                // After finding a word, we reset count but MUST move back 
                // to check for overlapping occurrences of the same word
                i -= dirM * (count - 1);
                j -= dirN * (count - 1);
                count = 0;
            }
        } else {
            // If match fails, move back to just after where the current potential match started
            i -= dirM * count;
            j -= dirN * count;
            count = 0;
        }
        i += dirM;
        j += dirN;
    }
}

int main() {
    int x, m, n;
    bool first = true;
    while (cin >> x >> m >> n) {
        // Printing empty line between test cases (but not after the last one)
        if (!first) cout << endl;
        first = false;

        vector<string> words(x);
        for (int i = 0; i < x; i++) cin >> words[i];

        Matrix matrix(m, vector<char>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        for (int i = 0; i < x; i++) {
            // 1. Check all Rows (Horizontal and Diagonal starting from Left Edge)
            for (int r = 0; r < m; r++) {
                findWord(matrix, words[i], m, n, r, 0, 0, 1); // Horizontal
                findWord(matrix, words[i], m, n, r, 0, 1, 1); // Diagonal Down-Right
            }
            // 2. Check all Columns (Vertical and Diagonal starting from Top Edge)
            for (int c = 0; c < n; c++) {
                findWord(matrix, words[i], m, n, 0, c, 1, 0); // Vertical
                if (c > 0) findWord(matrix, words[i], m, n, 0, c, 1, 1); // Diagonal Down-Right
            }
        }

        // Output results 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << (j == n - 1 ? "" : " ");
            }
            cout << endl;
        }
    }
}