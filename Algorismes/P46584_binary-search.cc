#include <iostream>
#include <vector>
using namespace std;

vector<double> difference(const vector<double>& v1, const vector<double>& v2){
    int sizeV1 = v1.size(), sizeV2 = v2.size();
    vector<double> vDif;
    double curVal, prevVal;

    for (int i = 0; i < sizeV1; i++)
    {
        curVal = v1[i];
        if (i == 0 || v1[i - 1] != curVal)
        {
            int left = 0, right = sizeV2 - 1;
            bool found = false;
            while (left <= right && !found){
                int j = (left + right) / 2;
                if (curVal < v2[j]) right = j - 1;
                else if (curVal > v2[j]) left = j + 1;
                else found = true;
            }
            if (!found) vDif.push_back(curVal);            
        }
    }
    return vDif;
}
// Doesn't suite for this exercise, don't pass private test cases. But solution works.