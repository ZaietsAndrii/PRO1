#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findDistance(int d, const vector<int> &v){
    int left = 0, right = v.size() - 2;
    while (left <= right)
    {
        int i = (left + right) / 2;
        if (d < abs(v[i] - v[i + 1])) right = i - 1;
        else if (d > abs(v[i] - v[i + 1])) left = i + 1;
        else return i;
    }
    return -1;
    
}