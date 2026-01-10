#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    for (int wIndex = 0; wIndex < n; wIndex++)
    {
        int wordSize = words[n-wIndex-1].size();
        for (int s = 0; s < wordSize; s++)
        {
            cout << words[n-wIndex-1][wordSize-s-1];
        }
        cout << endl;        
    }
    
    
}