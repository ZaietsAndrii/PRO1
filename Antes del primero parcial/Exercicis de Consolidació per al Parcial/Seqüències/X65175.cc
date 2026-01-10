#include <iostream>
using namespace std;

int getReversedNumber(int n){
    int reversedNumber = 0;
    while (n != 0)
    {
        int remainder = n % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        n /= 10;
    }
    return reversedNumber;
}

int main () {
    int n, firstPalindrome = 0;
    bool found = false;
    while (cin >> n && found == false)
    {
        if (n <= 100) {}
        else{
            int reversedNumber = getReversedNumber(n);
            if (n == reversedNumber) {
                found = true;
                firstPalindrome = n;
            }         
        }
    }
    if (found) cout << firstPalindrome << "!" << endl;
    else cout << "Res." << endl;
}