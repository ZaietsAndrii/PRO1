#include <iostream>
using namespace std;

char base64_to_char(int d) {
    if (d >= 0 && d <= 25) return 65 + d;          // A-Z
    else if (d >= 26 && d <= 51) return 71 + d;     // a-z
    else if (d >= 52 && d <= 61) return d - 4;      // 0-9
    else if (d == 62) return '+';
    else return '/';
}

int reinterpret_base256_to_base64_char(unsigned long long x, int curNum) {
    if (curNum == 0) return 0;
    int digit = x % 64;
    reinterpret_base256_to_base64_char(x / 64, curNum - 1);
    cout << base64_to_char(digit);
    return 0;
}

int main() {
    int numOfBytes;
    while (cin >> numOfBytes) {
        int i = 0;
        while (i < numOfBytes) {
            unsigned long long x = 0;
            int remaining = numOfBytes - i;

            if (remaining >= 3) {
                int b1, b2, b3;
                cin >> b1 >> b2 >> b3;
                x = (b1 * 256 * 256) + (b2 * 256) + b3;
                reinterpret_base256_to_base64_char(x, 4);
                i += 3;
            } 
            else if (remaining == 2) {
                int b1, b2;
                cin >> b1 >> b2;
                x = (b1 * 256 * 256) + (b2 * 256);
                reinterpret_base256_to_base64_char(x / 64, 3);
                cout << "=";
                i += 2;
            } 
            else if (remaining == 1) {
                int b1;
                cin >> b1;
                x = (b1 * 256 * 256);
                reinterpret_base256_to_base64_char(x / (64 * 64), 2);
                cout << "==";
                i += 1;
            }
        }
        cout << endl;
    }
    return 0;
}