#include <iostream>
#include <vector>
using namespace std;

vector<double> difference(const vector<double>& v1, const vector<double>& v2){
    int sizeV1 = v1.size(), sizeV2 = v2.size();
    vector<double> vDif;
    int i = 0, j = 0;
    while (i < sizeV1)
    {
        double curVal = v1[i];
        // advance i to skip duplicates
        while(i < sizeV1 && v1[i] == curVal) i++;
        // advance j
        while(j < sizeV2 && v2[j] < curVal) j++;

        if (j == sizeV2 || v2[j] != curVal) vDif.push_back(curVal);
    }
    return vDif;
}