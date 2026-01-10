#include <iostream>
using namespace std;

int main() {
    int numbers;

    while (cin >> numbers)
    {
        int digitsN = 0, numbersCounts = numbers;
        
        while (numbersCounts > 0)
        {
            numbersCounts /= 10;
            digitsN += 1;
        }

        int fDigits = 0;
        int sDigits = 0;
        if (digitsN % 2 == 1) fDigits = digitsN / 2 + 1;
        else fDigits = digitsN / 2;
        sDigits = digitsN / 2;

        
        
        
    }
    
}