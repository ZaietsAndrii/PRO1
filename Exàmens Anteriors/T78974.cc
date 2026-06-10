#include <iostream>
using namespace std;

bool dos_iguals_consecutius(int n){
    if(n > 9){
        int rem = n % 10;
        n /= 10;
        if(rem == n % 10) return true;
        else return dos_iguals_consecutius(n);
    }
    return false;
}