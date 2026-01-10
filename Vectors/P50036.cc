#include <iostream>
#include <vector>
using namespace std;


int evaluate(const vector<int>& p, int x){
    int n = p.size();
    if (n == 0) return 0;
    
    // Start with the highest degree coefficient
    int result = p[n-1];
    
    // Apply Horner's scheme: work backwards from highest to lowest degree
    for (int i = n-2; i >= 0; i--) {
        result = result * x + p[i];
    }
    
    return result;
}