#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while (cin >> n)
    {
        bool found = false;
        vector<int> vec(n);
        int allSum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            allSum += vec[i];
        }

        for (int iComp = 0; iComp < n && found == false; iComp++)
        {
            int n = vec[iComp];
            if (allSum - 2*n == 0) found = true;      
        }
        
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }    
}