#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Rectangle;

void minimal_dimensions(char c, const Rectangle& r, int& rows, int& cols){
    int lengthR = r.size();
    int widthR = r[0].size();
    bool found = false;
    int topMost = 0, bottomMost = 0, leftMost = 0, rightMost = 0;
    // search top-most border
    for (int i = 0; i < lengthR && !found ; i++){
        for (int j = 0; j < widthR && !found; j++){
            if (r[i][j] == c){
                topMost = i;
                found = true;
            }  
        }  
    }
    found = false;
    //search bottom-most border
    for (int i = lengthR - 1; i > -1 && !found ; i--){
        for (int j = widthR - 1; j > -1 && !found; j--){
            if (r[i][j] == c){
                bottomMost = i;
                found = true;
            }  
        }  
    }
    found = false;
    //search left-most border
    for (int i = 0; i < widthR && !found ; i++){
        for (int j = 0; j < lengthR && !found; j++){
            if (r[j][i] == c){
                leftMost = i;
                found = true;
            }  
        }  
    }
    found = false;
    //search right-most border
    for (int i = widthR - 1; i > -1 && !found ; i--){
        for (int j = lengthR - 1; j > -1 && !found; j--){
            if (r[j][i] == c){
                rightMost = i;
                found = true;
            }  
        }  
    }

    rows = bottomMost - topMost + 1;
    cols = rightMost - leftMost + 1; 
}
