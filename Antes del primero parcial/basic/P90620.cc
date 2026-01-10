#include <iostream>
using namespace std;

int main(){
    int prev1Num, prev2Num, actualNum;
    bool found = false;
    cin >> prev2Num;
    cin >> prev1Num;

    while (cin >> actualNum && !found && actualNum != 0)
    {      
        if (prev1Num > prev2Num && prev1Num > actualNum && prev1Num > 3143)
        {
            found = true;
        }  
        prev2Num = prev1Num;
        prev1Num = actualNum;    
    }

    if (found)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    
}