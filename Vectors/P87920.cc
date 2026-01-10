#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while (cin >> n)
    {
        bool found = false;
        vector<int> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        int VecSize = vec.size();
        for (int iComp = 0; iComp < n && found == false; iComp++)
        {
            int n = vec[iComp];
            for (int i = 0; i < VecSize; i++)
            {
                if(iComp != i){
                    n -= vec[i];
                }
            }
            if (n == 0) found = true;         
        }
        
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }    
}