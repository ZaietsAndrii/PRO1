#include <iostream>
using namespace std;

bool is_sandwich(int n){
    if (n < 100) return false;
    int d = 0, e = 0;
    d = n % 10;
    n /= 10;
    e = n % 10;

    while (n != 0)
    {
        int reminder = n % 10;
        n /= 10;
        if (reminder != e)
        {
            if (n == 0 && reminder == d) return true;
            else return false;
        }  
    }
    return false;  
}

int main(){
    int n, decimalsN = 0, minNDecimals = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        decimalsN = decimalsN * 10 + 9;
        if (minNDecimals == 0) minNDecimals = 1;
        else minNDecimals *= 10;
        
    }
    

    for (int i = minNDecimals; i < decimalsN; i++)
    {
        if (is_sandwich(i)) cout << i << endl;
        
    }
    
}