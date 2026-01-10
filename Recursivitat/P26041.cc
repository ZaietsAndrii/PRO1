#include <iostream>
using namespace std;

void writeWord(){
    string word;
    if (cin >> word) {
        writeWord();
        cout << word << endl;
    }
}

int main(){
    writeWord();
}