#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<double>& v){
    for (int i = 1; i < v.size(); i++)
    {
        double x = v[i];
        int j = i;
        while (j > 0 && x < v[j - 1])
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = x;
    }
    
    
}