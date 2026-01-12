#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers;
    int n;
    int maxN = 0;
    while (cin >> n) {
        numbers.push_back(n);
        if (n > maxN) maxN = n;
    }

    int limit = max(2, maxN);
    vector<char> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= maxN; ++p) {
        if (isPrime[p]) {
            for (int j = p * p; j <= maxN; j += p) isPrime[j] = false;
        }
    }

    for (int x : numbers) {
        cout << x << " is " << ( (x >= 0 && x <= maxN && isPrime[x]) ? "prime" : "not prime") << '\n';
    }

    return 0;
}