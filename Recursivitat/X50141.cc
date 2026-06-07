#include <iostream>
using namespace std;



int fatten(int x){
    int lastDigit, newX;

    if (x > 9) {
        lastDigit = x % 10;
        newX = fatten(x / 10);
        if(newX % 10 > lastDigit) newX = newX * 10 + (newX % 10);
        else newX = newX * 10 + lastDigit;
        return newX;
    }
    else return x;

}