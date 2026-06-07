#include <iostream>
#include <vector>
using namespace std;

bool bin_search(int x, const vector<int>& V, int left, int right){
    while (left <= right){
        int i = (left + right) / 2;
        if(x < V[i]) right = i - 1;
        else if(x > V[i]) left = i + 1;
        else return true;
    }
    return false;
}

int common_elements(const vector<int>& X, const vector<int>& Y){
    int counter = 0;

    for (int i = 0; i < X.size(); i++)
    {
        if(bin_search(X[i], Y, 0, Y.size() - 1)) counter++;
    }
    return counter;
}
