#include <iostream>
#include <vector>

using namespace std;

int colzeMuntanya(const vector<int>& v){
    int left = 1, right = v.size() - 2;
    while (left <= right)
    {
        int i = (left + right) / 2;
        if(v[i] > v[i - 1] && v[i] < v[i + 1]) left = i + 1;
        else if (v[i] <= v[i - 1] && v[i] >= v[i + 1]) right = i - 1;
        else return i;
    }
    return -1;
}