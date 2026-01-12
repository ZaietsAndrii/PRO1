#include <iostream>
#include <vector>
using namespace std;

void insert(vector<double>& v){
    int sizeV = v.size();
    for (int i = 1; i < sizeV; i++){
        double x = v[i];
        int j = i;
        while (j > 0 && v[j - 1] > x){
            v[j] = v[j - 1];
            j -= 1;
        }
        v[j] = x;
        
    }
    
}