#include <iostream>
using namespace std;

int main(){
    bool stairSequence = true;
    int curNum, prevNum, stairCounter = 1, wide = 1, dif, maxWide;

    cin >> prevNum;
    while (stairSequence && cin >> curNum)
    {        
        if (curNum != prevNum){
            if (stairCounter == 1){
                maxWide = wide;
                dif = curNum - prevNum;
                stairCounter++;
            }
            else{
                if (dif != curNum - prevNum || wide != maxWide) stairSequence = false;
            }
            prevNum = curNum;
            wide = 0;
        }
        wide++;
        if (stairCounter > 1 && wide > maxWide) stairSequence = false;
    }

    if (stairSequence && stairCounter > 1) cout << "si" << endl;
    else cout << "no" << endl;
    
}