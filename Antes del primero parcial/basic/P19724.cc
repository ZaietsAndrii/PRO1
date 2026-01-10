#include <iostream>
using namespace std;

int main(){
    int h, m, t, output, multiplicator, mRemainder = 0;
    while (cin >> h >> m >> t)
    {
        output = 0;
        mRemainder = m % 15;
        if (mRemainder != 0)
        {
            m += 15 - mRemainder;
            t -= 15 - mRemainder;
        }
        
        if (t >= 1440)
        {
            multiplicator = t / 1440;
            output += 484 * multiplicator;
            t -= 1440 * multiplicator;
        }
        while (t > 0)
        {      
            if (m >= 60)
            {
                m = 0;
                h += 1;
                if (h == 24)
                {
                    h = 0;
                }
            }
             
            if (m == 0)
            {
                if (h == 0)
                {
                    output += 12;
                }               
                else if (h / 12.0 < 1)
                {
                    output += h;
                }
                else if (h / 12.0 > 1)
                {
                    output += h - 12;
                }
                else if (h / 12.0 == 1)
                {
                    output += 100;
                }
                
                output += 4;
            }
            else{
                output += m / 15;      
            }

            m += 15;
            t -= 15;            
        }
        cout << output << endl;
    }
    
}