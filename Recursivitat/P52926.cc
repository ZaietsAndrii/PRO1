#include <iostream>
using namespace std;

void writeWord(){
    string word;
    if (cin >> word) {
        if (word != "end")
        {
            writeWord();
            cout << word << endl;
        }
    }
}

int main(){
    writeWord();
}