#include <iostream>
using namespace std;

int main() {
    int firstNum, prevNum, curNum;
    cin >> firstNum;
    prevNum = firstNum;
    int count = 0;
    bool descending = false;
    bool possible = true;

    while (possible && cin >> curNum) {
        if (!descending) {
            if (curNum >= prevNum) {
                count++;
            } else {
                descending = true;
                count--;
            }
        } else {
            if (curNum <= prevNum && count > 0) {
                count--;
            } else {
                possible = false;
            }
        }
        prevNum = curNum;
    }
    
    if (possible && firstNum == prevNum && count == 0) {
        cout << "si" << endl;
    } else {
        cout << "no" << endl;
    }
}