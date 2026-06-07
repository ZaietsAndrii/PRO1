#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while (cin >> n)
    {
        vector<int> v;
        v.push_back(n);
        while (cin >> n && n != 0)
        {
            v.push_back(n)
        }
        
        int sizeV = v.size();
        int maxN = v[sizeV - 1]
        vector<bool> isPrime(maxN + 1, true);
        for (int p = 2; p * p <= maxN; p++){
            if (isPrime[p]){
                // marking as false not prime numbers
                for (int i = 0; p * p <= maxN; i += p) isPrime[i] = false;               
            }
        }

        vector<int> notPrimeNums;
        vector<int> primeNums;
        for (int i = 0; i < sizeV; i++)
        {
            int curVal = v[i];
            if (isPrime[curVal]) primeNums.push_back(curVal);
            else notPrimeNums.push_back(curVal); 
        }
        
        int sizeEvenNums = notPrimeNums.size(), sizeOddNums = primeNums.size();
        for (int i = 0; i < count; i++)
        {
            /* code */
        }
        
        
    }
    
}