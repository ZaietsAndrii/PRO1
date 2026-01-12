#include <iostream>
#include <vector>
using namespace std;

int position_maximum(const vector<double>& v, int m){
    double maxValue = v[0];
    int index = 0;
    for (int i = 1; i <= m; i++)
    {
        if (v[i] > maxValue) {
            maxValue = v[i];
            index = i;
        }
    }
    return index;
}