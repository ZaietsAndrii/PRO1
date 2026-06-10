#include <iostream>
#include <vector>

using namespace std;


void ofuscacio(int n, string s){
    if(s.size() > 0){
        char c = s[s.size() - 1] + n;
        s.pop_back();
        ofuscacio(n, s);
        cout << c;
    }
}