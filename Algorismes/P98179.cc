#include <iostream>
#include <vector>
using namespace std;

void insert(vector<double>& v){
    for (int i = 1; i < v.size(); i++)
    {
        double x = v[i];
        int j = i;
        while (j > 0 && v[j - 1] > x)
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = x;
    }
    
    
}