#include <iostream>
using namespace std;

void writeWord(int& count){
    count += 1;
    string word;
    if (cin >> word) {
        writeWord(count);
        count -= 1;
        if (count < 0) cout << word << endl;
    }
    else {
        count = count / 2;
    }
}

int main(){
    int count = 0;
    writeWord(count);
}