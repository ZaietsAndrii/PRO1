#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    while (cin >> n)
    {
        vector<int> numbers(n);
        bool found = false;

        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }

        for (int x = 0; x < n && found == false; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (x != y)
                {
                    if (isPrime(numbers[x] + numbers[y])) found = true;
                }
                
            }
            
        }
        
        cout << (found ? "yes" : "no") << endl;
    }
    
}