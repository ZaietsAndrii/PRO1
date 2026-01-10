#include <iostream>
using namespace std;

bool is_bicolor(int n){
    int currentNumber = 0, antNumber = 0;
    bool numberChanged = false;
    currentNumber = n % 10;
    antNumber = currentNumber;
    while (n != 0)
    {
        if (currentNumber != antNumber)
        {
            if (numberChanged)
            {
                return false;
            }
            
            numberChanged = true;
        }
        antNumber = currentNumber;
        n /= 10;
        currentNumber = n % 10;
    }

    if (numberChanged) return true;
    else return false;  
}

int main(){
    int n, nDecimals = 0, minNum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        nDecimals = nDecimals * 10 + 9;
        if (minNum == 0) minNum = 1;
        else minNum *= 10;
        
    }
    
    for (int i = minNum; i < nDecimals; i++)
    {
        if (is_bicolor(i)) cout << i << endl;        
    }
    
}