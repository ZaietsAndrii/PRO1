#include <iostream>
#include <vector>
using namespace std;

 int pot_conflictive(const vector <bool>& B){
    int lenght = B.size() - 2;
    int confNumber = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (B[i]){
            if (B[i + 1] ) confNumber += 1;
            if (B[i + 2]) confNumber += 1;   
        }
    }
    return confNumber;    
 }

 vector<bool> ramps_pos(const vector <int>& V){
    int v0, v1, v2;
    int lenght = V.size() - 2;
    vector<bool> B(lenght + 2);
    for (int i = 0; i < lenght; i++)
    {
        v0 = V[i];
        v1 = V[i + 1];
        v2 = V[i + 2];
        if ((v0 < v1 && v1 < v2) || (v0 > v1 && v1 > v2)) B[i] = true;
    }
    return B;  
 }


int main() {
    int n, confNumber = 0;
    while (cin >> n)
    {
        vector<int> V(n);
        vector<bool> B(n);
        for (int i = 0; i < n; i++)
        {
            cin >> V[i];
        }
        B = ramps_pos(V);
        confNumber = pot_conflictive(B);

        cout << "positions with a ramp:";
        for (int i = 0; i < n; i++)
        {
            if (B[i]) cout << " " << i;  
        }
        cout << endl;
        cout << "potentially conflictive: " << confNumber << endl;
        cout << "---" << endl;
    }
    
}