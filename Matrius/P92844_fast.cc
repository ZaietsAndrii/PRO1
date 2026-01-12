#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Rectangle;

// in teory it should be faster, but for some reason I have "time limit exceeded" error. 
void minimal_dimensions(char c, const Rectangle& r, int& rows, int& cols){
    int lengthR = r.size();
    int widthR = r[0].size();
    int topMost = -1, bottomMost = -1, leftMost = -1, rightMost = -1;

    for (int i = 0; i < lengthR; i++){
        for (int j = 0; j < widthR; j++){
            if (r[i][j] == c){
                if (topMost == -1) topMost = i;
                if(bottomMost < i) bottomMost = i;
                if(leftMost > j || leftMost == -1) leftMost = j;
                if(rightMost < j) rightMost = j;
            }  
        }  
    }

    rows = bottomMost - topMost + 1;
    cols = rightMost - leftMost + 1; 
}
