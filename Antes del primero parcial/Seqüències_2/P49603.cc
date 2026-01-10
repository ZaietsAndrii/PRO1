#include <iostream>
using namespace std;

int main(){
    string word, pastWord;
    bool found = false, isAscending = false;
    int index = 0, n, lastLineIndex;

    while (cin >> n)
    {
        isAscending = true;
        index += 1;
        pastWord = "a";

        for (int i = 0; i < n; i++)
        {
            cin >> word;
            if (word < pastWord) isAscending = false;
            pastWord = word;
        }
        if (isAscending) {
            found = true;
            lastLineIndex = index;    
        }    
    }

    if (found) cout << "The last line in increasing order is " << lastLineIndex << "." << endl;
    else cout << "There is no line in increasing order."  << endl;  
}