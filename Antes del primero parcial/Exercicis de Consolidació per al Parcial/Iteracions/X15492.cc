#include <iostream>
using namespace std;

int main() {
    int inputNumber, dInputNumber;
    while (cin >> inputNumber)
    {
        int numberToAdd = 0, i = 1;
        dInputNumber = inputNumber;
        while (dInputNumber > 0)
        {
            if (dInputNumber % 2 == 0)
            {
                numberToAdd += i;
            }
            dInputNumber /= 10;
            i *= 10;
        }
        cout << inputNumber + numberToAdd << endl;
    }
    
}