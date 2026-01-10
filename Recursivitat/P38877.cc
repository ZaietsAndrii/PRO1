#include <iostream>
using namespace std;

void writeWord(int& n){
    string word;
    if (cin >> word) {
        writeWord(n);
        if (n != 0) {
            cout << word << endl;
            n -= 1;
        }
    }
}

int main(){
    int n;
    cin >> n;
    writeWord(n);
}