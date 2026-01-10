#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector< vector<char> > Matrix;
typedef vector< vector<bool> > BooleanMatrix;
typedef vector<int> Direction; 

// Recursively checks if the word exists in a specific direction
bool searchWithEdit(const Matrix& matrix, BooleanMatrix& boolMatrix, const string& word, const Direction& dir, int m, int n, int wordSize, int count) {
    if (count == wordSize) return true;

    // Boundary and character match check
    if (m < 0 || m >= (int)matrix.size() || n < 0 || n >= (int)matrix[0].size() || matrix[m][n] != word[count]) {
        return false;
    }

    // Continue searching in the same direction
    if (searchWithEdit(matrix, boolMatrix, word, dir, m + dir[0], n + dir[1], wordSize, count + 1)) {
        boolMatrix[m][n] = true; // Mark as part of a found word
        return true;
    }
    
    return false;
}

int main() {
    int x, m, n;
    // Read x (words), m (rows), n (columns) [cite: 2]
    while (cin >> x >> m >> n) {
        vector<string> words(x);
        for (int i = 0; i < x; i++) cin >> words[i];

        Matrix matrix(m, vector<char>(n));
        BooleanMatrix boolMatrix(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        // Define the 3 allowed directions: Horizontal, Vertical, Diagonal
        vector<Direction> directions = {
            {0, 1},  // Horizontal (Left to Right)
            {1, 0},  // Vertical (Top to Bottom)
            {1, 1}   // Diagonal (Top-Left to Bottom-Right)
        };

        // Scan the matrix for word starts
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int w = 0; w < x; w++) {
                    // If first letter matches, check all 3 directions
                    if (matrix[i][j] == words[w][0]) {
                        for (const auto& dir : directions) {
                            searchWithEdit(matrix, boolMatrix, words[w], dir, i, j, (int)words[w].size(), 0);
                        }
                    }
                }
            }
        }

        // Print the result matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char out = matrix[i][j];
                // Convert to uppercase if it's part of a word 
                if (boolMatrix[i][j]) {
                    out = (char)(out - 32);
                }
                cout << out << (j == n - 1 ? "" : " ");
            }
            cout << endl;
        }
        cout << endl; // Separate test data by an empty line 
    }
    return 0;
}