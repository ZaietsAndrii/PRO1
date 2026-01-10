#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;

    while (cin >> n)
    {
        vector<int> numbers(n);
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << numbers[n - i - 1];
            if (n - 1 != i) cout << " ";
        }
        cout << endl;
    }
    
}