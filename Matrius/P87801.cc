#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector < vector<char> > CharMatrix;
typedef vector< vector<int> > NumMatrix;

int searchWordAndCalculateMaxScore(const CharMatrix& charMx, const NumMatrix& numMx, string& word, int posR, int posC, int dirR, int dirC){
    int wordSize = word.size();
    int maxR = numMx.size(), maxC = numMx[0].size();
    int count = 0;
    int maxScore = -1, currentScore = 0;

    while (posR >= 0 && posC >= 0 && posR < maxR && posC < maxC)
    {
        //cout << "count: " << count << "  " << "posR: " << posR << " " << "posC: " << posC << endl;
        char currentChar = charMx[posR][posC];
        if (word[count] == currentChar)
        {
            currentScore += numMx[posR][posC];
            count += 1;
            if (wordSize == count){
                maxScore = max(maxScore, currentScore);
                currentScore = 0;
                posR += (count - 1) * (-dirR);
                posC += (count - 1) * (-dirC);
                count = 0;
            }
        }
        else {
            currentScore = 0;
            posR += count * (-dirR);
            posC += count * (-dirC);
            count = 0;            
        }
        posR += dirR;
        posC += dirC;
    }
    return maxScore;
}

int main(){
    int r, c;
    while (cin >> r >> c)
    {
        NumMatrix numMatrix(r, vector<int>(c));
        CharMatrix charMatrix(r, vector<char>(c));
        
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cin >> charMatrix[i][j];
            }     
        }
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cin >> numMatrix[i][j];
            }     
        }
        int numWords;
        cin >> numWords;
        vector<string> words(numWords);
        for (int i = 0; i < numWords; i++){
            cin >> words[i];
        }
        
        for (int n = 0; n < numWords; n++) // directions: 0,1; 1,0; 1,1;
        {
            int maxScore = -1;
            for (int i = 0; i < r; i++)
            {
                maxScore = max(maxScore, searchWordAndCalculateMaxScore(charMatrix, numMatrix, words[n], i, 0, 0, 1)); // Horizontal
                //maxScore = max(maxScore, searchWordAndCalculateMaxScore(charMatrix, numMatrix, words[n], i, 0, 1, 1)); // Diagonal down-right
            }

            for (int j = 0; j < c; j++)
            {
                maxScore = max(maxScore, searchWordAndCalculateMaxScore(charMatrix, numMatrix, words[n], 0, j, 1, 0)); // Vartical
                //maxScore = max(maxScore, searchWordAndCalculateMaxScore(charMatrix, numMatrix, words[n], 0, j, 1, 1)); // Diagonal down-right         
            }
            if (maxScore < 0) cout << "no" << endl;
            else cout << maxScore << endl;
        }
        
    }
    
}