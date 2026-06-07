#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    int sizeV;
    while (cin >> sizeV)
    {
        vector<int> v(sizeV);
        for (int i = 0; i < sizeV; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end(), compare);

        for (int i = 0; i < sizeV; i++){
            if(i != 0) cout << " ";
            cout << v[i];
        }
        cout << endl;
    }   
}