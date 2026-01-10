#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, lastN, counter;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lastN;
        numbers[i] = lastN;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (numbers[i] == lastN) counter += 1; 
    }

    cout << counter << endl;
    
}