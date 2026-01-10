#include <iostream>
using namespace std;

int main(){
    string word, pastWord;
    bool found = false, isAscending = false;
    int index = 0, n;

    while (cin >> n && found == false)
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
        if (isAscending) found = true;        
    }

    if (found) cout << "The first line in increasing order is " << index << "." << endl;
    else cout << "There is no line in increasing order."  << endl;  
}