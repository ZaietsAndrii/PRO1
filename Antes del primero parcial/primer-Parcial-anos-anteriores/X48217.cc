#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    for (int d = 1; d < 10; d++)
    {
        for (int e = 0; e < 10; e++)
        {
            if (d != e){        
                cout << d;
                for (int i = 0; i < n - 2; i++)
                {
                    cout << e;
                }
                cout << d << endl;
            }
        }
        
    }
    
    
}