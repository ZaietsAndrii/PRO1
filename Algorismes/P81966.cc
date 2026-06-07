#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right){
    while (left <= right){
        int i = (left + right) / 2;
        if(x < v[i]) right = i - 1;
        else if(x > v[i]) left = i + 1;
        else return i;
    }
    return -1;
    
}

