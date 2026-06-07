#include <iostream>
using namespace std;


bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {   // only odd divisors up to sqrt(n)
        if (n % i == 0) return false;
    }
    return true;
}

int functionS(int n){
    int newNum;
    if(is_prime(n)){
        while (n > 0){
            newNum += (n % 10);
            n /= 10;
        }
        if(newNum <= 7 && is_prime(newNum)) return true;
        else return functionS(newNum);
    }
    else return false;
}

bool is_perfect_prime(int n){
    return functionS(n);
}
