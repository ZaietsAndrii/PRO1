#include <iostream>
using namespace std;

int main () {
    int n, peaks=0, number1=0, number2=0, number3=0;
    while (cin >> n)
    {
        peaks = 0;
        if (n <= 111) {
            cout << 0 << endl;
        }
        else{ 
            number2 = n % 10;
            n /= 10;
            number3 = n % 10;
            n /= 10;
                  
            while (n > 0)
            {
                number1 = number2;
                number2 = number3;
                number3 = n % 10;
                if (number2 > number1 && number2 > number3) peaks += 1;
                n /= 10;
            }
            cout << peaks << endl;
        }
        
    }
    
}