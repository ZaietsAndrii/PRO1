#include <iostream>
#include <vector>
using namespace std;

bool bin_search(int x, const vector<int>& V, int left, int right) {
    while (left <= right) {
        int i = (left + right)/2;
        if (x < V[i]) right = i - 1;
        else if (x > V[i]) left = i + 1;
        else return true; //Found
    }
    return false;
}

int common_elements(const vector<int>& X, const vector<int>& Y){
    int lenghtX = X.size();
    int lenghtY = Y.size();
    int counter = 0;

    if (lenghtX < lenghtY){
        for (int i = 0; i < lenghtX; i++){
            if (bin_search(X[i], Y, 0, lenghtY - 1)) counter += 1;
        }
    }
    else{
        for (int i = 0; i < lenghtY; i++){
            if (bin_search(Y[i], X, 0, lenghtX - 1)) counter += 1;
        } 
    }
    return counter;
}