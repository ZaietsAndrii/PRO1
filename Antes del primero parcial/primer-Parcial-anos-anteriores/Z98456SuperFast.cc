#include <iostream>
using namespace std;

bool is_bicolor(int n){
    int curNum, prevNum;
    bool isNumChanged = false;

    prevNum = n % 10;
    n /= 10;

    while (n > 0)
    {
        curNum = n % 10;
        if (curNum != prevNum){
            if (!isNumChanged) isNumChanged = true;
            else return false;
        }
        prevNum = curNum;
        n /= 10;
    }
    
    if (isNumChanged) return true;
    else return false;
}

int main(){
    int numbers;
    cin >> numbers;

    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < numbers; j++)
        {
            int number;
            num
            
        }
        
    }
    
    
}

