#include <iostream>
#include <numeric>
using namespace std;

int main(){
    int num, den, maxNum = 0, maxDen = 0;
    char frac;
    cin >> maxNum >> frac >> maxDen;
    while (cin >> num >> frac >> den)
    {
        if (num * maxDen > maxNum * den){
            maxNum = num;
            maxDen = den;
        }
    }

    int gcdNum = gcd(maxNum, maxDen);
    maxNum /= gcdNum;
    maxDen /= gcdNum;
    cout << maxNum << '/' << maxDen << endl;
}