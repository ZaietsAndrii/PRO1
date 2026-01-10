#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    for (int d = 0; d < 10; d++)
    {
        for (int e = 0; e < 10; e++)
        {
            if (d > 0 && d != e)
            {
                for (int swp = 0; swp < n/2 - 1 || n/2 == 1; swp++)
                {                
                    for (int i = 0; i < n/2 - swp; i++)
                    {
                        cout << d;
                    }

                    for (int i = 0; i < n/2 + swp; i++)
                    {
                        cout << e;
                    }
                    if (n % 2 != 0) cout << e;                  
                    cout << endl;
                    
                    if (n % 2 != 0) cout << d;                  
                    for (int i = 0; i < n/2 + swp; i++)
                    {
                        cout << d;
                    }

                    for (int i = 0; i < n/2 - swp; i++)
                    {
                        cout << e;
                    }
                    cout << endl;
                }
            }
        }
        
    }
    
}